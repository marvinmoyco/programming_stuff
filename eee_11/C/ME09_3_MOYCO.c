/* This program gets contact information and when it searches a name that is in the list of input contact info, the program will print out the contact information of that name*/
#include <stdio.h>
#include <string.h>

int main()
{
    struct contact{ // Structure declaration
        char name[11];
        char number[12];
        char emailadd[26];
        
    };
    char sname[10]; // Variable declarations
    struct contact cname[5];
    int i,j=0; // Variable initialization
    int cmp[5] = {0,0,0,0,0};
    int flag =0;
    
    for(i=0;i<5;i++) // For loop that gets the contact information
    {
        printf("\nPlease enter Contact Name #%d: ", i+1);
        scanf("%s", cname[i].name);
        printf("\nPlease enter Contact Number #%d: ", i+1);
        scanf("%s", cname[i].number);
        printf("\nPlease enter Contact E-mail address #%d: ",i+1);
        scanf("%s", cname[i].emailadd);
    }
    
    printf("\n Please enter a name to find for contact information: "); // input name to get the contact information
    scanf("%s", sname);
    
    
    for(j=0;j<5;j++) // For loop that compares the name string to the input name string 
    {
        cmp[j] = strcmp(sname, cname[j].name); // uses array of cmp to get the strcmp values of every name string to the input name string
        if(cmp[j] == 0) // If the strcmp value is zero (means its equal) then the program will print the contact information of the contact name string
        {
            printf("\nContact information: \n");
            printf("Name: ");
            puts(cname[j].name);
            printf("\nContact Number: ");
            puts(cname[j].number);
            printf("\nE-mail Address: ");
            puts(cname[j].emailadd);
            flag++; // adds flag for checking
            break; // break to print only once
            
        }
    }
    if(flag != 1) // Flag lets the program know/check if the for loop found a match in the list of contact information, if not (or flag == 0) the program will print that there is no contact available for the input name string
    {
        //printf("\nCMP #%d is = %d",j+1, cmp[j]);
        printf("\n No contact available.\n");
    }
    return 0;
}
