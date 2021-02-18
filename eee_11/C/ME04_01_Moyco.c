/* Calculator Program. This program calculates the sum, difference, product, quotient, and modulo of two integer inputs. */
#include <stdio.h>


int sum(int, int); //Function prototypes
int difference(int, int);
int product(int, int);
float quotient(int, int);
int modulo(int, int);

int main()
{
	int getsum, getdiff, getprod, getmodulo, input1, input2 = 0; //Variable declaration
	float getquotient = 0.0;

	printf("Please enter the first integer: ");// User input
	scanf(" %d", &input1);
	printf("\nPlease enter the second integer: ");
	scanf(" %d", &input2);
	printf(" \nYour integers are %d (1st) and %d (2nd).\n", input1, input2); //Prints the input integers

	getsum = sum(input1, input2); // Assigns the return value of each functions into a variable
	getdiff = difference(input1, input2);
	getprod = product(input1, input2);
	getquotient = quotient(input1, input2);
	getmodulo = modulo(input1, input2);
	
	printf("Sum (1st integer + 2nd integer): %d \n", getsum);// Prints the sum, difference, product, quotient, and modulo of the two integer inputs.
	printf("Difference (1st integer - 2nd integer): %d \n", getdiff);
	printf("Product (1st integer * 2nd integer): %d \n", getprod);
	printf("Quotient (1st integer / 2nd integer): %f \n", getquotient);
	printf("Modulo (1st integer %% 2nd integer): %d \n", getmodulo);

	return 0;
}

int sum(int x, int y) //Function that adds two integer
{
	return x+y;
}

int difference(int a, int b)//Function that subtracts two integer
{
	return a-b;
}

int product(int c, int d) // Function that multiplies two integer
{
	return c*d;
}

float quotient (int e, int f)//Function that divides two integer
{

	return (float) e/f;
}

int modulo(int g, int h)//Function that gets the remainder of the division of two integers
{
	return g%h;
}
