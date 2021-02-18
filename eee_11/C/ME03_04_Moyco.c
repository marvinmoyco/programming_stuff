/* This program makes a multiplication table matrix based on the user's input of columns and rows */
#include <stdio.h>

int main()
{
	int rows, columns, i, j = 1; // Variable declaration
	printf("Input the number of rows (1-10)\n"); // Input of the user
	scanf("%d", &rows);
	printf("\nInput the number of columns(1-10)\n");
	scanf("%d", &columns);
	if(((rows <=10) && (rows >= 1)) && ((columns <= 10) && (columns >=1))) // Sets the range of valid inputs
	{
		for(i=1;i<=rows;i++) // Nested for loop. For loop that identifies the rows
		{
			printf("\n");
			for(j=1;j<=columns; j++) // For loop that identifies the columns
			{
				printf("%3d ", i*j); // Prints the product of i and j
				
			}
			
		}
	}
	else{ // Prints out that the user entered an invalid input.
		printf("Invalid input.\n");	
	}
	return 0;
}
