#include <iostream>
#include "ArrayInt.h"

using namespace std;

int main()
{
    int numbers1[] = {4,6,10,12,19};
    int numbers2[] = {3,4,5,9,11};
    ArrayInt arr1(20,5,numbers1);
    ArrayInt arr2(20,5,numbers2);


    ArrayInt arr3 = ArrayInt::Merge(arr1,arr2);

    cout << "Test" << endl;
    arr1.Display();
    cout << "Next" << endl;
    arr2.Display();
    cout << endl;
    cout << "Result Array Next" << endl;
    arr3.Display();

    return 0;
}
