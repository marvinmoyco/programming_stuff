/* This program calculates the average of every column and every row of a 5x5 matrix array */
#include <stdio.h>

float get_row_average(float arr1 [5] [5], int row_number );//Function prototypes
float get_column_average(float arr2 [5] [5], int column_number );

int main()
{
	int i,j =0;// Variable declaration
	float matrix [5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};//2D Array declaration
	printf("Please enter 25 floating points: \n");//User input
	for(i=0; i<5;i++)// Nested for loop to input by filling up each column of each row first
	{
		for(j=0;j<5;j++)
		{
			scanf(" %f", &matrix[i][j]);
		}
		printf("\n");
	}
	printf("\nThe matrix is: \n");// Prints out the 5x5 matrix with tab and 2 decimal places
	for(i=0; i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("\t %.2f", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<5;i++)// For loops that calculates the average of each row and column
	{
		printf("Row # %d Average: %.2f\n", i+1, get_row_average(matrix, i)); //Prints the return value of function
	}
	for(i=0;i<5;i++)
	{
		printf("Column # %d Average: %.2f\n", i+1, get_column_average(matrix , i)); 
	}
	return 0;
}

float get_row_average(float arr1 [5] [5], int row_number)//Function that calculates the row average
{
	int m=0;
	float sum = 0;
	float average = 0;
	for(m=0;m<5;m++)//Finds the total sum of the elements in the row
	{
		sum = sum + arr1 [row_number][m];
	}
	average = (float) sum/5;
	return average;// returns the average value of a row
	
}

float get_column_average(float arr2 [5] [5], int column_number)//Function that calculates the column average
{
	int m=0;
	float sum= 0; 
	float average = 0;
	for(m=0;m<5;m++)// Finds the total sum of the elements in a column
	{
		sum = sum + arr2 [m][column_number];
	}
	average = (float) sum/5;
	return average;// Returns the average value of a column
}
