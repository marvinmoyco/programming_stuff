/* This program finds what is the day of the input integer (1-31) */
#include <stdio.h>
#include <string.h>

int main()
{
	char days [7][10]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday", "Sunday"}; // 2-D Array for days of the week
	int day1 = 2; //March 1,2017 is on a wednesday where days[2][10] = "Wednesday"
	int input = 0;
	printf("Please enter a day of the month of March: ");// User input
	scanf(" %d", &input);
	if (input>0 && input < 32)//Checks if the input is within the valid range
	{
		int i;
		for(i=2;i<=input;i++)// For loop that calculates what is the day of the input day.
		{
			day1 = day1 +1;
			if(day1 == 7)//If day1 reaches 7 (Sunday) and the loop is not finish, the program reassigns day1 to 0 (Monday) 
			{
				day1 = day1 - 7;
			}
		}
		printf("\nUser input (day in March): %d\n", input); //prints user input
		switch(day1) // Switch statement that prints out the name of the day based on the computed value of day1
		{
			case 0:
				puts(days[0]);
				break;
			case 1:
				puts(days[1]);
				break;
			case 2:
				puts(days[2]);
				break;
			case 3:
				puts(days[3]);
				break;
			case 4:
				puts(days[4]);
				break;
			case 5:
				puts(days[5]);
				break;
			case 6:
				puts(days[6]);
				break;
			default:
				break;
		}
	
	}
	else
	{
		printf("Invalid input.\n");//prints if the input is invalid (not between 1-31)
		return 0;
	}
	return 0;
}
