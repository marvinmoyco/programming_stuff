/* This program checks if an input string is a palindrome */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	char strng1[21];//Variable declaration
	char strng2[21];
	//char strng3[20];
	int arrSize;
	int n, j;
	printf("Please enter a string (maximum of 20 characters): ");//Gets an input string
	scanf("%s", strng1);
	arrSize = strlen(strng1);//Gets the size of the string
	for(n = 0; n<arrSize; n++)//Converts all the letters in the string into lowercase
	{
		if((strng1[n] >= 'A') && (strng1[n] <= 'Z'))
		{
			strng1[n] = tolower(strng1[n]);
		}
	}
	for(n=0, j=arrSize-1;n<arrSize && j >=0;n++, j--)// Gets the reverse order of the string1
	{
		strng2[j] = strng1[n];
	}
	strng1[arrSize] = '\0';//Sets the terminating null of the string at the end of the arrays
	strng2[arrSize] = '\0';
	int m = 0;
	printf(" \nThe string ");//Prints the input string
	while(m<arrSize){
		printf("%c", strng1[m]);
		m++;
	}
	printf(" is ");
	int checker = 0;
	checker = strcmp(strng1, strng2);//Checks if the string1(original) is equal to string 2(reverse)

	if(checker == 0)// CHecks if the checker is zero, the input string is a palindorme, otherwise it is not
	{

		 printf("a palindrome.\n");


	}
	else{
		printf("not a palindrome.\n");


	}
	/*m = 0;
	printf(" \nThe string1 ");//Prints the input string
	while(m<arrSize){
		printf("%c", strng1[m]);
		m++;
	}
	m = 0;
	printf(" \nThe string2 ");//Prints the input string
	while(m<arrSize){
		printf("%c", strng2[m]);
		m++;
	}*/
	//printf("\nValue of strcmp is %d\n",checker);
	return 0;
}
