#include <stdio.h>
#include <stdlib.h>
#include "vectorLib.h"


int main(int argc, char *argv[])
{
    
    //creates vectors
    int size;
    float result = 0;
    float result_distance = 0;
    float result_norm = 0;
    size = 1000;
    struct Vector *x = vector_create("X",size);
    struct Vector *y = vector_create("Y",size);

    //assigns them functions (cosine and sine)
    vector_create_cos(x,0,200);
    vector_create_cos(y,0,100);

    vector_print_samples(x,100);
    vector_print_samples(y,100);
    //computes inner product

    vector_inner_product(x,x,&result);
    printf("Calculated Inner Product: %f\n",result);

    //computes distance
    vector_distance(y,x,&result_distance);
    printf("Calculated Distance: %f\n",result_distance);

    //computes norm
    vector_norm(x,&result_norm);
    printf("Calculated Norm: %f\n",result_norm);


    //call free and destroy of the pointers
    vector_destroy(x);
    vector_destroy(y);
}

