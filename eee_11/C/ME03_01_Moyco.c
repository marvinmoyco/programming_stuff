/* This program asks for a number from 1-12 and then it outputs the Factorial output of the said number */
#include <stdio.h>

int main()
{
	int factorial = 1; // Variable Declaration
	int i = 1;
	int num = 1;
	printf("Please enter a number from 1-12: "); // Asks the user for an input.
	scanf("%d", &num);
	if ((num >= 1) && (num <= 12)) // If statement that restricts the input range from 1-12
	{
		printf("\nInput number: %d\n", num); //Outputs the input of the user
		while (i <= num) // While statement that checks if i is less than the input number
		{
			factorial = factorial * i; //Factorial equation
			i = i + 1;
		}
		printf("%d! = %d\n", num, factorial); //Prints the final output

	}
	else // Else statement that outputs if the user inputted an invalid input
	{
		printf("You have entered an invalid input. Please try again\n");
	}
	return 0;
}
