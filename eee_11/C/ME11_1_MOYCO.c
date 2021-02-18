/*This program gets a 5 set of entries of Name, Contact Number, and Email address and checks if the input Name is equal to the name in  the database to print its contact information*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {    //Structure Definition
    char *name;
    char *number;
    char *emailadd;
}contact_t; //Typedef of struct contact



int main()
{
    contact_t *record;  //Variable declaration
    char *input;
    record = (contact_t*) malloc(sizeof(contact_t)*5);  //Malloc of the pointer record
    input = (char*) malloc(sizeof(char)*10);    //Malloc of the input pointer
    int c1,c2,c3,c4,c5;
    int i;
    for(i=0;i<5;i++)    //For loop that allocates memory to the char pointers members of each record pointer.
    {   
        (record+i)->name = (char*) malloc(sizeof(char)*10);
        (record+i)->number = (char*) malloc(sizeof(char)*12);
        (record+i)->emailadd = (char*) malloc(sizeof(char)*25);
    }
    
    
    
    if(!(((((((input||record)||((record->name)||(record->number)))||((record->emailadd)||((record+1)->name)))||(((record+1)->number)||((record+1)->emailadd)))||(((record+2)->name||(((record+2)->number)||((record+2)->emailadd)))||((record+3)->name)))||((record+3)->number||((record+3)->emailadd)))||(((record+4)->name)||((record+4)->number))||((record+4)->emailadd)))
    {   //If statement that checks if memory allocation is successful
        printf("\nMemory allocation failed. Restart the program.\n");
        exit(0);    //Exits the program
    }
    for(i=0;i<5;i++)
    {   //For loop that gets the 5 sets of entry of Name, Contact number and Email address
        printf("\nPlease enter Name #%d: ", i+1);
        scanf("%s", (record+i)->name);
        printf("\nPlease enter Contact Number #%d: ", i+1);
        scanf("%s", (record+i)->number);
        printf("\nPlease enter Email Address #%d: ", i+1);
        scanf("%s", (record+i)->emailadd);
    }
    
    printf("\nPlease enter the name to find their contact information: ");  //Gets the Name string to be compared to the database
    scanf("%s", input);
    
    c1 = strcmp(input,record->name);    //Strcmp of each of the 5 name string on the database
    c2 = strcmp(input,(record+1)->name);
    c3 = strcmp(input,(record+2)->name);
    c4 = strcmp(input,(record+3)->name);
    c5 = strcmp(input,(record+4)->name);
    printf("\n");
    if(c1 ==0)  //Checks if the Input Name string is equal to the 1st Name on the database
    {
        printf("\nContact Information: \n");    //Prints the Contact information of the 1st set
        printf("\nName #%d: ", 1);
        puts(record->name);
        printf("Contact Number #%d: ", 1);
        puts(record->number);
        printf("Email Address #%d: ", 1);
        puts(record->emailadd);
        
    }
    else if(c2 == 0)    //Checks if the Input Name string is equal to the 2nd Name on the database
    {
        printf("\nContact Information: \n");    //Prints the Contact information of the 2nd set
        printf("\nName #%d: ", 2);
        puts((record+1)->name);
        printf("Contact Number #%d: ", 2);
        puts((record+1)->number);
        printf("Email Address #%d: ", 2);
        puts((record+1)->emailadd);
        
    }
    else if(c3 == 0)    //Checks if the Input Name string is equal to the 3rd Name on the database
    {
        printf("\nContact Information: \n");    //Prints the Contact information of the 3rd set
        printf("\nName #%d: ", 3);
        puts((record+2)->name);
        printf("Contact Number #%d: ", 3);
        puts((record+2)->number);
        printf("Email Address #%d: ", 3);
        puts((record+2)->emailadd);
        
    }
    else if(c4 == 0)    //Checks if the Input Name string is equal to the 4th Name on the database
    {
        printf("\nContact Information: \n");    //Prints the Contact information of the 4th set
        printf("\nName #%d: ", 4);
        puts((record+3)->name);
        printf("Contact Number #%d: ", 4);
        puts((record+3)->number);
        printf("Email Address #%d: ", 4);
        puts((record+3)->emailadd);
    }
    else if(c5 == 0)    //Checks if the Input Name string is equal to the 5th Name on the database
    {
        printf("\nContact Information: \n");    //Prints the Contact information of the 5th set
        printf("\nName #%d: ", 5);
        puts((record+4)->name);
        printf("Contact Number #%d: ", 5);
        puts((record+4)->number);
        printf("Email Address #%d: ", 5);
        puts((record+4)->emailadd);
        
    }
    else    //If the name is not on the database, it will print that the contact information is not available.
    {
        printf("\nNo contact available\n");
        
    }
    
    
    
    
    
   /*for(i=0;i<5;i++)
    {
        printf("\nName #%d: ", i+1);
        puts((record+i)->name);
        printf("Contact Number #%d: ", i+1);
        puts((record+i)->number);
        printf("Email Address #%d: ", i+1);
        puts((record+i)->emailadd);
    }*/
    
    for(i=0;i<5;i++)    //For loop the frees up the allocated memory of each of the members of pointer to struct contact record
    {
        free((record+i)->name);
       free((record+i)->number);
       free((record+i)->emailadd);
        
        
    }
    free(record);   //Frees up the allocated memory of the pointer record
    free(input);    //Frees up the memory allocated for the pointer input
    return 0;
}