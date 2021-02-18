/* This program computes for the total sum and average of the inputs of the user. Only positive inputs and zero is considered a valid input. */
#include <stdio.h>

int main()
{
	int input = 0; // Variable Declaration
	int sum = 0;
	float average = 0;
	int counter = 1;
	do { // Do-while loop keeps the running sum and running average to execute infinitely until the user inputs a negative number
		printf("Input a number: "); // Asks the user for an input
		scanf("%d", &input);
		sum = sum + input; //Computes the sum of the inputs
		average = (float) sum / counter; // Computes for the average of the inputs
		printf("Iteration number: %d, Sum: %d, and Average: %f\n", counter, sum, average); // Prints out the iteration number, sum, and average
		counter = counter + 1; // Increments the counter (the no. of inputs)
	
	} while (input >= 0);
	return 0;
}
