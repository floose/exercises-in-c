#ifndef ARRAYINT_H
#define ARRAYINT_H


class ArrayInt
{
private:
    int *A;
    int Size;
    int Len;
    void _swap(int *x, int *y);

public:
    ArrayInt()
    {
        Size = 10;
        Len = 0;
        A = new int[Size];
    }
    ArrayInt(int size)
    {
        Size = size;
        Len = 0;
        A = new int[size];
    }
    ArrayInt(int size, int len, int *input)
    {
        Size = size;
        Len = len;
        A = new int[size];

        //sends data to class array
        for(int i = 0 ; i < len ; i++)
        {
            A[i] = input[i];
        }
    }


    ~ArrayInt()
    {
        delete[] A;
    }


    void Display();
    void Append(int value);
    void Insert(int index, int value);
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int Get(int index);
    int GetLen();
    int GetSize();
    void Set(int index, int value);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    bool IsSorted();
    void Rearrange();
    static ArrayInt Merge(const ArrayInt &arr1, const ArrayInt &arr2);
    static ArrayInt Union(const ArrayInt &arr1, const ArrayInt &arr2);
    static ArrayInt Inter(const ArrayInt &arr1, const ArrayInt &arr2);
    static ArrayInt Diff(const ArrayInt &arr1, const ArrayInt &arr2);
    void InsertSorted(int value);

};

#endif // ARRAYINT_H

