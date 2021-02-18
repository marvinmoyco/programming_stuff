/* THis program can identify a number or letter, evaulate a power function, and generate a random number based on the range */
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	char input; //Variable declaration
	char aInput;
	double base;
	double exponent;
	int range;

	printf("A/a - Identifying if an input is a letter or number\n");//Prints out the choices
	printf("B/b - Input a base and exponent and evaluate it\n");
	printf("C/c - Generate a random number base on the maximum range set by the user\n");
	printf("Please choose a letter to do an activity: ");//Waits for user input for choosin what kind of activity
	scanf("%c", &input);
	// if the user inputs A/a, it identifies another input of the user if it is alphanumeric, and if it is a letter or number
	if((input == 'A') || (input == 'a'))
	{
		printf("Please enter an alphanumeric symbol: ");
		scanf(" %c", &aInput);
		if(isalnum(aInput))// Checks if the input is alphanumeric
		{
			printf("\nYour input %c is an alphanumeric symbol\n", aInput);
			if(isalpha(aInput))// Checks if input is a letter
			{
				printf("You entered %c, which is a letter\n", aInput);
			}
			else if (isdigit(aInput))//Checks if input is a number
			{
				printf("You entered %c, which is a number\n", aInput);
			}
		}
		else{
			printf("Your input is not an alphanumeric symbol\n");
		}
	}
	// If the user enters B/b, the program evaluates the power function based on the input of a base and an exponent
	else if ((input == 'B') || (input == 'b'))
	{
		double power;
		printf("\nPlease enter the base: ");
		scanf(" %lf", &base);
		printf("\nPlease enter the exponent: ");
		scanf(" %lf", &exponent);
		power = pow(base, exponent);// Evaluates the base and exponent 
		printf("\n%lf raised to %lf is equal to %lf\n", base, exponent, power);
		
	}
	//If the user enters C/c, the program generates a random number based on the range provided by the user
	else if ((input == 'C') || (input == 'c'))
	{
		printf("\nPlease enter the maximum range for the random generator: ");
		scanf(" %d", &range);
		printf("\nRandom number: %d", ((rand()%range)+1));// Generates a random number
		printf("\n");
	}
	else{//Checks if the first input is A/a, B/b, or C/c and prints the input is invalid if the user inputs something else
		printf("Invalid input.\n");
	}
	return 0;
}
