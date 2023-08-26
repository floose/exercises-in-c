#include <stdio.h>

/*
Horner's Rule decreases the number of 
computations from O(n²) by O(n)
*/

float e(int x, int n)
{
    static float s = 1.00;

    if(n==0) return s;

    s = 1 + x*s/n;

    return e(x,n-1);
}

int main()
{
    printf("%f \n",e(1,10));
    return 0;
}