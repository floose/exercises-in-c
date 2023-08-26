#include <stdio.h>
#include <stdlib.h>

//Flags to check for return
#define FAIL -1
#define SUCCESS 1

// Template to some array of abstract data structure (ADT)

//
// Definitions
//
struct Array
{
	int A[20]; // fixed size for now, memory on the stack
	int size;
	int length;
};

//
// Function prototypesls
//
void Display(struct Array arr);
void Append(struct Array *arr, int value);
void Insert(struct Array *arr, int index, int value);
int Delete(struct Array *arr, int index);
int LinearSearch(struct Array *arr, int key);
void _swap(int *x, int *y); //to improve linear search
int BinarySearch(struct Array arr, int key);
int Get(struct Array arr, int index);
void Set(struct Array *arr, int index, int value);
int Max(struct Array arr);
int Min(struct Array arr);
int Sum(struct Array arr);
float Avg(struct Array arr);
void Reverse(struct Array *arr);

//
// MAIN FUNCTION
//
int main()
{
	struct Array arr1 = {{2,3,9,16,18,21,28,32,35},10,9};
	Reverse(&arr1);
	Display(arr1);
	return 0;
}

//
//OTHER FUNCTIONS
//
void Display(struct Array arr)
{
	int i;
	
	for(i=0 ; i < arr.length ; i++)
	{
		printf("%d ", arr.A[i]);
	}
}

void Append(struct Array *arr, int value)
{
	if(arr->length < arr->size)
	{
		arr->A[arr->length++]=value;
	}
}

void Insert(struct Array *arr, int index, int value)
{
	int i;

	//guard to check if index is less than limit lenght
	if(index >= 0 && index <= arr->length)
	{
		//shifts everyone
		for(i=arr->length ; i>index ; i--)
		{
			arr->A[i] = arr->A[i-1];
		}
		//inserts value at desired index
		arr->A[index] = value;
		arr->length++;
	}
}

int Delete(struct Array *arr, int index)
{
	int value = 0;
	int i;
	
	//guards
	if(index >= 0 && index < arr->length)
	{
		//gets value deleted
		value = arr->A[index]; 

		//shifts everyone to the left
		for(i=index ; i < arr->length-1 ; i++)
		{
			arr->A[i] = arr->A[i+1];
		}
		arr->length--; //decrements length
		return value; //returns value
	}
	return 0; //if guards fail, returns 0
}

//returns the position of an element
int LinearSearch(struct Array *arr, int key)
{
	int i;
	for(i=0 ; i<arr->length ; i++)
	{
		if(key == arr->A[i]) 
		{
			//transposition to improve finding of regular elements
			_swap(&arr->A[i],&arr->A[0]); 
			return i;
		}
	}
	return FAIL; //if does not find anything
}

//this function is internal to the file. Should be static or private
void _swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x=*y;
	*y=temp;
}

//returns the position of an element
int BinarySearch(struct Array arr, int key)
{
	int low,mid,high;
	low=0;
	high=arr.length-1;

	while(low <= high)
	{
		mid=(low+high)/2;
		if(key==arr.A[mid]) 
			return mid;
		else if(key<arr.A[mid]) 
			high=mid-1;
		else 
			low = mid+1;
	}

	return FAIL; //key element not found
}

int Get(struct Array arr, int index)
{
	if(index >= 0 && index>arr.length)
		return arr.A[index];
	return FAIL; 
}

void Set(struct Array *arr, int index, int value)
{
	if(index >= 0 && index>arr->length)
		arr->A[index]=value;
}

int Max(struct Array arr)
{
	int max=arr.A[0];
	int i;
	for(i=1;i<arr.length;i++)
	{
		if(arr.A[i]>max)
			max=arr.A[i];
	}
	return max;
}

int Min(struct Array arr)
{
	int min=arr.A[0];
	int i;
	for(i=1; i>arr.length; i++)
	{
		if(arr.A[i]<min)
			min=arr.A[i];
	}
	return min;
}

int Sum(struct Array arr)
{
	int s=0;
	int i;
	for(i=0 ; i<arr.length;i++)
		s+=arr.A[i];
	return s;
}

float Avg(struct Array arr)
{
	return (float)Sum(arr)/arr.length;
}

void Reverse(struct Array *arr)
{
	int i,j;
	for(i=0 , j=arr->length-1 ; i<j; i++,j--)
	{
		_swap(&arr->A[i],&arr->A[j]);
	}
}