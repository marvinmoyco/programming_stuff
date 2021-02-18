/* This program gets the sum, difference, product, quotient, and modulo of two (2) five elements array */
#include <stdio.h>
int sum(int add1, int add2); // Function Prototypes

int difference(int diff1, int diff2);

int product(int prod1, int prod2);

float quotient(int div1, int div2);

int modulo(int mod1, int mod2);

int main()
{
	int arr1[5];// Variable declarations
	int arr2[5];
	int sum1[5];
	int diff[5];
	int prod[5];
	float quot[5];
	int modu[5];
	int i = 0;
	for(i=0;i<5;i++)//Loop for array input 1
	{
		switch(i){
			case 0:
				printf("Please enter the 1st input: ");
				break;
			case 1:
				printf("Please enter the 2nd input: ");
				break;
			case 2:
				printf("Please enter the 3rd input: ");
				break;
			case 3:
				printf("Please enter the 4th input: ");
				break;
			case 4:
				printf("Please enter the 5th input: ");
			default:
				break;
		}
		scanf(" %d", &arr1[i]);
		//printf("\n");
	}
	for(i=0;i<5;i++)// Loop for array input2
	{
		switch(i){
			case 0:
				printf("Please enter the 1st input: ");
				break;
			case 1:
				printf("Please enter the 2nd input: ");
				break;
			case 2:
				printf("Please enter the 3rd input: ");
				break;
			case 3:
				printf("Please enter the 4th input: ");
				break;
			case 4:
				printf("Please enter the 5th input: ");
			default:
				break;
		}
		scanf(" %d", &arr2[i]);
		//printf("\n");
	}
	int j;
	for( j =0; j<5; j++) //Loop for getting the sum, difference, product, quotient, and modulo for each array inputs
	{
		sum1[j] = sum(arr1[j],arr2[j]);
		diff[j] = difference(arr1[j], arr2[j]);
		prod[j] = product(arr1[j], arr2[j]);
		quot[j] = quotient(arr1[j], arr2[j]);
		modu[j] = modulo(arr1[j], arr2[j]);
	}
	printf("\nArray 1st input: \n");
	i=0;
	while(i<5)// Prints out the array input 1
	{
		printf(" %d", arr1[i]);
		i++;
	}
	printf("\nArray 2nd input: \n");// Prints out the array input 2
	i=0;
	while(i<5)
	{
		printf(" %d", arr2[i]);
		i++;
	}
	i=0;
	printf("\n");
	while(i<5) // Prints out the sum for all of array inputs
	{
		printf("Sum # %d:", i+1);
		printf(" %d ", sum1[i]);
		i++;
	}
	printf("\n");
	i=0;
	while(i<5)//Prints out the difference for all array inputs
	{
		printf("Difference # %d:", i+1);
		printf(" %d ", diff[i]);
		i++;
	}
	printf("\n");
	i=0;
	while(i<5)//Prints out the product for all array inputs
	{
		printf("Product # %d:", i+1);
		printf(" %d ", prod[i]);
		i++;
	}
	printf("\n");
	i=0;
	while(i<5)// Prints out the quotient for all array inputs
	{
		printf("Quotient # %d:", i+1);
		printf(" %f ", quot[i]);
		i++;
	}
	printf("\n");
	i=0;
	while(i<5)//Prints out the remainder for all array inputs
	{
		printf("Modulo # %d:", i+1);
		printf(" %d ", modu[i]);
		i++;
	}
	printf("\n");
	
	return 0;
}


int sum(int add1, int add2)//Sum function
{
	return add1+add2;
}

int difference(int diff1, int diff2)//Difference function
{
	return diff1 - diff2;
}

int product(int prod1, int prod2)//Product function
{
	return prod1*prod2;
}

float quotient(int div1, int div2)//Quotient function
{
	return (float) div1/div2;
}

int modulo(int mod1, int mod2)//Modulo Function
{
	return mod1%mod2;
}
