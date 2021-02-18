/* This program determines in what age group the input of the user has given. */
#include <stdio.h>

int main()
{
	int input; // Variable Declaration
	printf("Input age to determine his/her age group: \n"); // Asks the user for an input
	scanf("%d", &input);
	if (input >= 0) // If statement that determines if the input is a valid input.
	{
	/* In this part of the program, the nested if statements determines the value of the input and it prints the corresponding age group
	   associated in it. */
		if(input <= 2){
			printf("She/He is still inelligible for school.\n");
			
		}
		else if ((input >= 3) && (input <= 5))
		{
			printf("She/He is in Preschool.\n");
			if(input <=4){
				printf("She/He is in Nursery.\n");			
			}
			else{
				printf("She/He is in Kindergarten.\n");
			}
		}
		else if ((input >= 6) && (input <= 11)){
			printf("She/He is in Elementary School.\n");	
		}
		else if((input >= 12) && (input <= 17)){
			printf("She/He is in Secondary School.\n");
		}
		else if((input >=18) && (input <= 59)){
			printf("She/He is ready to enter the Workforce.\n");
			if(input <= 22){
				printf("She/He could be studying in College.\n");
			}
			else{
				printf("She/He could be in her/his postgraduate studies.\n");
			}		
		}
		else{
			printf("She/He is a senior citizen.\n");
		}
	}
	else {
		printf("You have entered an invalid input. Please try again."); //Prints out if the input is invalid.
	}
	return 0;
}
