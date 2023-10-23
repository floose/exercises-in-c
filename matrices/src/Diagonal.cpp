#include "Diagonal.h"
#include "Matrix.h"

Diagonal::Diagonal(int n,TypeofMatrix type)
{
    this->N = n;
    this->Type = type;
    int numElements = n;

    if(type != Diagonal)
        numElements = n*(n+1)/2;

    A = new float[numElements];
}

Diagonal::~Diagonal()
{
    delete[] A;
}


//without arguments, creates the matrices with 1s
Diagonal::Create()
{
    if(Type == Diagonal)
    {

    }
}
