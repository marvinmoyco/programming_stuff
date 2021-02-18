/* 

Machine Problem #1 (EEE 11 WLMFQR)
Jan Marvin D. Moyco
Instructor: Paul Alpano
Brief Description:
This program solves different matrix operations on two input matrices */
#include <stdio.h>	//Only library allowed is the stdio.h library

void displayMatrix(int input, float matrix[5][5]); //Function prototypes for different matrix operations.
void transposeMatrix(float matrix [5] [5], int input); 
void getSum(float arr1[5][5], int input1, float arr2[5][5], int input2); 
void getDifference(float d1[5][5], int size1, float d2[5][5], int size2);
void getProduct(float m1[5][5], int s1, float m2[5][5], int s2);
void getQuotient(float dt1[5][5], int i1, float dt2[5][5], int i2, float determinant2);
float getDeterminant(float at1[5][5], int j1);

int main()
{		// This is the main function where most of the function calls are made and the inputs are entered.
	int inputD1 = 0;	// Variable declarations and initializations
	int inputD2 = 0;
	float determinantA = 0;
	float determinantB = 0;
	float matrixA [5] [5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
	float matrixB [5] [5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
	int i,j;
	printf("Please enter the dimension of Matrix A (Values from 2-5): "); // Input of the user
	scanf(" %d", &inputD1); //Scans the input
	printf("\n");
	
	if (inputD1 >= 2 && inputD1 <=5)
	{		// This if statement checks if the input for the size of the square matrix A is within the specified range (2-5)
		printf("Please enter the values of Matrix A (Format: single line diffferentiated by a space, e.g. 1 2 3 4 5): \n");	
		for(i=0;i<inputD1;i++)
		{ // This outer for loop makes sure that each row of the matrix A is placed properly
			for(j=0;j<inputD1;j++)
			{	//This inner for loop makes sure that each column of the matrix A is placed properly
				scanf(" %f", &matrixA [i] [j]); // Scanning of input
			}
		}
	}
	else
	{ //This else statement prints out that the input (size of matrix A) is not within the specified range (2-5) and ends the program
		printf(" Invalid input.\n");
		return 0; //Ends the main program
	}
	printf("\n");
	printf("Please enter the dimension of Matrix B (Values from 2-5): ");
	scanf(" %d", &inputD2);//Scans the input
	printf("\n");
	
	if (inputD2 >= 2 && inputD2 <=5)
	{		// This if statement checks if the input for the size of the square matrix B is within the specified range (2-5)
		printf("Please enter the values of Matrix B (Format: single line diffferentiated by a space, e.g. 1 2 3 4 5): \n");	
		for(i=0;i<inputD2;i++)
		{	// This outer for loop makes sure that each row of the matrix B is placed properly
			for(j=0;j<inputD2;j++)
			{	//This inner for loop makes sure that each column of the matrix B is placed properly
				scanf(" %f", &matrixB [i] [j]);
			}
		}
	}
	else
	{	//This inner for loop makes sure that each column of the matrix A is placed properly
		printf(" Invalid input.\n");
		return 0; 
	}
	/*At this part of the main program, the program calls on the different functions to perform different matrix operations and prints them. The functions will do an error check to make sure that the inputs are valid and the operations can be done correctly*/
	printf("\n");
	printf("Displaying Matrix A with %dx%d dimension: \n", inputD1,inputD1);
	displayMatrix(inputD1, matrixA);	//Function call for displaying matrix A
	printf("\n");
	printf("Displaying Matrix B with %dx%d dimension: \n", inputD2,inputD2);
	displayMatrix(inputD2, matrixB);	//Function call for displaying matrix B
	printf("\n");
	printf("Displaying Matrix A Transpose: \n");
	transposeMatrix(matrixA, inputD1);	//Function call for transposing matrix A
	printf("\n");
	printf("Displaying Matrix B Transpose: \n");
	transposeMatrix(matrixB, inputD2);	//Function call for transposing matrix B
	printf("\n");
	printf("Displaying Sum (A + B): \n");
	getSum(matrixA, inputD1, matrixB, inputD2);	//Function call for getting the sum of matrix A matrix B
	printf("\n");
	printf("Displaying Difference (A - B): \n");
	getDifference(matrixA, inputD1, matrixB, inputD2); // Function call for getting the difference of matrix A matrix B
	printf("\n");
	printf("Displaying Product (A * B): \n");
	getProduct(matrixA, inputD1, matrixB, inputD2);	//Function call for getting the product(dot product) of matrix A matrixB
	determinantA = getDeterminant(matrixA, inputD1); //Saves the determinants of matrix A and B into two float variables
	determinantB = getDeterminant(matrixB, inputD2);
	printf("\nDeterminant A = %.2f\n", determinantA); // Prints the determinants
	printf("\nDeterminant B = %.2f\n", determinantB);
	getQuotient(matrixA, inputD1, matrixB, inputD2, determinantB); //Function call for getting the quotient of matrix A matrix B and the adjugate and inverse of matrix B
	printf("\n");
	return 0;	//End of program.
}




void displayMatrix(int input, float matrix[5][5])
{	// This function displays the input matrix on the terminal
	int m = 0;	//Variable declaration
	int n = 0;
	for(m = 0;m<input;m++)
	{	//This outer for loop makes sure that the input matrix will print the proper number of rows
		for(n=0;n<input;n++)
		{	//This outer for loop makes sure that the input matrix will print the proper number of columns
			printf("\t%.2f", matrix[m][n]); //Printing of input matrix
		}
		printf("\n");
	}
	
}



void transposeMatrix(float matrix [5] [5], int input)
{	//This function transposes the input matrix and print the resulting matrix
	int m = 0;
	int n = 0;
	
	for(m = 0;m<input;m++)
	{	//This outer for loop makes sure that the input matrix will print the proper number of rows
		
		for(n=0;n<input;n++)
		{	//This outer for loop makes sure that the input matrix will print the proper number of columns
			printf("\t%.2f", matrix[n][m]); //Prints the transposed matrix because it prints the input matrix's all the columns first before the rows.
		}
		printf("\n");
	}
	
}


void getSum(float arr1[5][5], int input1, float arr2[5][5], int input2)
{	//This function gets the sum of the two equal in size matrices
	int a,b = 0;
	float sum[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
	if(input1 == input2)
	{	//This if statement makes sure that the size of the two square matrix is equal before proceeding to adding them together
		for(a=0;a<input1;a++)
		{	//This outer for loop makes sure that the rows of sum[][], arr1[][], and arr2[][] are selected properly so that the operation is properly executed
			for(b=0;b<input2;b++)
			{	//This inner for loop makes sure that the columns of sum[][], arr1[][], and arr2[][] are selected properly so that the operation is properly executed
				sum[a][b] = arr1[a][b] + arr2[a][b]; //Saves the sum (element-wise) of matrix A and B in sum array
				printf("\t %.2f", sum[a][b]); // Prints the sum array
			}
				printf("\n");
		}
	}
	else
	{	//This else statement prints out that it cannot get the sum because the size of the two matrix are not equal.
		printf("Sum not possible. Matrix dimensions are not equal. Matrix A has %dx%d dimension and Matrix B has %dx%d dimension.\n",input1, input1, input2, input2);
	}
	
}



void getDifference(float d1[5][5], int size1, float d2[5][5], int size2)
{		//This function gets the difference of two equal in size matrices and prints them to the terminal
	int c,d = 0;	//Variable declaration and initialization
	float diff[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
	if(size1 == size2)
	{	//This if statement makes sure that the size of the two square matrix is equal before proceeding to subtracting the two matrix
		for(c=0;c<size1;c++)
		{	//This outer for loop makes sure that the rows of diff[][], d1[][], and d2[][] are selected properly so that the operation and printing are properly executed
			for(d=0;d<size2;d++)
			{	//This inner for loop makes sure that the rows of diff[][], d1[][], and d2[][] are selected properly so that the operation and printing are properly executed
				diff[c][d] = d1[c][d] - d2[c][d];	// Saves the difference element-wise (A-B) in diff array
				printf("\t %.2f", diff[c][d]);	//Prints the diff array
			}
				printf("\n");
		}
	}
	else
	{	//This else satement prints that the operation is not possible because the size of the two matrices are not equal
		printf("Difference not possible. Matrix dimensions are not equal. Matrix A has %dx%d dimension and Matrix B has %dx%d dimension.\n",size1, size1, size2, size2);
	}
}




void getProduct(float m1[5][5], int s1, float m2[5][5], int s2)
{	//This function gets the product of two equal in size matrices and prints them to the terminal

	int e,f,g = 0; // Variable declaration and initialization
	float m3 [5] [5] [5] =  {{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}};
	float dprod[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};

	if(s1 == s2)
	{	//Makes sure that the size of the two input matrices are equal

		/* This part of code saves all the possible products of m1 and m2 in a 3-d Matrix where the 1st row of the 1st face of m3 is the 1st element of the 1st row of the product of matrix A and B, and the 2nd row of 2nd face of m3 is the 2nd elemenent of the 2nd row of the product matrix of matrix A and matrix B, and so on.*/
		for(e=0;e<s1;e++)
		{	//This for loop makes sure that the proper face of the 3-D matrix m3 is properly selected and that the row of m1 is properly selected
			for(f=0;f<s2;f++)
			{	// This for loop makes sure that the proper row of m3 is selected and the proper column of m2 is selected
				for(g=0;g<s1;g++)
				{	//This for loop makes sure that the proper row of m2 is selected as well as the proper columns of m1 and m3
					m3[e][f][g] = m1[e][g] * m2[g][f];
				}
			}
		}


		/*This nested for loops gets the sum of a row in m3 matrix then it saves it in a cell of dprod (dot product) matrix where the 1st row of the 1st face of m3 is the 1st cell of the 1st row of dprod and the 3rd row of the 1st face of m3 is the 3rd cell of the 1st row of dprod. */
		for(e=0;e<s1;e++)
		{	//This makes sure that the proper row of dprod is selected and the proper face of the 3-D matrix m3 is selected
			for(f=0;f<s2;f++)
			{	// This makes sure that the proper column of dprod is selected and the proper row of the 3-D matrix m3 is selected
				for(g=0;g<s2;g++)
				{ // This makes sure that the proper column of the 3-D matrix is selected
					dprod[e][f] = dprod[e][f] + m3[e][f][g];
				}
				
			}

		}
		printf("\n");
		/*This prints out the matrix dprod after getting the sum of the rows of m3 and saving it in the respecive cells of dprod.*/
		for(e=0;e<s1;e++)
		{	//This makes sure that the proper row is selected in dprod matrix
			for(f=0;f<s2;f++)
			{	//This makes sure that the column of dprod is properly selected
				printf("\t%.2f", dprod[e][f]);
			}
			printf("\n");
		}
		printf("\n");
		printf("\n");

	}
	else
	{	//Prints out that the operation cannot be done because the matrix sizes of the two input matrices are not equal.
		printf("Product not possible. Matrix dimensions are not equal. Matrix A has %dx%d dimension and Matrix B has %dx%d dimension.\n",s1, s1, s2, s2);
	}
}




float getDeterminant(float at1[5][5], int j1)
{
	int m,n,o,p,z = 0;	//Variable Declaration and Initialization
	float det = 0;
	float p1 = 1;
	float p2 = 1;
	float p3 = 1;
	float p4 = 1;
	float p5 = 1;
	float p6 = 1;
	float m41[4][3][5] = {{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}};
	float m51_0[20][3][5] = {{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}};
	float det_temp[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	float r[4][6] = {{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1}};
	float r_0[20][6] = {{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1}};
	float j[4] = {0,0,0,0};
	float j_0[5] = {0,0,0,0,0};
	float m31[3][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
	float m51[5][4][4] = {{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}};
	switch(j1) // Switch statement that identifies what the size of the dimension of the input matrix
	{
		
		
		
		case 2: // Case 2 where the input matrix is a 2x2 Matrix
		det = ((at1[0][0] * at1[1][1]) -(at1[1][0] * at1[0][1])); // gets the determinant by getting the difference of the diagonal products of each 2x2 matrix
		break;
		
		
		
		
		case 3:	// Case 3 where the input matrix is a 3x3 Matrix
			/*In getting the determinant of the 3x3 matrix, I  used the basket weave method where i transformed the 3x3 matrix into a 3x5 matrix and then I find the diagonal products of as well as their differences*/

		//Transferring the matrix A and B to a 3x5 matrices
		for(m=0;m<j1;m++)
		{	//Makes sure that the selected row for m31 and at1 are correct
			for(n=0;n<j1;n++)
			{	//Makes sure that the selected column of m31 and at1 are correct
				m31[m][n] = at1[m][n];
			}
		}
		//Gets the 1st and 2nd columns of the transformed matrix and copies it to the 4th and 5th columns making a 3x5 matrix
		for(n=3, m=0;n<5 && m < 2;n++, m++)
			{	//Makes sure that the column of m31 (n variable) and the column of at1 (m variable) are properly selected
				m31[0][n] = at1[0][m];
				m31[1][n] = at1[1][m];
				m31[2][n] = at1[2][m];
			}
		
		//Gets the product of the different diagonals (increasing and decreasing)
		for(m=0;m<3;m++)
		{	//Makes sure that the columns and rows of m31 are properly selected
			p1 = p1 * m31[m][m]; //p1 to p3 are the decreasing diagonals
			p2 = p2 * m31[m][m+1];
			p3 = p3 * m31[m][m+2];
			p4 = p4 * m31[m][4-m]; //p4 to p6 are the increasing diagonals
			p5 = p5 * m31[m][3-m];
			p6 = p6 * m31[m][2-m];
		}
		
		det = (p1+p2+p3) - (p4+p5+p6); //Determinant of a 3x3 matrix by basket-weave method; Difference of the sum of the product of increasing diagonals and the sum of the decreasing diagona;
		break;
		
		
		
		case 4:	// Case 4 where the input matrix is a 4x4 Matrix
		
		//Transforms that 4x4 matrix into a 3x3 matrix
		for(m=1,o=0;o<3;m++,o++) //Multiple initialization
		{	//Makes sure that the row of at1 and the row of m41 are properly selected
			for(n=1,p=0;p<3;n++,p++)
			{	//Make sure that the column of at1 on different faces of m41 are properly selected as well as the column of m41
				m41[0][o][p] =  at1[m][n];
				m41[3][o][p] = at1[m][p];
				if(p != 1)
				{	// This makes sure that the program will correctly assign the proper element of m41 to the proper element of at1
					if(p!=2)
					{	//This makes sure that the program will follow the correct procedure if p is not equal to 2
						m41[1][o][p] = at1[m][p];
					}
					else
					{	//This makes sure that the the program will not assign at1[m][2] to the program by skipping it
						m41[1][o][p] = at1[m][3];
					}
				}
				if(p != 2)
				{	//This makes sure that the program will assign proper values to m41 if at1 is not equal to 2
					m41[2][o][p] = at1[m][p];
				}
				if(p == 1)
				{	//This makes sure that the program will skip the value of at1[m][1] and jump to the next column.
					m41[1][o][1] = at1[m][2];
					
				}
				if(p == 2)
				{	//This makes sure that the value of at1[m][2] is skipped and replaced by the next column of at1 array
					m41[2][o][2] = at1[m][3];
				}
			}
		}


		//Gets the 1st and 2nd columns and copies it to the 4th and 4th columnns making a 3x5 matrix
		for(o=0;o<4;o++)
		{	//This makes sure that the face of m41 is properly selected
			for(n=3, m=0;n<5 && m < 2;n++, m++)
				{	//This makes sure that the column of m41 is properly selected before and after the assignment operator
					m41[o][0][n]= m41[o][0][m];
					m41[o][1][n] = m41[o][1][m];
					m41[o][2][n] = m41[o][2][m];
				}
		}
		
		//This nested for loop gets the productof the increasing diagonals and the decreasing diagonals
		for(n=0;n<4;n++)
		{	//This saves the products of the diagonal products in the rows of r array and makes sure that the row of r[][] and the face of m41 is properly selected
			for(m=0;m<3;m++)
			{		//This makes sure that the rows and columns of m41 are properly selected
				r[n][0] = r[n][0] * m41[n][m][m];	
				r[n][1] = r[n][1] * m41[n][m][m+1];
				r[n][2] = r[n][2] * m41[n][m][m+2];
				r[n][3] = r[n][3] * m41[n][m][4-m];
				r[n][4] = r[n][4] * m41[n][m][3-m];
				r[n][5] = r[n][5] * m41[n][m][2-m];
				
			}
		}
		//This for loop gets the difference of the sum of products of the increasing and decreasing diagonals.
		for(m=0;m<4;m++)
		{	//Makes sure that the elements of j and the row of r are properly selected
			j[m] = ((r[m][0] + r[m][1] + r[m][2]) - (r[m][3] + r[m][4] + r[m][5]));
		}

		//The deerminant is done by getting the products of the element of the original matrix selected to the determinant of the submatrix formed and then getting the sum of its products but the 2nd and 4th terms are multiplied to negative one (-1)
		det = ((at1[0][0]*j[0])-(at1[0][1]*j[1])+(at1[0][2]*j[2])-(at1[0][3]*j[3]));
		break;

		case 5:	// Case 5 where the input matrix is a 5x5 Matrix
		//Transforming the 5x5 matrix into 5 4x4 matrix
		for(m=0;m<5;m++)
		{	//This makes sure that the face of m51 is properly selected
			for(n=0;n<4;n++)
			{	//This makes sure that the row of m51 and at1 is properly selected
				for(o=0;o<4;o++)
				{	//This makes sure that the column of m51 and at1 is properly selected
					switch(m)
					{	//This switch-case statement organizes the program so that the code for computing the resulting 4x4 submatrix of the original 5x5 matrix is done correctly
						//m51[x][][] = the sub matrix formed by selecting at1[0][x] where x is from 0 to 4 so there will be 5 4x4 matrices
						case 0:	//For the 1st face of the m51 matrix
						m51[m][n][o] = at1[n+1][o+1];
						break;
						case 1: //For the 2nd face of the m51 matrix
						if(o == 0)
						{	//This makes sure that the value of m51 if o is equal to zero is the element below at1[n][o]
							m51[m][n][o] = at1[n+1][o];
						}
						else
						{	//If o is not equal to zero then the value of m51 is the element below at1[n+1][o]
							m51[m][n][o] = at1[n+1][o+1];
						}
						break;	
						case 2:	//For the 3rd face of the m51 matrix
						if(o < 2)
						{	//This makes sure that the elements do not enter the values in which the column is in index 2 of at1
							m51[m][n][o] = at1[n+1][o];
						}
						else
						{ //If o is equal to 2, the program will adjust the column by 1 to get the value
							m51[m][n][o] = at1[n+1][o+1];
						}
						break;
						case 3:	//For the 4th face of the m51 matrix
						if(o < 3)
						{	//This makes sure that the values before column 3 is adjusted by moving one row below but the column remains unchanged
							m51[m][n][o] = at1[n+1][o];
						}
						else
						{	//If o is greater than or equal to 3, then the same thing will happen but the column will move to the next
							m51[m][n][o] = at1[n+1][o+1];
						}
						break;	
						case 4:	//For the 5th face of the m51 matrix
						m51[m][n][o] = at1[n+1][o]; 
						break;
					}
					
				}
			}
		}
		
		for(z=0;z<5;z++)
		{	//This makes sure that the face of m51 after the assignment operator is properly selected
			switch(z)
			{	//This switch-case statement gets the 3x3 matrices of each of the 5 4x4 matrices. So the total 3x3 matrices that will be formed would be 25 3x3 matrices
				case 0:	//The matrix m51_0 face 0-3 is equal to the sub matrices formed by the 1st face of the m51 matrix
				//Transforming the 1st 4x4 matrix into 4 3x3 matrix
				//This part of the code is just the same as the code above in getting the 3x3 submatrix based on a 4x4 matrix
				for(m=1,o=0;o<3;m++,o++)
				{	//Makes sure that the row of m51 before and after the assignment operator is properly selected
					for(n=1,p=0;p<3;n++,p++)
					{	// This makes sure that the column of m51 is properly selected
						m51_0[0][o][p] =  m51[z][m][n];
						m51_0[3][o][p] = m51[z][m][p];
						if(p != 1)
						{//This just makes sure that the proper assignment of m51 is done when the column is not equal to 1
							if(p!=2)
							{	//If p is not equal to 2 the normal assignment applies
								m51_0[1][o][p] = m51[z][m][p];
							}
							else
							{	//But if p is equal to 2, then the code will set the column 3 of m51[z][m][] to be the value of the new matrix
								m51_0[1][o][p] = m51[z][m][3];
							}
						}
						if(p != 2)
						{	//If p is not equal to 2, then the following normal assignment applies
							m51_0[2][o][p] = m51[z][m][p];
						}
						if(p == 1)
						{	//But if p is equal to 1, then the column 2 of m51 will be assigned to the face 1 of the column 1 of m51_0
							m51_0[1][o][1] = m51[z][m][2];
							
						}
						if(p == 2)
						{	//But if p is equal to 1, then the column 3 of m51 will be assigned to the face 2 of the column 2 of m51_0
							m51_0[2][o][2] = m51[z][m][3];
						}
					}
				}
				break;
				case 1:		//The matrix m51_0 face 4-7 is equal to the sub matrices formed by the 2nd face of the m51 matrix
				///Transforming the 2nd 4x4 matrix into 4 3x3 matrix
				for(m=1,o=0;o<3;m++,o++)
				{	//This makes sure that the row of m51 and m51_0 are properly selected
					for(n=1,p=0;p<3;n++,p++)
					{	//This makes sure that the column of m51 and m51_0 are properly selected
						m51_0[4][o][p] =  m51[z][m][n];
						m51_0[7][o][p] = m51[z][m][p];
						if(p != 1)
						{	//This just makes sure that the proper assignment of m51 is done when the column is not equal to 1
							if(p!=2)
							{	//If p is not equal to 2 the normal assignment applies
								m51_0[5][o][p] = m51[z][m][p];
							}
							else
							{	//But if p is equal to 2, then the code will set the column 3 of m51[z][m][] to be the value of the new matrix
								m51_0[5][o][p] = m51[z][m][3];
							}
						}
						if(p != 2)
						{	//If p is not equal to 2, then the following normal assignment applies
							m51_0[6][o][p] = m51[z][m][p];
						}
						if(p == 1)
						{	//But if p is equal to 1, then the column 2 of m51 will be assigned to the face 5 of the column 1 of m51_0
							m51_0[5][o][1] = m51[z][m][2];
							
						}
						if(p == 2)
						{	//But if p is equal to 1, then the column 3 of m51 will be assigned to the face 6 of the column 2 of m51_0
							m51_0[6][o][2] = m51[z][m][3];
						}
					}
				}
				break;
				case 2:	//The matrix m51_0 face 8-11 is equal to the sub matrices formed by the 3rd face of the m51 matrix
				///Transforming the 3rd 4x4 matrix into 4 3x3 matrix
				for(m=1,o=0;o<3;m++,o++)
				{	//This makes sure that the row of m51 and m51_0 are properly selected
					for(n=1,p=0;p<3;n++,p++)
					{	//This makes sure that the column of m51 and m51_0 are properly selected
						m51_0[8][o][p] =  m51[z][m][n];
						m51_0[11][o][p] = m51[z][m][p];
						if(p != 1)
						{	//This just makes sure that the proper assignment of m51 is done when the column is not equal to 1
							if(p!=2)
							{	//If p is not equal to 2 the normal assignment applies
								m51_0[9][o][p] = m51[z][m][p];
							}
							else
							{	//But if p is equal to 2, then the code will set the column 3 of m51[z][m][] to be the value of the new matrix
								m51_0[9][o][p] = m51[z][m][3];
							}
						}
						if(p != 2)
						{	//If p is not equal to 2, then the following normal assignment applies
							m51_0[10][o][p] = m51[z][m][p];
						}
						if(p == 1)
						{		//But if p is equal to 1, then the column 2 of m51 will be assigned to the face 9 of the column 1 of m51_0
							m51_0[9][o][1] = m51[z][m][2];
							
						}
						if(p == 2)
						{	//But if p is equal to 1, then the column 3 of m51 will be assigned to the face 10 of the column 2 of m51_0
							m51_0[10][o][2] = m51[z][m][3];
						}
					}
				}
				break;
				case 3:	//The matrix m51_0 face 12-15 is equal to the sub matrices formed by the 4th face of the m51 matrix
					///Transforming the 4th 4x4 matrix into 4 3x3 matrix
				for(m=1,o=0;o<3;m++,o++)
				{		//This makes sure that the row of m51 and m51_0 are properly selected
					for(n=1,p=0;p<3;n++,p++)
					{	//This makes sure that the column of m51 and m51_0 are properly selected
						m51_0[12][o][p] =  m51[z][m][n];
						m51_0[15][o][p] = m51[z][m][p];
						if(p != 1)
						{	//This just makes sure that the proper assignment of m51 is done when the column is not equal to 1
							if(p!=2)
							{	//If p is not equal to 2 the normal assignment applies
								m51_0[13][o][p] = m51[z][m][p];
							}
							else
							{	//But if p is equal to 2, then the code will set the column 3 of m51[z][m][] to be the value of the new matrix
								m51_0[13][o][p] = m51[z][m][3];
							}
						}
						if(p != 2)
						{	//If p is not equal to 2, then the following normal assignment applies
							m51_0[14][o][p] = m51[z][m][p];
						}
						if(p == 1)
						{		//But if p is equal to 1, then the column 2 of m51 will be assigned to the face 13 of the column 1 of m51_0
							m51_0[13][o][1] = m51[z][m][2];
							
						}
						if(p == 2)
						{	//But if p is equal to 1, then the column 3 of m51 will be assigned to the face 14 of the column 2 of m51_0
							m51_0[14][o][2] = m51[z][m][3];
						}
					}
				}
				break;
				case 4:	//The matrix m51_0 face 16-19 is equal to the sub matrices formed by the 5th face of the m51 matrix
					///Transforming the 5th 4x4 matrix into 4 3x3 matrix
				for(m=1,o=0;o<3;m++,o++)
				{		//This makes sure that the row of m51 and m51_0 are properly selected
					for(n=1,p=0;p<3;n++,p++)
					{	//This makes sure that the column of m51 and m51_0 are properly selected
						m51_0[16][o][p] =  m51[z][m][n];
						m51_0[19][o][p] = m51[z][m][p];
						if(p != 1)
						{	//This just makes sure that the proper assignment of m51 is done when the column is not equal to 1
							if(p!=2)
							{	//If p is not equal to 2 the normal assignment applies
								m51_0[17][o][p] = m51[z][m][p];
							}
							else
							{	//But if p is equal to 2, then the code will set the column 3 of m51[z][m][] to be the value of the new matrix
								m51_0[17][o][p] = m51[z][m][3];
							}
						}
						if(p != 2)
						{	//If p is not equal to 2, then the following normal assignment applies
							m51_0[18][o][p] = m51[z][m][p];
						}
						if(p == 1)
						{		//But if p is equal to 1, then the column 2 of m51 will be assigned to the face 17 of the column 1 of m51_0
							m51_0[17][o][1] = m51[z][m][2];
							
						}
						if(p == 2)
						{	//But if p is equal to 1, then the column 3 of m51 will be assigned to the face 18 of the column 2 of m51_0
							m51_0[18][o][2] = m51[z][m][3];
						}
					}
				}
				break;
				
			}
			
			
		}
		
		//Copying the 1st two columns and placing it to the 4th and 5th column so that the program can do the basket-weave method
		for(o=0;o<20;o++)
		{	//This makes sure that the face of m51_0 is properly selected
			for(n=3, m=0;n<5 && m < 2;n++, m++)
				{	//This makes sure that the column of m51_0 before and after the assignment operator is properly selected
					m51_0[o][0][n]= m51_0[o][0][m];
					m51_0[o][1][n] = m51_0[o][1][m];
					m51_0[o][2][n] = m51_0[o][2][m];
				}
		}
		
		
		
		//gets the diagonal products of the formed 3x5 matrices
		for(n=0;n<20;n++)
		{	//This makes sure that the rows of r_0 and the face of m51_0 are properly selected
			for(m=0;m<3;m++)
			{	//This makes sure that the column and row of m51_0 are properly selected
				r_0[n][0] = r_0[n][0] * m51_0[n][m][m];
				r_0[n][1] = r_0[n][1] * m51_0[n][m][m+1];
				r_0[n][2] = r_0[n][2] * m51_0[n][m][m+2];
				r_0[n][3] = r_0[n][3] * m51_0[n][m][4-m];
				r_0[n][4] = r_0[n][4] * m51_0[n][m][3-m];
				r_0[n][5] = r_0[n][5] * m51_0[n][m][2-m];
				
			}
		}
		
		//Gets the difference of the sum of the increasing diagonal products and the decreasing diagonal products
		for(m=0;m<20;m++)
		{	//This makes sure that the element so f j_0 and the rows of r_0 are properly selected
			j_0[m] = ((r_0[m][0] + r_0[m][1] + r_0[m][2]) - (r_0[m][3] + r_0[m][4] + r_0[m][5]));
		}
		//Gets the determinant of the 5 4x4 matrices; The for loop multiplies the element selected to the determinant of the formed submatrices of the selected element
		for(m=0;m<5;m++)
		{	//This makes sure that the element of det_temp is properly selected
			switch(m)
			{	//This switch case just goes through with getting the operation case by case
				case 0:
				det_temp[m] = ((m51[m][0][0]*j_0[0]) - (m51[m][0][1]*j_0[1]) + (m51[m][0][2]*j_0[2]) - (m51[m][0][3]*j_0[3]));
				break;
				case 1:
				det_temp[m] = ((m51[m][0][0]*j_0[4]) - (m51[m][0][1]*j_0[5]) + (m51[m][0][2]*j_0[6]) - (m51[m][0][3]*j_0[7]));
				break;
				case 2:
				det_temp[m] = ((m51[m][0][0]*j_0[8]) - (m51[m][0][1]*j_0[9]) + (m51[m][0][2]*j_0[10]) - (m51[m][0][3]*j_0[11]));
				break;
				case 3:
				det_temp[m] = ((m51[m][0][0]*j_0[12]) - (m51[m][0][1]*j_0[13]) + (m51[m][0][2]*j_0[14]) - (m51[m][0][3]*j_0[15]));
				break;
				case 4:
				det_temp[m] = ((m51[m][0][0]*j_0[16]) - (m51[m][0][1]*j_0[17]) + (m51[m][0][2]*j_0[18]) - (m51[m][0][3]*j_0[19]));
				break;
			}
		}
		//Gets the determinant of the 5x5 matrices by multiplying the determinant of a specific 4x4 matrices to the cell that it is selected
		det = ((at1[0][0]*det_temp[0])-(at1[0][1]*det_temp[1])+(at1[0][2]*det_temp[2])-(at1[0][3]*det_temp[3]) + (at1[0][4]*det_temp[4]));
		break;
		default: // For error printing
		printf("\nError in computing the determinant\n");
		break;
	}
	return det; //returns to int main() the value of det
}





void getQuotient(float dt1[5][5], int i1, float dt2[5][5], int i2, float determinant2)
{
	/*
	  Note:
	  In getting the determinant and quotient of 3x3 matrices,
	  p1 to p6 and q1 to q6 = products of the diagonal of the 3x5 matrix
	  In getting the determinant and quotient of 4x4 matrices (see getDeterminant() function),
	   matrix41[x][x][x] and matrix42[x][x]x[] = 3x5 (5 columns because of copying the 1st two columns of the formed 3x3 matrix and placing it at the 4th and 5th column respectively) matrices formed by the 4x4 matrix by cancelling one row and one column.
	  r[x][x][x] and s[x][x]x[x] = diagonal products (for the basket-weave method) of the 3x5 matrix formed by the 4x4 matrix by cancelling one row and one column.
	  j[x][x] and t[x]x[x] = determinant (using the basket-weave method) of the 3x3 matrix formed by the 4x4 matrix by cancelling one row and one column.
	  *Basically j[x][x] and t[x][x] is equal to the minors of matrix A and matrix B respectively
	*/
	int a,b,c,d= 0; //Variable declaration and initialization
	float s[4][6] = {{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1}};
	float t[4] = {0,0,0,0};
	float m4 [5] [5] [5] =  {{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}};
	float minor[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
	float cofactor[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
	float adjugate[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
	float quotient[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
	float inverse[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
	float m5temp_det[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	float matrix42[4][3][5] = {{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}};
	float matrix52[25][4][4] = {{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}};
	float matrix52_0[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_1[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_2[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_3[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_4[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_5[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_6[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_7[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_8[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_9[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_10[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_11[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_12[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_13[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_14[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_15[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_16[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_17[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_18[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_19[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_20[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_21[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_22[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_23[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	float matrix52_24[5][5] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};;
	
	

	/* This part of codes separates the process of getting the determinant, quotient, minor, cofactor, adjugate, and inverse depending on the size of the square matrix. Also it checks whether the dimensions of the square matrices are equal before proceeding to do the operations.*/
	if(i2 == 2)
	{	//This makes sure that the dimension of the 2nd input matrix is equal to 2 before proceeding 
		//Hardcoding of the minor and cofactors
		minor[0][0] = dt2[1][1];
		minor[0][1] = dt2[1][0];
		minor[1][0] = dt2[0][1];
		minor[1][1] = dt2[0][0];
		
		//This part makes sure that the cofactors will not have an output of "-0.00"
		if(minor[0][1] == 0)
		{	//If the value of minor is 0 then it will not multiply to negative 1
			cofactor[0][1] = minor[0][1];
		}	
		else{	//But if it is not zero, the program will proceed and multiply to negative 1
			cofactor[0][1] = minor[0][1] * -1;
		}
		if(minor[1][0] == 0)
		{	//If the value of minor is 0 then it will not multiply to negative 1
			cofactor[1][0] = minor[1][0];
		}
		else{	//But if it is not zero, the program will proceed and multiply to negative 1
			cofactor[1][0] = minor[1][0] * -1;
		}
		cofactor[1][1] = minor[1][1];
		cofactor[0][0] = minor[0][0];
		
		
		
		
		//Gets the adjugate matrix by transposing the cofactor (I used the transposed code above)
		for(a=0;a<i1;a++)
		{	//Makes sure that the row of adjugate and column of cofactor matrix are properly selected
			for(b=0;b<i2;b++)
			{	//Makes sure that the column of adjugate and the row of cofactor matrix are selected properly
				adjugate[a][b] = cofactor[b][a];
				
					
			}
		}
		
		
		
		//prints out the Adjugate matrix
		printf("\nDisplaying Adjugate of Matrix B: \n");
		for(a=0;a<i2;a++)
		{	//This makes sure that the row of the adjugate matrix is selected properly
			for(b=0;b<i2;b++)
			{	//This makes sure that the column of the adjugate matrix is selected properly
				printf("\t%.2f", adjugate[a][b]);
			}
			printf("\n");
		}
		
		
		
	}
	else if(i2 == 3)
	{	//This makes sure that the dimension of the 2nd input matrix is equal to 3 before proceeding 
		//Hardcoding of the minor of 3x3 matrix
		minor[0][0] = ((dt2[1][1]*dt2[2][2])-(dt2[1][2]*dt2[2][1]));
		minor[0][1] = ((dt2[1][0]*dt2[2][2])-(dt2[1][2]*dt2[2][0]));
		minor[0][2] = ((dt2[1][0]*dt2[2][1])-(dt2[1][1]*dt2[2][0]));
		
		minor[1][0] = ((dt2[0][1]*dt2[2][2])-(dt2[0][2]*dt2[2][1]));
		minor[1][1] = ((dt2[0][0]*dt2[2][2])-(dt2[0][2]*dt2[2][0]));
		minor[1][2] = ((dt2[0][0]*dt2[2][1])-(dt2[0][1]*dt2[2][0]));
		
		minor[2][0] = ((dt2[0][1]*dt2[1][2])-(dt2[0][2]*dt2[1][1]));
		minor[2][1] = ((dt2[0][0]*dt2[1][2])-(dt2[0][2]*dt2[1][0]));
		minor[2][2] = ((dt2[0][0]*dt2[1][1])-(dt2[0][1]*dt2[1][0]));
		
		//This for loop transforms the minor matrix into the cofactor by multiplying negative 1 to the appropriate element
		for(a=0;a<i1;a++)
		{	//This makes sure that the rows of cofactor and minor are properly selected
			for(b=0;b<i2;b++)
			{	//This makes sure that the column of cofactor and minor are properly selected
				if(((a+b) == 1)||((a+b) == 3))
				{	//This makes sure that the elements that the program will multiply to -1 are the ones in the pattern of alternating signs (+-+-+- .... etc)
					if(minor[a][b] == 0)
					{	//If the minor is equal to zero, the program will not multiply to negative one
						cofactor[a][b] = minor[a][b];
					}
					else{	//Else, if it is non zero, then the program will multiply it to negative one
						cofactor[a][b] = minor[a][b] * -1;
					}
					
				}
				else
				{	//If the minor element is supposed to be multiplied to positive one, the program proceeds 
					cofactor[a][b] = minor[a][b];
				}
			}
		}
		
		
		//This for loop transposes the cofactor matrix to get the adjugate matrix
		for(a=0;a<i2;a++)
		{	//This makes sure that the column of cofactor and row of adjugate are properly selected
			for(b=0;b<i2;b++)
			{	//This makes sure that the row of cofactor and column of adjugate are properly selected
				adjugate[a][b] = cofactor [b][a];
				
			}
		}
		

		
		//Prints the adjugate matrix
		printf("\nDisplaying Adjugate of Matrix B: \n");
		for(a=0;a<i2;a++)
		{	//Makes sure that the row of adjugate is properly selected
			for(b=0;b<i2;b++)
			{	//Makes sure that the column of adjugate matrix is properly selected
				printf("\t%.2f", adjugate[a][b]);
			}
			printf("\n");
		}
		
		
		
	}
	else if(i2 == 4)
	{	//This makes sure that the dimension of the 2nd input matrix is equal to 4 before proceeding
	
		//This transforms the 4x4 matrix into a series of 3x3 matrices
		for(a=1,c=0;c<3;a++,c++)
		{	//This makes sure that the row of matrix42 and dt2 are properly selected
			for(b=1,d=0;d<3;b++,d++)
			{	//This makes sure that the column of matrix42 and dt2 are properly selected 
				matrix42[0][c][d] =  dt2[a][b];
				matrix42[3][c][d] = dt2[a][d];
				if(d != 1)
				{	//If d is not equal to 1, then the program checks if it is not equal to 2
					if(d!=2)
					{	//If d is not equal to 2, normal assignment applies
						matrix42[1][c][d] = dt2[a][d];
					}
					else
					{	//If d is equal to 2, the  the column 3 of dt2 is assigned to the matrix42
						matrix42[1][c][d] = dt2[a][3];
					}
				}
				if(d != 2)
				{	//If d is equal to 2, then normal assignment apply
					matrix42[2][c][d] = dt2[a][d];
				}
				if(d == 1)
				{	//If d is equal to 1, then the column 2 of dt2 is assigned to the face 1 of matrix42 column 1
					matrix42[1][c][1] = dt2[a][2];
					
				}
				if(d == 2)
				{	//If d is equal to 2, the column 3 of dt2 is assigned to the face 2 of matrix42 column 2
					matrix42[2][c][2] = dt2[a][3];
				}
			}
		}
		
		//This copies the 1st and the 2nd columns of the 3x3 matrix are placed to the 4th and 5th columns, making a 3x5 matrix
		for(c=0;c<4;c++)
		{	//This makes sure that the face of matrix 4 is properly selected
			for(b=3, a=0;b<5 && a < 2;b++, a++)
				{	//This makes sure that the column of matrix42 before and after the assignment operator is properly selected
					matrix42[c][0][b] = matrix42[c][0][a];
					matrix42[c][1][b] = matrix42[c][1][a];
					matrix42[c][2][b] = matrix42[c][2][a];
				}
		}



		//This nested for loop gets the product of the diagonals of the 3x5 matrix (basket-weave method)
		for(b=0;b<4;b++)
		{	//This makes sure that the row of s and the face of matrix42 is properly selected
			for(a=0;a<3;a++)
			{	//This makes sure that the row and column of matrix42 are properly selected
				
				s[b][0] = s[b][0] * matrix42[b][a][a];
				s[b][1] = s[b][1] * matrix42[b][a][a+1];
				s[b][2] = s[b][2] * matrix42[b][a][a+2];
				s[b][3] = s[b][3] * matrix42[b][a][4-a];
				s[b][4] = s[b][4] * matrix42[b][a][3-a];
				s[b][5] = s[b][5] * matrix42[b][a][2-a];
			}
		}
		
		
		//This gets the difference of the sums of the products of the diagonals (or the determinant of the submatrix)
		for(a=0;a<4;a++)
		{	//This makes sure that the element of t and the row of s are properly selected
			t[a] = ((s[a][0] + s[a][1] + s[a][2]) - (s[a][3] + s[a][4] + s[a][5]));
		}


		//Assigning the values of the minor matrix
		minor[0][0] = t[0];
		minor[0][1] = t[1];
		minor[0][2] = t[2];
		minor[0][3] = t[3];

		//Hardcoding of the remaining elements of the minor matrix (2nd row)
		minor[1][0] = (dt2[0][1]*((dt2[2][2]*dt2[3][3]) - (dt2[2][3]*dt2[3][2])) - dt2[0][2]*((dt2[2][1]*dt2[3][3]) - (dt2[2][3]*dt2[3][1])) + dt2[0][3]*((dt2[2][1]*dt2[3][2]) - (dt2[2][2]*dt2[3][1])));
		minor[1][1] = (dt2[0][0]*((dt2[2][2]*dt2[3][3]) - (dt2[2][3]*dt2[3][2])) - dt2[0][2]*((dt2[2][0]*dt2[3][3]) - (dt2[2][3]*dt2[3][0])) + dt2[0][3]*((dt2[2][0]*dt2[3][2]) - (dt2[2][2]*dt2[3][0])));
		minor[1][2] = (dt2[0][0]*((dt2[2][1]*dt2[3][3]) - (dt2[2][3]*dt2[3][1])) - dt2[0][1]*((dt2[2][0]*dt2[3][3]) - (dt2[2][3]*dt2[3][0])) + dt2[0][3]*((dt2[2][0]*dt2[3][1]) - (dt2[2][1]*dt2[3][0])));
		minor[1][3] = (dt2[0][0]*((dt2[2][1]*dt2[3][2]) - (dt2[2][2]*dt2[3][1])) - dt2[0][2]*((dt2[2][0]*dt2[3][2]) - (dt2[2][2]*dt2[3][0])) + dt2[0][2]*((dt2[2][0]*dt2[3][1]) - (dt2[2][1]*dt2[3][0])));

		//Hardcoding of the remaining elements of the minor matrix (3rd row)
		minor[2][0] = (dt2[0][1]*((dt2[1][2]*dt2[3][3]) - (dt2[1][3]*dt2[3][2])) - dt2[0][2]*((dt2[1][1]*dt2[3][3]) - (dt2[1][3]*dt2[3][1])) + dt2[0][3]*((dt2[1][1]*dt2[3][2]) - (dt2[1][2]*dt2[3][1])));
		minor[2][1] = (dt2[0][0]*((dt2[1][2]*dt2[3][3]) - (dt2[1][3]*dt2[3][2])) - dt2[0][2]*((dt2[1][0]*dt2[3][3]) - (dt2[1][3]*dt2[3][0])) + dt2[0][3]*((dt2[1][0]*dt2[3][2]) - (dt2[1][2]*dt2[3][0])));
		minor[2][2] = (dt2[0][0]*((dt2[1][1]*dt2[3][3]) - (dt2[1][3]*dt2[3][1])) - dt2[0][1]*((dt2[1][0]*dt2[3][3]) - (dt2[1][3]*dt2[3][0])) + dt2[0][3]*((dt2[1][0]*dt2[3][1]) - (dt2[1][1]*dt2[3][0])));
		minor[2][3] = (dt2[0][0]*((dt2[1][1]*dt2[3][2]) - (dt2[1][2]*dt2[3][1])) - dt2[0][1]*((dt2[1][0]*dt2[3][2]) - (dt2[1][2]*dt2[3][0])) + dt2[0][2]*((dt2[1][0]*dt2[3][1]) - (dt2[1][1]*dt2[3][0])));

		//Hardcoding of the remaining elements of the minor matrix (4th row)
		minor[3][0] = (dt2[0][1]*((dt2[1][2]*dt2[2][3]) - (dt2[1][3]*dt2[2][2])) - dt2[0][2]*((dt2[1][1]*dt2[2][3]) - (dt2[1][3]*dt2[2][1])) + dt2[0][3]*((dt2[1][1]*dt2[2][2]) - (dt2[1][2]*dt2[2][1])));
		minor[3][1] = (dt2[0][0]*((dt2[1][2]*dt2[2][3]) - (dt2[1][3]*dt2[2][2])) - dt2[0][2]*((dt2[1][0]*dt2[2][3]) - (dt2[1][3]*dt2[2][0])) + dt2[0][3]*((dt2[1][0]*dt2[2][2]) - (dt2[1][2]*dt2[2][0])));
		minor[3][2] = (dt2[0][0]*((dt2[1][1]*dt2[2][3]) - (dt2[1][3]*dt2[2][1])) - dt2[0][1]*((dt2[1][0]*dt2[2][3]) - (dt2[1][3]*dt2[2][0])) + dt2[0][3]*((dt2[1][0]*dt2[2][1]) - (dt2[1][1]*dt2[2][0])));
		minor[3][3] = (dt2[0][0]*((dt2[1][1]*dt2[2][2]) - (dt2[1][2]*dt2[2][1])) - dt2[0][1]*((dt2[1][0]*dt2[2][2]) - (dt2[1][2]*dt2[2][0])) + dt2[0][2]*((dt2[1][0]*dt2[2][1]) - (dt2[1][1]*dt2[2][0])));

		//This gets the cofactor matrix by multilpying the element to negative 1 if the sum of the row and column are odd number
		for(a=0;a<i2;a++)
			{	//This makes sure that the rows of cminor and cofactor are properly selected
				for(b=0;b<i2;b++)
				{	//This makes sure that the columns of minor and cofactor are properly selected
					switch(a+b)
					{	//Switch-case that determines if the sum of the row and column are odd number
						case 1:
						case 3:
						case 5:
						if(minor[a][b] == 0)
						{	//Checks if the element of minor is zero, if it is, the program will not multiply zero to negative one
							cofactor[a][b] = minor[a][b];
						}
						else{	//Otherwise, the element will be multiplied to negative one
							cofactor[a][b] = minor[a][b] * -1;
						}
						break;
						default: //If the sum of the row and column are not odd, normal assignment applies
						cofactor[a][b] = minor[a][b];
						break;
					}
				}
			}
			


		//Gets the adjugate matrix by transposing the cofactor matrix
		for(a=0;a<i2;a++)
		{	//Makes sure that therow of adjugate and column of cofactor are selected properly
			for(b=0;b<i2;b++)
			{	//Makes sure that the column of adjugate and the row of cofactor are selected properly
				adjugate[a][b] = cofactor[b][a];
				
					
			}
		}
			

	
		//Prints the adjugate matrix
		printf("Displaying Adjugate of Matrix B: \n");
		for(a=0;a<i2;a++)
		{	//Makes sure that the row of the adjugate is properly selected
			for(b=0;b<i2;b++)
			{	//Makes sure that the column of the adjugate is properly selected
				printf("\t%.2f", adjugate[a][b]);
			}
			printf("\n");
		}
		
	}
	else if(i2 == 5)
	{	//This makes sure that the dimension of the 2nd input matrix is equal to 5 before proceeding 
		//Transforming the 5x5 matrix into 25 4x4 matrices
		//To simplify commenting, the process for getting the 4x4 matrices are the same for every 5 face.
		//Face 0-4 (1st row of 5x5 matrix), Face 5-9 (2nd row of 5x5 matrix), Face 10-14 (3rd row of 5x5 matrix), Face 15-19 (4th row of 5x5 matrix), Face 20-24 (5th row of 5x5 matrix)
		for(a=0;a<25;a++)
		{	//This makes sure that the face of matrix52 are properly selected
			for(b=0;b<4;b++)
			{	//This makes sure that the row  of matrix52 and dt2 are properly selected
				for(c=0;c<4;c++)
				{	//This makes sure that the column of matrix52 and dt2 are properly selected	
					switch(a)
					{
						//Case 0 to 4 indicates the 4x4 matrices formed by the 1st row of the input 5x5 matrix
						//For simpler commenting, the assumption is that the process of getting the 4x4 matrices are the same for each 5 sets of faces.
						//The only difference are in the if statements where the comparisons are change depending on which row of the matrix is currently analyzing. (see the comment where it is explained what is the corresponding row of the sets of matrices)
						case 0:
						matrix52[a][b][c] = dt2[b+1][c+1];
						break;
						case 1:
						if(c == 0)
						{	//If the c is zero, then the value assigned to matrix52 is dt2 but a row below.
							matrix52[a][b][c] = dt2[b+1][c];
						}
						else
						{	//Otherwise, the program will also add the column index another unit
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 2:
						if(c < 2)
						{	//If c is less than 2, then the column index will not add 1
							matrix52[a][b][c] = dt2[b+1][c];
						}
						else
						{	//Otherwise, it will add another 1 to the column index
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 3:
						if(c < 3)
						{	//If c s less than 3, then the column index will not be added to 1
							matrix52[a][b][c] = dt2[b+1][c];
						}
						else
						{	//otherwise it will be added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 4:
						matrix52[a][b][c] = dt2[b+1][c];
						break;
						
						
						//Case 5 to 9 indicates the 4x4 matrices formed by the 2nd row of the input 5x5 matrix
						//Cases 5-19 are similar and the only difference are the if statements comparisons.
						case 5:
						if(b < 1)
						{	//If b is less than 1 then dt2 row will not be added to a 1
							matrix52[a][b][c] = dt2[b][c+1];
						}
						else{	//Else the row of dt2 will be added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 6:
						if (c < 1 && b < 1)
						{	//if c is less than 1 and b is less than 1, normal assignment applies
							matrix52[a][b][c] = dt2[b][c];
						}
						if(c<1 && b >=1)
						{		//if c is less than 1 and b is greater than or equal to 1, row of dt2 will be added to a 1
							matrix52[a][b][c] = dt2[b+1][c];
						}
						if (c >= 1 && b < 1){
								//if c is greater than or equal to 1 and b is less than 1, the column of dt2 will be added to a 1
							matrix52[a][b][c] = dt2[b][c+1];
						}
						if (c >= 1 && b > 1)
						{		//if c is greater than or equal to 1 and b is greater than 1, the row and column of dt2 will be added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						if(c > 0 && b == 1)
						{		//if c is greater than 0 and b is equal 1, row and column of dt2 is added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 7:
						if (c < 2 && b < 1)
						{	//if c is less than 2 and b is less than 1, normal assignment applies
							matrix52[a][b][c] = dt2[b][c];
						}
						if(c<2 && b >=1)
						{	//if c is less than 2 and b is greater than or equal to 1, row of dt2 will be added to a 1
							matrix52[a][b][c] = dt2[b+1][c];
						}
						if (c >= 2 && b < 1)
						{	//if c is greater than or equal to 2 and b is less than 1, the column of dt2 will be added to a 1
							matrix52[a][b][c] = dt2[b][c+1];
						}
						if (c >= 2 && b > 1)
						{	//if c is greater than or equal to 2 and b is greater than 1, the row and column of dt2 will be added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						if(c > 1 && b == 1)
						{	//if c is greater than 1 and b is equal 1, row and column of dt2 is added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 8:
						if (c < 3 && b < 1)
						{	//if c is less than 3 and b is less than 1, normal assignment applies
							matrix52[a][b][c] = dt2[b][c];
						}
						if(c<3 && b >=1)
						{	//if c is less than 3 and b is greater than or equal to 1, row of dt2 will be added to a 1
							matrix52[a][b][c] = dt2[b+1][c];
						}
						if (c >= 3 && b < 1){	//if c is greater than or equal to 3 and b is less than 1, the column of dt2 will be added to a 1
							matrix52[a][b][c] = dt2[b][c+1];
						}
						if (c >= 3 && b > 1)
						{	//if c is greater than or equal to 3 and b is greater than 1, the row and column of dt2 will be added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						if(c > 2 && b == 1)
						{	//if c is greater than 2 and b is equal 1, row and column of dt2 is added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 9:
						if (c < 4 && b < 1)
						{	//if c is less than 4 and b is less than 1, normal assignment applies
							matrix52[a][b][c] = dt2[b][c];
						}
						if(c<4 && b >=1)
						{	//if c is less than 4 and b is greater than or equal to 1, row of dt2 will be added to a 1
							matrix52[a][b][c] = dt2[b+1][c];
						}
						if (c >= 4 && b < 1){	//if c is greater than or equal to 4 and b is less than 1, the column of dt2 will be added to a 1
							matrix52[a][b][c] = dt2[b][c+1];
						}
						if (c >= 4 && b > 1)
						{	//if c is greater than or equal to 4 and b is greater than 1, the row and column of dt2 will be added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						if(c > 3 && b == 1)
						{	//if c is greater than 3 and b is equal 1, row and column of dt2 is added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						
						
						
						
						//Case 10 to 14 indicates the 4x4 matrices formed by the 3rd row of the input 5x5 matrix
						case 10:
						if(b < 2)
						{		//If b is less than 2, then the row index will not add 1
							matrix52[a][b][c] = dt2[b][c+1];
						}
						else{	//Else the row of dt2 will be added to a 1

							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 11:
						if (c < 1 && b < 2)
						{	//if c is less than 1 and b is less than 2, normal assignment applies
							matrix52[a][b][c] = dt2[b][c];
						}
						if(c<1 && b >=2)
						{	//if c is less than 1 and b is greater than or equal to 2, row of dt2 will be added to a 1
							matrix52[a][b][c] = dt2[b+1][c];
						}
						if (c >= 1&& b < 2){//if c is greater than or equal to 1 and b is less than 2, the column of dt2 will be added to a 1
							matrix52[a][b][c] = dt2[b][c+1];
						}
						if (c >= 1 && b > 2)
						{	//if c is greater than or equal to 1 and b is less than 2, the column of dt2 will be added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						if(c > 0 && b == 2)
						{	//if c is greater than 0 and b is equal 2, row and column of dt2 is added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 12:
						if (c < 2 && b < 2)
						{	//if c is less than 2 and b is less than 2, normal assignment applies
							matrix52[a][b][c] = dt2[b][c];
						}
						if(c<2 && b >=2)
						{	
							matrix52[a][b][c] = dt2[b+1][c];
						}
						if (c >= 2 && b < 2){	//if c is greater than or equal to 2 and b is less than 2, the column of dt2 will be added to a 1

							matrix52[a][b][c] = dt2[b][c+1];
						}
						if (c >= 2 && b > 2)
						{
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						if(c > 1 && b == 2)
						{	//if c is greater than 1 and b is equal 2, row and column of dt2 is added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 13:
						if (c < 3 && b < 2)
						{	//if c is less than 3 and b is less than 2, normal assignment applies
							matrix52[a][b][c] = dt2[b][c];
						}
						if(c<3 && b >=2)
						{
							matrix52[a][b][c] = dt2[b+1][c];
						}
						if (c >= 3 && b < 2){
							matrix52[a][b][c] = dt2[b][c+1];
						}
						if (c >= 3 && b > 2)
						{
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						if(c > 2 && b == 2)
						{	//if c is greater than 2 and b is equal 2, row and column of dt2 is added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 14:
						if (c < 4 && b < 2)
						{	//if c is less than 4 and b is less than 2, normal assignment applies
							matrix52[a][b][c] = dt2[b][c];
						}
						if(c<4 && b >=2)
						{
							matrix52[a][b][c] = dt2[b+1][c];
						}
						if (c >= 4 && b < 2){
							matrix52[a][b][c] = dt2[b][c+1];
						}
						if (c >= 4 && b > 2)
						{
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						if(c > 3 && b == 2)
						{	//if c is greater than 3 and b is equal 2, row and column of dt2 is added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						
						
						
						
						//Case 15 to 19 indicates the 4x4 matrices formed by the 4th row of the input 5x5 matrix
						case 15:
						if(b < 3)
						{	//If b is less than 3, then the column index will not add 1
							matrix52[a][b][c] = dt2[b][c+1];
						}
						else{
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 16:
						if (c < 1 && b < 3)
						{
							matrix52[a][b][c] = dt2[b][c];
						}
						if(c<1 && b >=3)
						{
							matrix52[a][b][c] = dt2[b+1][c];
						}
						if (c >= 1&& b < 3){
							matrix52[a][b][c] = dt2[b][c+1];
						}
						if (c >= 1 && b > 3)
						{
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						if(c > 0 && b == 3)
						{	//if c is greater than 0 and b is equal 3, row and column of dt2 is added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 17:
						if (c < 2 && b < 3)
						{	//if c is less than 2 and b is less than 3, normal assignment applies
							matrix52[a][b][c] = dt2[b][c];
						}
						if(c<2 && b >=3)
						{
							matrix52[a][b][c] = dt2[b+1][c];
						}
						if (c >= 2 && b < 3){
							matrix52[a][b][c] = dt2[b][c+1];
						}
						if (c >= 2 && b > 3)
						{
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						if(c > 1 && b == 3)
						{	//if c is greater than 1 and b is equal 3, row and column of dt2 is added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 18:
						if (c < 3 && b < 3)
						{	//if c is less than 3 and b is less than 3, normal assignment applies
							matrix52[a][b][c] = dt2[b][c];
						}
						if(c<3 && b >=3)
						{
							matrix52[a][b][c] = dt2[b+1][c];
						}
						if (c >= 3 && b < 3){
							matrix52[a][b][c] = dt2[b][c+1];
						}
						if (c >= 3 && b > 3)
						{
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						if(c > 2 && b == 3)
						{	//if c is greater than 2 and b is equal 3, row and column of dt2 is added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 19:
						if (c < 4 && b < 3)
						{	//if c is less than 4 and b is less than 3, normal assignment applies
							matrix52[a][b][c] = dt2[b][c];
						}
						if(c<4 && b >=3)
						{
							matrix52[a][b][c] = dt2[b+1][c];
						}
						if (c >= 4 && b < 3){
							matrix52[a][b][c] = dt2[b][c+1];
						}
						if (c >= 4 && b > 3)
						{
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						if(c > 3 && b == 3)
						{	//if c is greater than 3 and b is equal 3, row and column of dt2 is added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						
						
						
						
						//Case 20 to 24 indicates the 4x4 matrices formed by the 5th row of the 5x5 matrix row of the input 5x5 matrix
						case 20:
						if(b < 4)
						{	//If b is less than 4, then the column index will not add 1
							matrix52[a][b][c] = dt2[b][c+1];
						}
						else{
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 21:
						if (c < 1 && b < 4)
						{	//if c is less than 1 and b is less than 4, normal assignment applies
							matrix52[a][b][c] = dt2[b][c];
						}
						if(c<1 && b >=4)
						{
							matrix52[a][b][c] = dt2[b+1][c];
						}
						if (c >= 1&& b < 4){
							matrix52[a][b][c] = dt2[b][c+1];
						}
						if (c >= 1 && b > 4)
						{
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						if(c > 0 && b == 4)
						{	//if c is greater than 0 and b is equal 4, row and column of dt2 is added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 22:
						if (c < 2 && b < 4)
						{	//if c is less than 2 and b is less than 4, normal assignment applies
							matrix52[a][b][c] = dt2[b][c];
						}
						if(c<2 && b >=4)
						{
							matrix52[a][b][c] = dt2[b+1][c];
						}
						if (c >= 2 && b < 4){
							matrix52[a][b][c] = dt2[b][c+1];
						}
						if (c >= 2 && b > 4)
						{
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						if(c > 1 && b == 4)
						{//if c is greater than 1 and b is equal 4, row and column of dt2 is added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 23:
						if (c < 3 && b < 4)
						{	//if c is less than 3 and b is less than 4, normal assignment applies
							matrix52[a][b][c] = dt2[b][c];
						}
						if(c<3 && b >=4)
						{
							matrix52[a][b][c] = dt2[b+1][c];
						}
						if (c >= 3 && b < 4){
							matrix52[a][b][c] = dt2[b][c+1];
						}
						if (c >= 3 && b > 4)
						{
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						if(c > 2 && b == 4)
						{	//if c is greater than 2 and b is equal 4, row and column of dt2 is added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
						case 24:
						if (c < 4 && b < 4)
						{	//if c is less than 4 and b is less than 4, normal assignment applies
							matrix52[a][b][c] = dt2[b][c];
						}
						if(c<4 && b >=4)
						{
							matrix52[a][b][c] = dt2[b+1][c];
						}
						if (c >= 4 && b < 4){
							matrix52[a][b][c] = dt2[b][c+1];
						}
						if (c >= 4 && b > 4)
						{
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						if(c > 3 && b == 4)
						{	//if c is greater than 3 and b is equal 4, row and column of dt2 is added to a 1
							matrix52[a][b][c] = dt2[b+1][c+1];
						}
						break;
					}
					
				}
			}
		}
		
		/* This nested for loop transfers each face of the 3-D matrix into 25 4x4 matrices so that the code can use the function getDeterminant(); to get the determinant of each 4x4 matrices for easy programming*/
		
		for(a=0;a<4;a++)
		{	//This makes sure that the row of matrix52_0 and matrix52 are properly selected
			for(b=0;b<4;b++)
			{	//This makes sure that the column of matrix52_0 and matrix52 are properly selected
				matrix52_0[a][b] = matrix52[0][a][b];
				matrix52_1[a][b] = matrix52[1][a][b];
				matrix52_2[a][b] = matrix52[2][a][b];
				matrix52_3[a][b] = matrix52[3][a][b];
				matrix52_4[a][b] = matrix52[4][a][b];
				matrix52_5[a][b] = matrix52[5][a][b];
				matrix52_6[a][b] = matrix52[6][a][b];
				matrix52_7[a][b] = matrix52[7][a][b];
				matrix52_8[a][b] = matrix52[8][a][b];
				matrix52_9[a][b] = matrix52[9][a][b];
				matrix52_10[a][b] = matrix52[10][a][b];
				matrix52_11[a][b] = matrix52[11][a][b];
				matrix52_12[a][b] = matrix52[12][a][b];
				matrix52_13[a][b] = matrix52[13][a][b];
				matrix52_14[a][b] = matrix52[14][a][b];
				matrix52_15[a][b] = matrix52[15][a][b];
				matrix52_16[a][b] = matrix52[16][a][b];
				matrix52_17[a][b] = matrix52[17][a][b];
				matrix52_18[a][b] = matrix52[18][a][b];
				matrix52_19[a][b] = matrix52[19][a][b];
				matrix52_20[a][b] = matrix52[20][a][b];
				matrix52_21[a][b] = matrix52[21][a][b];
				matrix52_22[a][b] = matrix52[22][a][b];
				matrix52_23[a][b] = matrix52[23][a][b];
				matrix52_24[a][b] = matrix52[24][a][b];
			}
		}
		
		
		//Gets the determinant of each of th 25 4x4 matrices of the input 5x5 matrix by calling the getDeterminant() function
		m5temp_det[0] = getDeterminant(matrix52_0, 4);
		m5temp_det[1] = getDeterminant(matrix52_1, 4);
		m5temp_det[2] = getDeterminant(matrix52_2, 4);
		m5temp_det[3] = getDeterminant(matrix52_3, 4);
		m5temp_det[4] = getDeterminant(matrix52_4, 4);
		m5temp_det[5] = getDeterminant(matrix52_5, 4);
		m5temp_det[6] = getDeterminant(matrix52_6, 4);
		m5temp_det[7] = getDeterminant(matrix52_7, 4);
		m5temp_det[8] = getDeterminant(matrix52_8, 4);
		m5temp_det[9] = getDeterminant(matrix52_9, 4);
		m5temp_det[10] = getDeterminant(matrix52_10, 4);
		m5temp_det[11] = getDeterminant(matrix52_11, 4);
		m5temp_det[12] = getDeterminant(matrix52_12, 4);
		m5temp_det[13] = getDeterminant(matrix52_13, 4);
		m5temp_det[14] = getDeterminant(matrix52_14, 4);
		m5temp_det[15] = getDeterminant(matrix52_15, 4);
		m5temp_det[16] = getDeterminant(matrix52_16, 4);
		m5temp_det[17] = getDeterminant(matrix52_17, 4);
		m5temp_det[18] = getDeterminant(matrix52_18, 4);
		m5temp_det[19] = getDeterminant(matrix52_19, 4);
		m5temp_det[20] = getDeterminant(matrix52_20, 4);
		m5temp_det[21] = getDeterminant(matrix52_21, 4);
		m5temp_det[22] = getDeterminant(matrix52_22, 4);
		m5temp_det[23] = getDeterminant(matrix52_23, 4);
		m5temp_det[24] = getDeterminant(matrix52_24, 4);
		
		//Gets the minor matrix of the 5x5 by assigning the respective determinant of the 4x4 matrices to the elements of the minor matrix
		for(a=0;a<5;a++)
		{	//This makes sure that the colun of the minor and the element of the m5temp_det matrix are properly selected
			minor[0][a] = m5temp_det[a];
			minor[1][a] = m5temp_det[a+5];
			minor[2][a] = m5temp_det[a+10];
			minor[3][a] = m5temp_det[a+15];
			minor[4][a] = m5temp_det[a+20];

		}
		
		//This loop transforms the minor matrix into cofactor matrix by multiplying the element of the minor matrix if the sum of their row and column is an odd number
		for(a=0;a<i1;a++)
		{	//Makes sure that the row of minor and cofactor are properly selected
			for(b=0;b<i2;b++)
			{	//Makes sure that the column of cofactor and minor are properly selected
				switch(a+b)
				{	//if the sum of the row and column is odd, the program will multiply the minor element to negative one
					case 1:
					case 3:
					case 5:
					case 7:
					if(minor[a][b] == 0)
					{	//Checks if the minor element is equal to zero and if it is zero, the program will not multiply it to negative one
						cofactor[a][b] = minor[a][b];
					}
					else{	//Otherwise, it will multiply the minor element to negative one
						cofactor[a][b] = minor[a][b] * -1;
					}
					break;
					default:	//If the sum of the row and column are not odd, normal assignment proceeds
					cofactor[a][b] = minor[a][b];
					break;
				}
			}
		}
		
		
		
		//Gets the adjugate matrix by transposing the cofactor matrix
		for(a=0;a<i2;a++)
		{	//Makes sure that the adjugate row and the cofactor column are properly selected
			for(b=0;b<i2;b++)
			{	//Makes sure that the adjugate column and the cofactro row are properly selected
				adjugate[a][b] = cofactor[b][a];
				
					
			}
		}
		
		//Prints the adjugate matrix
		printf("\nDisplaying Adjugate of Matrix B: \n");
		for(a=0;a<i2;a++)
		{	//makes sure that the row of the adjugate matrix is properly selected
			for(b=0;b<i2;b++)
			{	//Makes sure that the column of the adjugate matrix is properly selected
				printf("\t   %.2f", adjugate[a][b]);
			}
			printf("\n");
		}
		
		
		
		
	}
	if((i1 == 2)&&(i2 == 2))
	{	//This makes sure that the dimensions of matrix A and matrix B are both equal to two (2).
		
		if(determinant2 != 0)
		{	// This makes sure that the determinant of matrix B is not equal to zero before getting the inverse and quotient to prevent getting undefined values.



			//Gets the Inverse matrix by scalar multiplication of the adjugate matrix to the reciprocal of the determinant of matrix B
			for(a=0;a<i2;a++)
			{	//This makes sure that the row of inverse and adjugate are properly selected
				for(b=0;b<i2;b++)
				{	//This makes sure that the  column of inverse and adjugate matrix are properly selected
						inverse[a][b] = (adjugate[a][b] * (1/determinant2));
						
				}
			}
			//Prints the inverse matrix
			printf("\nDisplaying Inverse of Matrix B: \n");
			for(a=0;a<i2;a++)
			{	//This makes sure that the row of the inverse matrix is properly selected
				for(b=0;b<i2;b++)
				{	// This makes sure that the column of the inverse matrix is properly selected
					printf("\t%.2f", inverse[a][b]);
				}
				printf("\n");
			}
			
			
			printf("\nDisplaying Quotient (A / B): \n");
			//gets the matrix quotient of matrix A and matrix B by using matrix multiplication (dot product) of matrix A and the inverse of matrix B. Each face of the 3-D m4 matrix is equal to a row of the quotient matrix so m4[0][][] = 1st row of the quotient matrix
			for(a=0;a<i1;a++)
			{	//This makes sure that the face of m4 and the row of matrix A is properly selected
				for(b=0;b<i2;b++)
				{	// This makes sure that the row of m4 and the column of the inverse of matrix B is properly selected
					for(c=0;c<i2;c++)
					{	//This makes sure that the column of m4 and matrix A and the row of the inverse of matrix B is selected
						m4[a][b][c] = (dt1[a][c] * inverse[c][b]);
					}
				}
			}
			
			//Gets the quotient matrix by adding all of the elements in a row of m4 to get an element of the quotient matrix.
			for(a=0;a<i1;a++)
			{	//This makes sure that the row of quotient and the face of m4 is properly selected 
				for(b=0;b<i2;b++)
				{	//This makes sure that the column of quotient and the row of m4 is properly selected
					for(c=0;c<i2;c++)
					{ // This makes sure that the column of m4 is properly selected
						quotient[a][b] = quotient[a][b] + m4[a][b][c];
					}
				
				}

			}
			//Prints out the quotient matrix
			for(a=0;a<i1;a++)
			{	//This makes sure that the row of quotient matrix is properly selected
				for(b=0;b<i2;b++)
				{	// This makes sure that the column of the quotient matrix is properly selected
					printf("\t%.2f", quotient[a][b]);
				}
				printf("\n");
			}
			
		}
		else
		{ //Prints that getting the quotient is not possible because the determinant of matrix B is zero (undefined values)
			printf("\nQuotient not possible. Determinant of Matrix B is %f\n", determinant2);
		}
	}
	else if((i1 == 3)&&(i2 == 3))
	{	//This makes sure that the dimensions of matrix A and matrix B are both equal to three (3).
		
		
		
		if(determinant2 != 0)
		{	// This makes sure that the determinant of matrix B is not equal to zero before getting the inverse and quotient to prevent getting undefined values.
			
			
			
			
		//Gets the inverse of the matrix by multiplying the adjugate to the reciprocal of the matrix's determinant (scalar multiplication)
		for(a=0;a<i2;a++)
		{	//Makes sure that the inverse row and adjugate row are properly selected
			for(b=0;b<i2;b++)
			{	//Makes sure that the column of inverse and adugate are properly selected
				inverse[a][b] = ((1/determinant2) * adjugate[a][b]);
				
			}
		}
		
		//prints the inverse matrix
		printf("\nDisplaying Inverse of Matrix B: \n");
		for(a=0;a<i2;a++)
		{	//makes sure that the row of the inverse is properly selected
			for(b=0;b<i2;b++)
			{	//Makes sure that the column of the inverse is properly selected
				printf("\t%.2f", inverse[a][b]);
			}
			printf("\n");
		}
		
		
		
		printf("\nDisplaying Quotient (A / B): \n");
		
		
			//gets the elements of the quotient matrix by the dot product of the 1st input matrix and the inverse of the 2nd input matrix
			for(a=0;a<i1;a++)
			{	//Makes sure that the face of m4 and the row of dt1 are properly selected
				for(b=0;b<i2;b++)
				{	//Makes sure that the row of m4 and the column of inverse are properly selected
					for(c=0;c<i2;c++)
					{	//This makes sure that the column of m4, dt1 and the row of inverse are properly selected
						m4[a][b][c] = (dt1[a][c] * inverse[c][b]);
					}
				}
			}
			
			//Gets the quotient matrix by getting the sum of the dot products of each face of the matrix
			for(b=0;b<i2;b++)
			{	//Makes sure that the quotient column and m4 row are properly selected
				for(c=0;c<i2;c++)
				{	//Makes sure that the m4 column are properly selected
					quotient[0][b] = quotient[0][b] + m4[0][b][c];
					quotient[1][b] = quotient[1][b] + m4[1][b][c];
					quotient[2][b] = quotient[2][b] + m4[2][b][c];
				}
				
			}
			
			//Prints out the quotient matrix
			for(a=0;a<i1;a++)
			{	//makes sure that the row of quotient is properly selected
				for(b=0;b<i2;b++)
				{	//Makes sure that the column of quotient is properly selected
					printf("\t%.2f", quotient[a][b]);
				}
				printf("\n");
			}
			
		}
		else
		{	//Prints that getting the quotient is not possible because the determinant of matrix B is zero (undefined values)
			printf("\nQuotient not possible. Determinant of Matrix B is %f\n", determinant2);
		}
		
	}
	else if((i1 == 4)&&(i2 == 4))
	{	//This makes sure that the dimensions of matrix A and matrix B are both equal to four (4).


		if(determinant2 != 0)
		{	// This makes sure that the determinant of matrix B is not equal to zero before getting the inverse and quotient to prevent getting undefined values.
			

			//Gets the inverse by multiplying the adjugate to the reciprocal of the determinant of the 2nd matrix input
			for(a=0;a<i2;a++)
			{	//Makes sure that the row of inverse and adjugate are properly selected
				for(b=0;b<i2;b++)
				{	//makes sure that the column of inverse and adjugate are properly selected
					inverse[a][b] = ((1/determinant2) * adjugate[a][b]);
					
				}
			}
			
			
			//prints the inverse matrix
			printf("Displaying Inverse of Matrix B: \n");
			for(a=0;a<i2;a++)
			{	//makes sure that the row of inverse is properly selected
				for(b=0;b<i2;b++)
				{	//makes sure that the column of inverse is properly selected
					printf("\t%.2f", inverse[a][b]);
				}
				printf("\n");
			}
			
			printf("\nDisplaying Quotient (A / B): \n");
			
			//Gets the quotient matrix by getting the dot product of the 1st matrix input and the inverse matrix (2nd input matrix)
			for(a=0;a<i1;a++)	
			{	//Makes sure that the face of m4 and the row of dt1 are properly selected
				for(b=0;b<i2;b++)
				{	//Makes sure that the row of m4 and the column of inverse are properly selected
					for(c=0;c<i2;c++)
					{	//makes sure that the column of m4 and dt1 and the row of inverse are properly selected
						m4[a][b][c] = (dt1[a][c] * inverse[c][b]);
					}
				}
			}
			
			
			//Gets the quotient matrix elements by getting the sum of each row of the m4 matrix
			for(b=0;b<4;b++)
			{	//Makes sure that the column of quotient and row of m4 are properly selected
				for(c=0;c<4;c++)
				{	//makes sure that the column of m4 are properly selected
					quotient[0][b] = quotient[0][b] + m4[0][b][c];
					quotient[1][b] = quotient[1][b] + m4[1][b][c];
					quotient[2][b] = quotient[2][b] + m4[2][b][c];
					quotient[3][b] = quotient[3][b] + m4[3][b][c];
				}
				
			}


			//Prints out the quotient matrix
			for(a=0;a<i1;a++)
			{	//Makes sure that the row of quotient is properly selected
				for(b=0;b<i2;b++)
				{	//Makes sure that the column of quotient is properly selected
					printf("\t%.2f", quotient[a][b]);
				}
				printf("\n");
			}

		}
		else
		{	//Prints that getting the quotient is not possible because the determinant of matrix B is zero (undefined values)
			printf("\nQuotient not possible. Determinant of Matrix B is %f\n", determinant2);
		}
		
		
	}
	else if((i1 == 5)&&(i2 == 5))
	{	//This makes sure that the dimensions of matrix A and matrix B are both equal to five (5).
		
		if(determinant2 != 0)
		{	// This makes sure that the determinant of matrix B is not equal to zero before getting the inverse and quotient to prevent getting undefined values.
			
			
			
			
			//gets the inverse by multiplying the adjugate to the reciprocal of the 2nd input matrix determinant (scalar multiplication)
			for(a=0;a<i2;a++)
			{	//Makes sure that the row of inverse and adjugate are properly selected
				for(b=0;b<i2;b++)
				{	//Makes sure that the column og inverse and adjugate are properly selected
					inverse[a][b] = ((1/determinant2) * adjugate[a][b]);
				
				}
			}	
			
			
			
			//prints the inverse matrix
			printf("\nDisplaying Inverse of Matrix B: \n");
			for(a=0;a<i2;a++)
			{	//makes sure that the row of inverse is properly selected
				for(b=0;b<i2;b++)
				{	//Makes sure that the column of inverse is properly selected
					printf("\t%.2f", inverse[a][b]);
				}
				printf("\n");
			}
			
			printf("\nDisplaying Quotient (A / B): \n");
		
			//Prints the quotient matrix by getting the dot product of the 1st input matrix and the inverse of the 2nd input matrix 
			//For easier coding, it is done by calling out the function getProduct();
			getProduct(dt1, i1, inverse, i2);
			
			
			
			
		}
		else
		{	//Prints that getting the quotient is not possible because the determinant of matrix B is zero (undefined values)
			printf("\nQuotient not possible. Determinant of Matrix B is %f\n", determinant2);
		}
		
	}
	else
	{	//Prints out that the operation could not proceed because the matrix dimensions of matrix A and matrix B are not equal.
		printf("\nQuotient not possible. Matrix dimensions are not equal. Matrix A has %d x %d dimension and Matrix B has %d x %d dimension.\n", i1, i1, i2, i2);
	}
	
	

}
