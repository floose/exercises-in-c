#include "Diagonal.h"

Diagonal::Diagonal(int n,TypeofMatrix flag)
{
    this->N = n;
    int numElements = n;

    if(flag != Diagonal)
        numElements = n*(n+1)/2;

    A = new float[numElements];
}

Diagonal::~Diagonal()
{
    delete[] A;
}
