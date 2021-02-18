/* This program sorts the inputs in ascending order */
#include <stdio.h>

int main()
{
	int input[5]; // Variable declaration
	int i=0;
	int j=0;
	int n = 0;
	int temp;
	for(i=0;i<5;i++) // Stores the input in the array using loop
	{
		switch(i){
			case 0:
				printf("\nPlease enter the 1st input: ");
				break;
			case 1:
				printf("\nPlease enter the 2nd input: ");
				break;
			case 2:
				printf("\nPlease enter the 3rd input: ");
				break;
			case 3:
				printf("\nPlease enter the 4th input: ");
				break;
			case 4:
				printf("\nPlease enter the 5th input: ");
			default:
				break;
		}
		scanf(" %d", &input[i]);
		printf("\n");
	}
	i=0;
	printf("Input: ");// Prints out the input integers
	while(i<5){
		printf(" %d", input[i]);
		i++;
	}
	printf("\nSequence (in ascending order): ");
	
	for(j = 0; j<5; j++)// Nested for loop that rearranges the integers based on their value
	{
		for(n=0;n<j;n++)
		{
			if(input[n] > input[j])
			{ 
				temp = input[n];
				input[n] = input[j];
				input[j] = temp;
			}
			
		}
	}
	j=0;
	while(j<5) // Prints out the arranged integers
	{
		printf(" %d", input[j]);
		j++;
	}
	printf("\n");

	
	return 0;
}
