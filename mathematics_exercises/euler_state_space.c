#include <stdio.h>

/*
This program applies the Euler method to solve a 2nd order state-space equation.
The system is a series RLC circuit submitted to a step function.
The output is a text file containing the waveforms of the state of the system
*/

//struct to save the states of the euler's method iteration
struct States
{
    double il;
    double vc;
};

//functions that returns the states of the RLC circuit
struct States States_RLC(double C, double L, double R, double t_step, double vin, double i_l, double v_c);

int main()
{

    //Struct to store the state variables
    struct States x;
    
    // input parameters
    double t_step; //time step for euler's method (in seconds)
    t_step = 0.1e-6;
    double t_final;
    //final time of simulation
    t_final = 100e-6;
    //time variable
    double time;
    time = 0;

    //file to save data
    FILE *file_out;
    file_out = fopen("output.txt","w");

    //circuit parameters
    double C; 
    C = 1e-6;
    double L;
    L = 5e-6;
    double R;
    R = 5;

    //initial conditions of states
    double i_l = 0;
    double v_c = 0; 
    //amplitude of the step response
    double vin = 20;

    //loop for processing
    while (time < t_final)
    {
        //struct x receives the updated states
        x =  States_RLC(C, L, R, t_step, vin, i_l, v_c);
        //updates time stamp
        time = time + t_step;
        //updates the states
        i_l = x.il;
        v_c = x.vc;

        //saves updates states into the file
        fprintf(file_out, "%.12lf %.12lf %.12lf %.12lf \n", time, vin, i_l, v_c);
    }

    //closes file
    fclose(file_out);
}

//function that returns the states given by the euler's method
//C, L and R are parameters
// t_step is the time step (or the h factor in the Euler Method)
// vin is input function, i_l and v_c are the initial conditions of the states
struct States States_RLC(double C, double L, double R, double t_step, double vin, double i_l, double v_c)
{
    struct States RLC_states;

    //local variables to store the updated state
    double il_t;
    double vc_t;

    //state equations according to RLC series circuit
    il_t = i_l + (t_step/L)*( - v_c - R * i_l + vin);
    vc_t = v_c + (t_step/C)*( i_l);

    //assigns locals to struct
    RLC_states.il = il_t;
    RLC_states.vc = vc_t;

    //returns updated states
    return RLC_states;
}

