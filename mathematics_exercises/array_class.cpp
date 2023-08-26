#include <iostream>
using namespace std;

template <class T>
class Array
{
private:
    T *A;
    int Size;
    int Length;

public:
    Array()
    {
        Size = 10;
        A = new T[10];
        Length = 0;
    }
    Array(int size)
    {
        Size = size;
        Length = 0;
        A = new T[size];
    }
    ~Array()
    {
        delete[] A;
    }
    void Display();
    void Insert(int index, T value);
    T Delete(int index);
};

template <class T>
void Array<T>::Display()
{

    for (int i = 0; i < Length; i++)
        {cout << A[i] << " ";
            cout << endl;
        }
}

template <class T>
void Array<T>::Insert(int index, T value)
{
    // guards for size
    if (index >= 0 && index <= Length)
    {
        // shifts everyone to create space
        for (int i = Length - 1; i >= index; i--)
            A[i + 1] = A[i];
        A[index] = value;
        Length++;
    }
}

template <class T>
T Array<T>::Delete(int index)
{
    T aux = 0;

    // guards for size
    if (index >= 0 && index < Length)
    {
        aux = A[index];
        // shifts everyone to shrink array
        for (int i = index; i < Length - 1; i++)
            A[i] = A[i + 1];
        Length--; // decreases length
    }
    return aux;
}

int main()
{
    Array<char> arr(10);
    arr.Insert(0, 'a');
    arr.Insert(1, 'c');
    arr.Insert(2, 'd');
    arr.Display();
    cout << arr.Delete(0) << endl;
    arr.Display();
    return 0;
}