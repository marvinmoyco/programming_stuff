/*
Machine Problem 2
This program uses a text file as an input of entries (1-5) of author, books, and control number and sorts them according by author's name, title, and control number.

Jan Marvin D. Moyco
2015-09359
EEE 11 WLMFQR
*/
#include <stdio.h>  //Libraries used
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct entry {  //Declaration of struct data type and its typedef
    char *name;
    char *title;
    char *controlNumber;
    struct entry *next_record;
}entry_t;


void arrangebyName(entry_t *inPtr, char *outputFile, int num);  //Function prototypes of the different functions used.
void arrangebyTitle(entry_t *inPtr1, char *outputFile1, int num1);
void arrangebyControlNumber(entry_t *inPtr2, char *outputFile2, int num2);
void modifiedToUpper(entry_t *str, int num3);
int spaceChecker(char *inPtr1);

int main(int argc, char *argv[])
{   //Main function that will run.
    FILE *Fptr;     //Variable declarations.
    entry_t *record;
    int i,numLines=0;
    char c='A';
    char *buffer;
    char *token;
    //int s;
    /*Error checking to make sure that the command line arguments are properly typed */
    if(argc != 3)
    {
        printf("\nCommand-Line Arguments have wrong format. Make sure that you have exactly 3 arguments in this format:\n ./<Program filename> <Input filename> <Output filename>");
        exit(0);
    }
    
    //Opening of the file using fopen
    Fptr = fopen(argv[1], "r");
    
    
    /*Error checking that makes sure the input file is sucessfully opened */
    if(Fptr == NULL)
    {
        printf("\nNO DATASET AVAILABLE\n");
        exit(0);
    }
    
    
    
    /*Memory allocation of the different pointers and the pointers within the structures */
    buffer = (char*) malloc(sizeof(char)*92);
    record  = (entry_t*) malloc(sizeof(entry_t)*5);
    
    
    
    
    for(i=0;i<5;i++)
    {   //Memory allocation for all of the members of the struct pointer.
        (record+i)->name = (char*) malloc(sizeof(char)*30);
        (record+i)->title = (char*) malloc(sizeof(char)*50);
        (record+i)->controlNumber = (char*) malloc(sizeof(char)*6);
    }
    
    
    
    /*Error checking to check if the memory allocation is sucessful for all of the pointers*/
    if(!(((((buffer&&(record))&&((record+1)&&(record+2)))&&(((record+3)&&(record+4))&&((record->name)&&(record->title))))&&((record->controlNumber)&&((record+1)->name)))&&((record+1)->title))&&
    ((((((record+1)->controlNumber)&&((record+2)->name))&&(((record+2)->title)&&((record+2)->controlNumber)))&&(((record+3)->name)&&((record+3)->title)))&&((((record+3)->controlNumber)&&((record+4)->name))
    &&(((record+4)->title)&&((record+4)->controlNumber)))))
    {
        printf("\nMemory allocation unsuccessful. Restart the program to reset.\n");
        exit(0);
    }
    record->next_record = record+1;
    (record+1)->next_record = record+2;
    (record+2)->next_record = record+3;
    (record+3)->next_record = record+4;
    (record+4)->next_record = NULL;
    
    /* This part prints the filename of input and output files and prints out the unsorted dataset to the terminal */
    printf("\nInput file: %s\n", argv[1]);
    printf("Output file: %s\n", argv[2]);
    printf("\nUnsorted Dataset: \n");
    for(numLines=0;c!=EOF;)
    {   //Gets the number of entries by using fgetc.
        c=fgetc(Fptr);
        if(c=='|')
        {
            numLines++;
        }
        printf("%c", c);
    }
    printf("\n\n");
    c='A';  //Sets the char c to a non-NULL character
    
    rewind(Fptr);   //Rewinds the pointer of the file to the beginning of the file
    i=0;
    for(i=0;i<numLines;i++)
    {   //This for loop parses an entry to separate the name of the author, title of the book, and the control number and saves it the struct pointer
        fgets(buffer,92,Fptr);
        token = strtok(buffer,";");
        //strcpy((record+i)->name,token);
        sscanf(token,"%[^\n]",(record+i)->name);
        token = strtok(NULL,";");
        //strcpy((record+i)->title,token+1);
        sscanf(token,"\t%[^\n]",(record+i)->title);
        token = strtok(NULL,"|");
        //strcpy((record+i)->controlNumber,token+1);
        sscanf(token,"\t%[^\n]",(record+i)->controlNumber);
    }
    rewind(Fptr);
   // modifiedToUpper(record,numLines);
    
    fclose(Fptr);   //Closes the file opened.
   
    arrangebyName(record,argv[2],numLines); //Function call for the function that arranges the entries by name
    arrangebyTitle(record,argv[2],numLines); //Function call for the function that arranges the entries by title
    arrangebyControlNumber(record,argv[2],numLines);  //Function call for the function that arranges the entries by controlnumber
    
    
    for(i=0;i<5;i++)
    {   //This loop frees the allocated memory of each of the member of the struct
        free((record+i)->name);
        free((record+i)->title);
        free((record+i)->controlNumber);
        
    }
    free(record);   //Frees up the allocated memory of the main struct pointer
    free(buffer);   //Frees up the allocated memory of the buffer pointer.
    
    return 0;
}




