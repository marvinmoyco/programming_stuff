/* This program gets a series of strings (separated by newline) from1  to 10 lines and puts it in  a newly created output file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
    char *input;    //Variable declaration
    int numLines =0;
    FILE *fptr;
    int i;
    input = (char*) malloc(sizeof(char)*20);    //Malloc of input pointer. (Max char per string is 20 char)

    if(!((numLines<=10) && (numLines >= 1)))    //Checks if the number of lines input in command line is within the allowable range (1-10)
    {
        printf("\nPlease enter a valid number of lines. Select from 1 to 10.\n");
        exit(0);
    }
    if(argc != 3)   //Checks if the arguments in command line is 3
    {
        printf("\nThe format is wrong. Please use this format: ./<program name> <output_file> <number_of_lines>\n");
        exit(0);
    }
    if(!input)  //Checks if the malloc of input pointer is successful
    {
        printf("\nMemory allocation failed. Restart the program.\n");
        exit(0);
    }
    fptr = fopen(argv[1],"w");  //Creates the output file and opens it with write mode
    if(fptr == NULL)    //Checks if the output file is created successfully
    {
        printf("\nThe file %s does not exist. Open a text file that exist.\n", argv[1]);
        free(input);
        exit(0);
    }

	
    numLines = atoi(argv[2]);   //Converts the 2nd argument in command line into integer to compare it later
    
    for(i=0;i<numLines;i++) //For loop that gets the string (up to 20 characters) and puts it in the created output file
    {
        printf("\nPlease enter the string to be placed on line #%d:\n", i+1);
        fgets(input, 21, stdin);    //Gets the input string from user
        fputs(input,fptr);  //Puts the input string to the output file
    }
    
    free(input);    //Frees up the allocated memory for input pointer
    fclose(fptr);   //Closes the created output file
    return 0;
}
