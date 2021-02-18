/* This program reverses a string input with the use of pointers*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inverse(char *input); //Function prototype
int main()
{
    char *input = NULL; // Pointer declaration
    int slen =0;    //Variable declaration
    input = (char*) malloc(11); //Dynamically allocating memory to pointer input
    if(input)   //If statement that makes sure the pointer input has memory allocated to it.
    {
        printf("\nPlease enter a string (Maximum of 10 characters): ");//Getting the input
        scanf("%s", input);
        slen = strlen(input); //Gets the string length of the input
        if(slen <= 10)  //Makes sure that the string length would not exceed 10 characters
        {

            inverse(input); //Function call for the inverse function
            printf("\nInverse: %s\n", input);   //Prints the reversed input
        }
        else//Prints that the string length is too long and frees up the dynamically allocated memory for input
        {
            printf("\nString length too long. Enter a string with a maximum length of 10 characters.\n");
            free(input);
        }
        
    }
    else    //Prints that the memory allocation for input failed and frees up any memory allocated to input pointer
    {
        printf("\nMemory Allocation for pointer input failed. Restart the program.\n");
    }
    free(input);
    return 0;
}


void inverse(char *input)   
{
    int i,j= 0; //Variable declaration
    char *temp = NULL;
    temp = (char*) malloc(11);  //Dynamic allocation of memory to temp pointer
    int len = 0;
    len = strlen(input);//Gets the string length of the input pointer

        for(i=0, j=len-1;i<len && j >=0;i++, j--)// Gets the reverse order of the input
        {
            *(temp+j) = *(input+i); //THe last element of the temp pointer is the value of the 1st element of the input pointer
    	   //temp[j] = input[i];
    	}
        for(i=0;i<len;i++)
        {   //Returns the reverse order of string to the input pointer
            *(input+i) = *(temp+i);
           // input[i] = temp[i];
                
        }
        free(temp); //Frees up the dynamically allocated memory for temp pointer
}