/*Function that arranges the entries by name*/
void arrangebyName(entry_t *inPtr,char *outputFile, int num)
{
    FILE *ptr1;
    ptr1 = fopen(outputFile,"w+");  //Opens the file in reading/writing mode
    if(ptr1 == NULL)//Error checking if the file does not exist or empty
    {
        printf("\nNO DATASET AVAILABLE\n");
        exit(0);
    }
    entry_t *tempRecord1;   //Declaration of pointers
    char *nametempString;
    entry_t *tempRecord;
    tempRecord = (entry_t*) malloc(sizeof(entry_t));    //Memory allocation of pointers.
    tempRecord1 = (entry_t*) malloc(sizeof(entry_t));
    nametempString = (char*) malloc(sizeof(char)*30);
    if(!((tempRecord1&&nametempString)&&tempRecord))
    {   //Error checking for the memory allocation of the pointers
        printf("Memory allocation failed.Restart the program\n");
        exit(0);
    }
    int strret; //Variable declaration
    //int strret2;
    int i,j;
    int n;
    int check = 0;

    
    /*This arranges all missing parameter to the top of the order*/
    for(i=0;i<num-1;i++)
    {   //This outer for loop makes sure that each of the entry will be compared
            for(j=i+1;j<num;j++)
            {   //This for loops compares one entry to all others
            
                strret = strcasecmp((inPtr+i)->name,((inPtr+j)->name));

                //printf("\nStrcmp value = %d\n", strret);

                if(strret > 0)
                {   //If the strret is positive it means that the 2nd string is 
                    *tempRecord = *(inPtr+i);
                    *(inPtr+i) = *(inPtr+j);
                    *(inPtr+j) = *tempRecord;

                }
            
            }
        
    }
    
    
    
    /*This loop shifts all the missing parameters to the bottom part of the dataset */
    i=0;
    while( i < num)
    {   //This loop makes sure that it runs through all of the input
        //strret2 = strcasecmp((inPtr)->title," ");    //This identifies if there is a missing parameter bec in the 1st sorting, all the spaces are on the top of the dataset
        check = spaceChecker(inPtr->name);
        if(check != 0)
        {                   //This if statement makes sure that the for loop for shifting an element down the data set is only achieved when the 1st element is a missing parameter
            for(j=0, n =1;n<num;j++,n++)
            {   //This for loop shifts the space to the bottom of the dataset
                *tempRecord = *(inPtr+j);
                *(inPtr+j) = *(inPtr+n);
                *(inPtr+n) = *tempRecord;
            }
        }
        
        i++;
    }
    
    
    
    /*Prints out the dataset to the terminal */
    printf("Sorted by Name: \n");
    for(i=0;i<num;i++)
    {   //Prints out the ordered set
        printf("%s;\t%s;\t%s\t|\n",(inPtr+i)->name,(inPtr+i)->title,(inPtr+i)->controlNumber);
    }
    printf("\n\n");
    
    /*Puts the sorted set into the file*/
    fputs("Sorted by Name: \n", ptr1);
    
    /*Writes the ordered dataset to the file.*/
    for(i=0;i<num;i++)
    {   //Prints out the ordered set
        fprintf(ptr1,"%s;\t%s;\t%s\t|\n",(inPtr+i)->name,(inPtr+i)->title,(inPtr+i)->controlNumber);
        
    }
    fprintf(ptr1,"\n\n");
    
    
    //Closes the file
    fclose(ptr1);
    //Frees up all the allocated memory
    free(tempRecord1);
    free(nametempString);
    free(tempRecord);
}


