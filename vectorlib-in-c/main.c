#include <stdio.h>
#include <stdlib.h>
#include "vectorLib.h"


int main(int argc, char *argv[])
{
    
    //creates vectors
    int size;
    size = 2000;
    struct Vector *x = vector_create("X",size);
    struct Vector *y = vector_create("Y",size);

    //assigns them functions (cosine and sine)
    vector_create_cos(x,0,50);
    vector_create_sin(y,0,50);

    //computes inner product
    float *inner_p;
    inner_p = malloc(sizeof(float));
    vector_inner_product(y,y,inner_p);
    printf("Calculated Inner Product: %f\n",*inner_p);

    //call free and destroy of the pointers
    vector_destroy(x);
    vector_destroy(y);
    free(inner_p);
}
