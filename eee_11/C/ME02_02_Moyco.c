/* This program asks who is the 2017 Miss Universe and prints out the result of the answer of the user */
#include <stdio.h>

int main(void)
{
	char input; // Variable declaration
	printf("Question: Who won in the 2017 Miss Universe?\n"); //Prints out the question
	printf("Choose the letter of your answer: \n"); // Prints out the choices 
	printf("a - Miss Philippines\n");
	printf("b - Miss France\n");
	printf("c - Miss Netherlands\n");
	printf("d - Miss Haiti\n");
	scanf("%c", &input); // Waits for the user to input the answer
	if ((input == 'a') || (input == 'A')) // This if statement determines what is the answer of the user and if it is correct, incorrect, or invalid
	{
		printf("Your answer is %c - Miss Philippines.\n", input);
		printf("Your answer is incorrect!\n");
	}
	else if( (input == 'b') || (input == 'B'))
	{
		printf("Your answer is %c - Miss France.\n", input);
		printf("Your answer is correct!\n");
	}
	else if( (input == 'c') || (input == 'C'))
	{
		printf("Your answer is %c - Miss Netherlands.\n", input);
		printf("Your answer is incorrect!\n");
	}
	else if( (input == 'd') || (input == 'D'))
	{
		printf("Your answer is %c - Miss Haiti.\n", input);
		printf("Your answer is incorrect!\n");
	}
	else 
	{
		printf("Your answer is %c\n", input);
		printf("You have an invalid answer!\n");
	}
	return 0;
}