/*Function that arranges the entries by Title*/
void arrangebyTitle(entry_t *inPtr,char *outputFile, int num)
{
    FILE *ptr1;
    ptr1 = fopen(outputFile,"a+");  //Opens the file in appending mode
    if(ptr1 == NULL)//Error checking if the file does not exist or empty
    {
        printf("\nNO DATASET AVAILABLE\n");
        exit(0);
    }
    entry_t *tempRecord1;   //Declaration of pointers
    char *nametempString;
    entry_t *tempRecord;
    tempRecord = (entry_t*) malloc(sizeof(entry_t));    //Memory allocation of pointers.
    tempRecord1 = (entry_t*) malloc(sizeof(entry_t));
    nametempString = (char*) malloc(sizeof(char)*30);
    if(!((tempRecord1&&nametempString)&&tempRecord))
    {   //Error checking for the memory allocation of the pointers
        printf("Memory allocation failed.Restart the program\n");
        exit(0);
    }
    int strret; //Variable declaration
    //int strret2;
    int i,j;
    int n;
    int check = 0;

    
    /*This arranges all missing parameter to the top of the order*/
    for(i=0;i<num-1;i++)
    {   //This outer for loop makes sure that each of the entry will be compared
            for(j=i+1;j<num;j++)
            {   //This for loops compares one entry to all others
            
                strret = strcasecmp((inPtr+i)->title,((inPtr+j)->title));

                //printf("\nStrcmp value = %d\n", strret);

                if(strret > 0)
                {   //If the strret is positive it means that the 2nd string is 
                    *tempRecord = *(inPtr+i);
                    *(inPtr+i) = *(inPtr+j);
                    *(inPtr+j) = *tempRecord;

                }
            
            }
        
    }
    
    
    
    /*This loop shifts all the missing parameters to the bottom part of the dataset */
    i=0;
    while( i < num)
    {   //This loop makes sure that it runs through all of the input
        //strret2 = strcasecmp((inPtr)->title," ");    //This identifies if there is a missing parameter bec in the 1st sorting, all the spaces are on the top of the dataset
        check = spaceChecker(inPtr->title);
        if(check != 0)
        {                   //This if statement makes sure that the for loop for shifting an element down the data set is only achieved when the 1st element is a missing parameter
            for(j=0, n =1;n<num;j++,n++)
            {   //This for loop shifts the space to the bottom of the dataset
                *tempRecord = *(inPtr+j);
                *(inPtr+j) = *(inPtr+n);
                *(inPtr+n) = *tempRecord;
            }
        }
        
        i++;
    }
    
    
    
    /*Prints out the dataset to the terminal */
    printf("Sorted by Title: \n");
    for(i=0;i<num;i++)
    {   //Prints out the ordered set
        printf("%s;\t%s;\t%s\t|\n",(inPtr+i)->name,(inPtr+i)->title,(inPtr+i)->controlNumber);
    }
    printf("\n\n");
    
    /*Puts the sorted set into the file*/
    fputs("Sorted by Title: \n", ptr1);
    
    /*Writes the ordered dataset to the file.*/
    for(i=0;i<num;i++)
    {   //Prints out the ordered set
        fprintf(ptr1,"%s;\t%s;\t%s\t|\n",(inPtr+i)->name,(inPtr+i)->title,(inPtr+i)->controlNumber);
        
    }
    fprintf(ptr1,"\n\n");
    
    
    //Closes the file
    fclose(ptr1);
    //Frees up all the allocated memory
    free(tempRecord1);
    free(nametempString);
    free(tempRecord);
}


