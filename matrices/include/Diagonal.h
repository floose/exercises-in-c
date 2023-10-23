#ifndef DIAGONAL_H
#define DIAGONAL_H

enum TypeofMatrix
{
    Diagonal,
    Lower,
    Upper
};

class Diagonal
{

private:
    float *A; //array
    int N; //number of diagonal elements
    TypeofMatrix Type;

public:
    Diagonal(int n,TypeofMatrix flag);
    ~Diagonal();
    void Create();
    void Create(float *arr);
    //int Get(int i, int j);
    //void Set(int i, int j, int x);
    //void Display();


};

#endif // DIAGONAL_H
