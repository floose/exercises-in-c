#include "ArrayInt.h"
#include <iostream>

using namespace std;

void ArrayInt::Display()
{
    for (int i = 0; i < Len; i++)
    {
        cout << A[i] << " ";
    }
}

void ArrayInt::Append(int value)
{
    if (Len < Size)
    {
        A[Len] = value;
        Len++;
    }
}

void ArrayInt::Insert(int index, int value)
{
    // guard
    if (index >= 0 && index <= Len)
    {
        // left shift everyone (shinks)
        for (int i = Len; i < index; i--)
            A[i] = A[i - 1];
        A[index] = value;
        Len++;
    }
}

int ArrayInt::Delete(int index)
{
    int x = 0;
    int i;

    // guards
    if (index >= 0 && index < Len)
    {
        x = A[index];
        // right shift everyone (increases)
        for (i = index; i < Len - 1; i++)
            A[i] = A[i + 1];
        Len--;
        return x; // returns deleted value
    }
    return 0;
}

void ArrayInt::_swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int ArrayInt::LinearSearch(int key)
{
    int i;
    for (i = 0; i < Len; i++)
    {
        if (key == A[i])
        {
            _swap(&A[i], &A[0]);
            return i;
        }
    }
    return -1;
}

int ArrayInt::BinarySearch(int key)
{
    int l, mid, h;
    l = 0;
    h = Len - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int ArrayInt::Get(int index)
{
    if (index >= 0 && index < Len)
        return A[index];
    return -1;
}

int ArrayInt::GetLen()
{
    return this->Len;
}

int ArrayInt::GetSize()
{
    return this->Size;
}

void ArrayInt::Set(int index, int value)
{
    if (index >= 0 && index < Len)
        this->A[index] = value;
}

int ArrayInt::Max()
{
    int max = A[0];
    int i;

    for (i = 1; i < Len; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

int ArrayInt::Min()
{
    int min = A[0];
    int i;

    for (i = 1; i < Len; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    return min;
}

int ArrayInt::Sum()
{
    int sum = 0;
    int i;

    for (i = 0; i < Len; i++)
    {
        sum += A[i];
    }
    return sum;
}

float ArrayInt::Avg()
{
    return (float)Sum() / Len;
}

void ArrayInt::Reverse()
{
    int i, j;
    for (i = 0, j = Len - 1; i < j; i++, j--)
    {
        _swap(&A[i], &A[j]);
    }
}

void ArrayInt::InsertSorted(int value)
{
    int i = Len - 1;

    // shifts everyone to assign space
    while (A[i] > value)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = value;
}

bool ArrayInt::IsSorted()
{
    int i;
    for (i = 0; i < Len - 1; i++)
    {
        // check if everything is sorted
        if (A[i] > A[i + 1])
            return false;
    }
    return true;
}

void ArrayInt::Rearrange()
{
    int i, j;
    i = 0;
    j = Len - 1;
    while (i < j)
    {
        while (A[i] < 0)
            i++;
        while (A[j] >= 0)
            j--;
        if (i < j)
            _swap(&A[i], &A[j]);
    }
}

    ArrayInt ArrayInt::Merge(const ArrayInt &arr1, const ArrayInt &arr2)
    {
        int i,j,k;
        i=j=k=0;
        int arr1Len = arr1.Len;
        int arr2Len = arr2.Len;
        ArrayInt arr3(arr1Len + arr2Len);

        while(i < arr1Len && j < arr2Len)
        {
            //takes the smaller and merges into the position
            //test also with append later
            if(arr1.A[i] < arr2.A[j])
            {
                arr3.A[k++] = arr1.A[i++];
            }
            else
            {
                arr3.A[k++] = arr2.A[j++];
            }
            //copy remaining elements
        }
        for(; i < arr1Len ; i++)
            arr3.A[k++] = arr1.A[i];
        for(; j < arr2Len ; j++)
            arr3.A[k++] = arr2.A[j];
        arr3.Len = arr1Len + arr2Len;
        return arr3;
    }

