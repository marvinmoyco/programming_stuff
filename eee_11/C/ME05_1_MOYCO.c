/* This prgoram outputs a Fibonacci sequence based on the input of the user */
#include <stdio.h>

void get_fibonacci(int, int, int, int); // Function prototype

int main()
{
	int fNumber = 0; // Variable declaration
	int sNumber = 1;
	int nSequence;
	int counter = 2;
	printf("Please enter a number: "); // User input
	scanf(" %d", &nSequence);
	if (nSequence >=2 && nSequence <=30) // Checks if the input is between 2 and 30 (inclusive)
	{
		printf(" Fibonacci sequence: %d, %d, ", fNumber, sNumber); // Prints the first two digits of the sequence
		get_fibonacci(fNumber, sNumber, nSequence, counter); // Function call of get_fibonacci
	}
	else
	{
		printf("Invalid Input\n");
	}
	return 0;
}

void get_fibonacci(int firstnumber, int secondnumber, int sequence, int counter) // Function definition 
{
	if(sequence != counter) //Checks if the input is not equal to the counter 
	{
		int sum = firstnumber + secondnumber;
		firstnumber = secondnumber;
		secondnumber = sum;
		printf("%d, ", sum);
		counter = counter +1;
		get_fibonacci(firstnumber, secondnumber, sequence, counter); // Function call inside the function
	}
	else{
		printf("\n End of sequence\n");
	}
}