/*Function that arranges the entries by Control Number*/
void arrangebyControlNumber(entry_t *inPtr,char *outputFile, int num)
{
    FILE *ptr1;
    ptr1 = fopen(outputFile,"a+");  //Opens the file in appending mode
    if(ptr1 == NULL)//Error checking if the file does not exist or empty
    {
        printf("\nNO DATASET AVAILABLE\n");
        exit(0);
    }
    entry_t *tempRecord1;   //Declaration of pointers
    char *nametempString;
    entry_t *tempRecord;
    tempRecord = (entry_t*) malloc(sizeof(entry_t));    //Memory allocation of pointers.
    tempRecord1 = (entry_t*) malloc(sizeof(entry_t));
    nametempString = (char*) malloc(sizeof(char)*30);
    if(!((tempRecord1&&nametempString)&&tempRecord))
    {   //Error checking for the memory allocation of the pointers
        printf("Memory allocation failed.Restart the program\n");
        exit(0);
    }
    int strret; //Variable declaration
    //int strret2;
    int i,j;
    int n;
    int check = 0;

    
    /*This arranges all missing parameter to the top of the order*/
    for(i=0;i<num-1;i++)
    {   //This outer for loop makes sure that each of the entry will be compared
            for(j=i+1;j<num;j++)
            {   //This for loops compares one entry to all others
            
                strret = strcasecmp((inPtr+i)->controlNumber,((inPtr+j)->controlNumber));

                //printf("\nStrcmp value = %d\n", strret);

                if(strret > 0)
                {   //If the strret is positive it means that the 2nd string is 
                    *tempRecord = *(inPtr+i);
                    *(inPtr+i) = *(inPtr+j);
                    *(inPtr+j) = *tempRecord;

                }
            
            }
        
    }
    
    
    
    /*This loop shifts all the missing parameters to the bottom part of the dataset */
    i=0;
    while( i < num)
    {   //This loop makes sure that it runs through all of the input
        check = spaceChecker(inPtr->controlNumber);
        if(check != 0)
        {                   //This if statement makes sure that the for loop for shifting an element down the data set is only achieved when the 1st element is a missing parameter
            for(j=0, n =1;n<num;j++,n++)
            {   //This for loop shifts the space to the bottom of the dataset
                *tempRecord = *(inPtr+j);
                *(inPtr+j) = *(inPtr+n);
                *(inPtr+n) = *tempRecord;
            }
        }
        
        i++;
    }
    
    
    
    /*Prints out the dataset to the terminal */
    printf("Sorted by Control Number: \n");
    for(i=0;i<num;i++)
    {   //Prints out the ordered set
        printf("%s;\t%s;\t%s\t|\n",(inPtr+i)->name,(inPtr+i)->title,(inPtr+i)->controlNumber);
    }
    printf("\n\n");
    
    /*Puts the sorted set into the file*/
    fputs("Sorted by Control Number: \n", ptr1);
    
    /*Writes the ordered dataset to the file.*/
    for(i=0;i<num;i++)
    {   //Prints out the ordered set
        fprintf(ptr1,"%s;\t%s;\t%s\t|\n",(inPtr+i)->name,(inPtr+i)->title,(inPtr+i)->controlNumber);
        
    }
    fprintf(ptr1,"\n\n");
    
    
    //Closes the file
    fclose(ptr1);
    //Frees up all the allocated memory
    free(tempRecord1);
    free(nametempString);
    free(tempRecord);
}
/*This function checks if the input String is only whitespaces */
int spaceChecker(char *inPtr1)
{
    int checker =0; //Variable declaration
    int v,j,s;
    //printf("inPtr = %s;\n", inPtr1);
    //s= strlen(inPtr1);
    //printf("s = %d\n", s);
    /*this loop gets the number of characters of a string*/
    for(j=0,s=0;;j++)   //Infinite loop that breaks if the function identifies a terminating null
    {
        
        if(inPtr1[j] != '\0')
        {   //This checks if the element of a string is not a terminating null
            s++;
            break;
           
        }
        
    }
    
    for(j=0;j<s;j++)
    {   //This loop checks if the element of the string is a whitespace or not
        v = isgraph(inPtr1[j]);
        //rintf("v = %d", v);
         if(v==0)
            {//This if statement increments checker so that it means the string is a missing parameter
                checker++;
            }
    }
    
    
        //printf("checker = %d\n", checker);
        return checker;
}