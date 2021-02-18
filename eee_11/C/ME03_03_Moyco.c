/* This program identifies if the input number is a prime number or not. */
#include <stdio.h>

int main()
{
	int input, i, check =0; // Variable Declaration
	printf("Enter a number: \n"); // User input
	scanf("%d", &input);
	if((input >= 1) && (input <= 1000)) // Sets the range of valid input
	{
		for(i=2; i<= input/2; i++) // Checks if the input if the input is prime or not.
		{
			
			if(input%i == 0) // If input%i = 0, the input is not a prime number
			{
				check++;
				break;
			}
			
		}
		if(check == 0 && input != 1)// If statement that outputs the number and if it is a prime number or not.
			{
				printf("Your number %d is a prime number\n", input);
				
			}
			else{
				printf("Your number %d is not a prime number\n", input);
				
			}
	}
	else{ // Prints out that the user entered an invalid output.
		printf("You have entered an invalid input.");
	}
	return 0;
}

