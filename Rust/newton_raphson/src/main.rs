fn main() {
    // Initial guess for the root7
    let mut x: f64 = -3.9;
    let mut flag: bool = true;
    let mut count: i32 = 0;
    let mut delta_x: f64 = 1.0;
    let max_iterations = 100;
    // Error tolerance
    let epsilon = 1e-10;


    // Newton-Raphson iteration
    while(flag)
    {
        //functions
        let fx = x.powi(2) + x.sinh() + 10.0;
        let dfx = 2.0 * x + x.cosh();

        delta_x = -fx/dfx;
        x += delta_x; 
        count += 1;

        if delta_x.abs() < epsilon 
        {
            flag = false;
        }
        else if count > max_iterations
        {
            println!("Newton Raphson did not converge");
            flag = false;
        }
    }


    println!("Approximate root: {}", x);
    println!("epsilon is: {}",epsilon);
    println!("No. of interaction is: {}",count);
}
