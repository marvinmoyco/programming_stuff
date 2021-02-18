/*This program gets the frequency of a character in an input string*/
#include <stdio.h>
#include <string.h>
int main()
{
	char arr[50];//Variable declaration
	int freq = 0;
	char checker;
	int size = 0;
	printf("\nPlease enter the string: ");//Input the string
	scanf("%s", arr);
	size = strlen(arr);//Gets the size of a string
	printf("\n");
	printf("Please enter the character: ");//Gets the character element to be checked
	scanf(" %c", &checker);
	int j =0;
	while(j<=size)//Loop that gets how many times the checker element appears in the string
	{

		if(arr[j] == checker)
		{
			freq++;
		}
	j++;
	}
	printf("The size of the string is %d characters.\n", size);//Prints out the size of the string
	printf("The input string is ");
	puts(arr);// Prints out the input string
	printf("\n");
	printf("The checker element is %c\n", checker);//Prints out the checker element
	printf("\nThe frequency of %c in the string is %d\n", checker, freq);// Prints out the frequency of the checker element in the input string


	return 0;
}
