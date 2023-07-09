#include <stdio.h>
#include <stdlib.h>
#include "vectorLib.h"


int main(int argc, char *argv[])
{
    
    //creates vectors
    int size;
    float result = 0;
    float result_distance = 0;
    size = 10000;
    struct Vector *x = vector_create("X",size);
    struct Vector *y = vector_create("Y",size);

    //assigns them functions (cosine and sine)
    vector_create_cos(x,0,2000);
    vector_create_cos(y,0,1000);

    //computes inner product

    vector_inner_product(y,x,&result);
    printf("Calculated Inner Product: %f\n",result);

    //computes norm
    vector_distance(y,x,&result_distance);
    printf("Calculated Distance: %f\n",result_distance);

    //call free and destroy of the pointers
    vector_destroy(x);
    vector_destroy(y);
}

