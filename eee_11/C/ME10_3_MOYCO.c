/*This program switches a character on an input string based on the input integer (location of character on string).*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *input = NULL;//Pointer declaration
    input = (char*) malloc(11); //Dynamically allocation of memory to pointer input.
    int strinput = 1;   //Variable declaration
    int len = 0;
    char cinput = 0;
    if(input)   //Makes sure that the pointer input has memory allocated to it before proceeding to the rest of the code
    {
        printf("\nPlease enter a string (Maximum of 10 characters): "); //Getting the input string
        scanf("%s", input);
        len = strlen(input);//Gets the string length of the input string
        for(;;) //For loop that goes on to infinity unless a break statement appeared
        {
            printf("\nPlease input an integer between 1 to 10: ");  //Gets the integer that gets the position of the character
            scanf(" %d", &strinput);
            if(strinput>0 && strinput<= len) //Makes sure that the input integer would be within the length of the string input
            {
            strinput = strinput - 1;    //Because the real position of the elements of the string starts from zero, the integer must subtract a one to get the position of the character to be replaced
            printf("\nPlease input a character: "); //Gets the input character that will replace the old
            scanf(" %c", &cinput);
            *(input+strinput) = cinput; //Gets the value of the correct element of the pointer input and replaces that value with the input character
            printf("\nModified string: ");  //Prints out the newly modified string
            puts(input);
            printf("\n");
            }
            else    //Makes sure that the for loop will end if the user entered either an integer not within the length of the string or not within the maximum range of characters (1-10 characters)
            {
                break;
            }
        }

        
    }
    else    //Prints that the memory allocation for pointer input has failed and frees up any memory allocated to pointer input
    {
        printf("\nMemory allocation failed. Please restart the program.\n");
    }
    free(input); //Frees up the allocated memory of pointer input
    return 0;
}
