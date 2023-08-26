#include <stdio.h>

int fact(int n)
{
    int result = 1;
    if(n==0) return result;

    for(;n>0;n--)
    {
        result = result * n;
    }
    return result;
}

int ncr(int n, int r)
{
    int t1,t2,t3;

    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n-r);

    return t1/(t2*t3);
}

int main()
{

    printf("%d /n",ncr(5,2));
}