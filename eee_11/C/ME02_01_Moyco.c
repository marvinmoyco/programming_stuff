/* This program identifies a number if it is a positive integer, negative integer, or zero.*/
#include <stdio.h> 

int main(void)
{
	int input; // Variable Declaration
	printf("Please enter an integer to identify if the integer is positive, negative, or zero:  "); // Directions for the user
	scanf("%d", &input); // Waits for the input of the user
	if (input < 0) // This if statement determines if the input number is less than 0 (negative), greater than zero (positive), or equal to zero
	{
		printf("\nYour number %d is a negative integer\n", input);
	}
	else if (input == 0)
	{
		printf("\nYour number %d is equal to zero (0)\n", input);
	}
	else if (input > 0)
	{
		printf("\nYour number %d is a positive integer\n", input);
	}
	return 0; // returns 0
}
