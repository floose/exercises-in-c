#include <stdio.h>

/*
Taylor Series of e^x using recursion
Computionaly costly.
The recursion is based on the expansion of Taylor, that is:
e^x = 1 + x/1 + x*x/2! + x*x*x/3! + x*x*x*x/4! * ...

variables:
x is the expoent
n is the number of terms
count returns the number of iterations taken
*/

int count = 0; // number of iterations 

float e(int x, int n)
{
	// initial memory storage for recursion
	static float p = 1, f = 1;
	float r = 0;

	count++; // counts number of loops

	if (n == 0)
		return 1;
		
	r = e(x, n - 1);
	// fundamental recursive functions
	p = p * x;
	f = f * n;
	return r + p / f;
}

int main()
{
	printf("Result: %f \n", e(3, 30));
	printf("Count: %d \n", count);
	return 0;
}
