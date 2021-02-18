/*This program reads the input file and prints out how many words are in the input file.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
    char *input;    //Variable Declaration
    char c='A';
    FILE *fptr;
    unsigned int counter;
    input = (char*) malloc(sizeof(char)*100);   //Malloc of input pointer (Max char of input file is 100 characters)
    fptr = fopen(argv[1],"r");  //opens the input file for reading
    
    if(argc != 2)   //Checks if the command line argument format is correct
    {
        printf("\nThe format is wrong. Please use this format: ./<program name> <input filename>\n");
        free(input);    //Frees the allocated memory of input pointer
        exit(0);
    }
    if(!input)  //Checks if the Memory allocation is successful
    {
        printf("\nMemory allocation failed. Restart the program.\n");
        exit(0);
    }
    if(fptr == NULL)    //Checks if the input file exists and/or created
    {
        printf("\nThe file %s does not exist. Open a text file that exist.\n", argv[1]);
        free(input);    //Frees the allocated memory of pointer input
        exit(0);
    }
    
    
    for(counter =0;c != EOF;)   //For loop that checks each character of the input file. Each word is separated with a space and the last word would be after the End of FIle marker (EOF)
    {
        c=fgetc(fptr);  //Gets a character from the input file
        if(c==' ')  //Adds 1 to the counter integer (counter integer is the counter that checks how many words have been identified)if it recognizes a space character
        {
            counter++;
        }
        if(c == EOF)    //If c is the end of file marker, the characters before it is also considered as a word
        {
            counter++;
        }
	if(c == '\n')	
	{
		counter++;
	}
        
        //fscanf(fptr," %s",input);
    }
    counter--;//Subtracts 1 from counter to remove excess increment if the c ends with newline and EOF
    printf("The number of words in %s are %d\n", argv[1], counter); //Prints the counter. 
    
    free(input);    //Frees up the allocated memory of the input pointer
    fclose(fptr);   //Closes the input file
    return 0;
}
