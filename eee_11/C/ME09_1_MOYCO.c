/*This program calculates the age based on the birthdate and a date of comparison */
#include <stdio.h>


struct date { // Structure declaration
        int month;
        int day;
        int year;
    };
    
    
int main()
{
    struct date bday, date1; // Variable declaration
    int age =0;
    
    bday.month = 0; // Variable initialization
    bday.day = 0;
    bday.year = 0;
    date1.month = 0;
    date1.day = 0;
    date1.year = 0;
    printf("Please enter the birthday month: "); // Input gathering
    scanf(" %d", &(bday.month));
    printf("\nPlease enter the birthday day: ");
    scanf(" %d", &(bday.day));
    printf("\nPlease enter the birthday year: ");
    scanf(" %d", &(bday.year));
    printf("Please enter the comparison month: ");
    scanf(" %d", &(date1.month));
    printf("\nPlease enter the comparison day: ");
    scanf(" %d", &(date1.day));
    printf("\nPlease enter the comparison year: ");
    scanf(" %d", &(date1.year));
    
    printf("\n Birtday Date: %d/%d/%d\n", bday.month, bday.day, bday.year); // Prints out the birthdate
    printf("\n Comparison Date: %d/%d/%d\n", date1.month, date1.day, date1.year); // Prints out the date of comparison
    age = date1.year - bday.year; // Calculates the temporary age by subtracting the year of comparison to the birth year
    if(date1.month > bday.month) // If the month of comparison is greater than the birthmonth, the age is the temporary age
    {
	age = date1.year - bday.year;
	printf("\n The age is %d years old\n", age); // prints out the age
    }
    else if(date1.month < bday.month) // If the month of comparison is less than the birthmont, the age should be the temp age - 1 because the date has not passed the birthmonth yet
    {
	age = date1.year - bday.year;
	age= age -1; // Temp age -1
	printf("\n The age is %d years old\n", age); // Prints out the age
    }
    else if(date1.month == bday.month) // If the months are equal, the program will compare the days like what the program did on the months
    {
	if(date1.day > bday.day)
	{
		age = date1.year - bday.year;
		printf("\n The age is %d years old\n", age);
	}
	else if(date1.day < bday.day)
	{
		age = date1.year - bday.year;
		age= age -1;
		printf("\n The age is %d years old\n", age);
	}
	else if(date1.day == bday.day) // If the month and days are equal, the age is equal to temp age and it is his/her birthday
	{
		printf("\n The age is %d years old\n", age);
		printf("\n Happy Birthday!\n");
	}
    }
    
    
    return 0;
}









                
