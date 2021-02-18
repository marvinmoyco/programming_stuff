/* This program converts a number (from 0-999,999,999) to its equivalent word.*/
#include <stdio.h>

int millions(int); // Declares the function prototypes of the millions, thousands, and hundreds function.
int thousands(int);
int hundreds(int);

int main() // Main function
{
	int input, place1, place2, place3 = 0; // Variable Decalaration
	printf("Please enter an integer: \n");// Program asks for user input
	scanf(" %d", &input);
	printf("\n");
	if( (input > 0) && (input < 1000000000))// Program sets the range of the valid input
	{
			place1 = input/1000000;// Parses the input
			millions(place1); // Function call for  millions
			input = input % 1000000;// Parses the input to get the thousands places

			place2 = input / 1000;
			thousands(place2); // Function call for thousands
			input = input % 1000; // Parses the input to get the hundreds places

			place3 = input;
			hundreds(place3); // Function call for hundreds


	}
	else if(input == 0) // Prints "Zero" if the input is zero
	{
		printf("Zero\n");
	}
	else{ // Prints "Invalid input" if the input is more than 999,999,999 or negative number
		printf("Invalid input");
	}
	return 0;
}



int millions (int x) // millions function prints the word equivalent of each digit in hundredth million, tenth million, and millionth
{

	int millionth, tmillionth, hmillionth, tmillionth1 = 0; // Variable Declaration

	if(x != 0) // Sets that the millions places of input is not zero
	{

		hmillionth = x / 100;//Parses the digits
		millionth = x % 10;
		tmillionth = (x % 100);
		tmillionth1 = (x % 100) - millionth;
        // It prints the equivalent word of each digit in its place.
		if(hmillionth != 0)
        {
            if((tmillionth1 == 0) && (millionth == 0))
            {
            switch (hmillionth){

			case 1:
				printf("One hundred Million ");
				break;
			case 2:
				printf("Two hundred Million ");
				break;
			case 3:
				printf("Three hundred Million ");
				break;
			case 4:
				printf("Four hundred Million ");
				break;
			case 5:
				printf("Five hundred Million ");
				break;
			case 6:
				printf("Six hundred Million ");
				break;
			case 7:
				printf("Seven hundred Million ");
				break;
			case 8:
				printf("Eight hundred Million ");
				break;
			case 9:
				printf("Nine hundred Million ");
				break;
			default:
				break;
            }
            }
            else if((tmillionth1 != 0) && (millionth == 0) )
            {
            switch (hmillionth){

			case 1:
				printf("One hundred ");
				break;
			case 2:
				printf("Two hundred ");
				break;
			case 3:
				printf("Three hundred ");
				break;
			case 4:
				printf("Four hundred ");
				break;
			case 5:
				printf("Five hundred ");
				break;
			case 6:
				printf("Six hundred ");
				break;
			case 7:
				printf("Seven hundred ");
				break;
			case 8:
				printf("Eight hundred ");
				break;
			case 9:
				printf("Nine hundred ");
				break;
			default:
				break;
            }
            switch(tmillionth1){
                case 10:
                    printf("Ten Million ");
                    break;
				case 20:
					printf("Twenty Million ");
					break;
				case 30:
					printf("Thirty Million ");
					break;
				case 40:
					printf("Forty Million ");
					break;
				case 50:
					printf("Fifty Million ");
					break;
				case 60:
					printf("Sixty Million ");
					break;
				case 70:
					printf("Seventy Million ");
					break;
				case 80:
					printf("Eighty Million ");
					break;
				case 90:
					printf("Ninety Million ");
					break;

			}
            }
            else if((tmillionth1 == 0) && (millionth != 0))
            {
            switch (hmillionth){

			case 1:
				printf("One hundred ");
				break;
			case 2:
				printf("Two hundred ");
				break;
			case 3:
				printf("Three hundred ");
				break;
			case 4:
				printf("Four hundred ");
				break;
			case 5:
				printf("Five hundred ");
				break;
			case 6:
				printf("Six hundred ");
				break;
			case 7:
				printf("Seven hundred ");
				break;
			case 8:
				printf("Eight hundred ");
				break;
			case 9:
				printf("Nine hundred ");
				break;
			default:
				break;
            }
            switch(millionth){
				case 1:
					printf("One Million ");
					break;
				case 2:
					printf("Two Million ");
					break;
				case 3:
					printf("Three Million ");
					break;
				case 4:
					printf("Four Million ");
					break;
				case 5:
					printf("Five Million ");
					break;
				case 6:
					printf("Six Million ");
					break;
				case 7:
					printf("Seven Million ");
					break;
				case 8:
					printf("Eight Million ");
					break;
				case 9:
					printf("Nine Million ");
					break;

			}

            }
            else if ((tmillionth1 != 0) && (millionth != 0))
            {
                switch (hmillionth){

			case 1:
				printf("One hundred ");
				break;
			case 2:
				printf("Two hundred ");
				break;
			case 3:
				printf("Three hundred ");
				break;
			case 4:
				printf("Four hundred ");
				break;
			case 5:
				printf("Five hundred ");
				break;
			case 6:
				printf("Six hundred ");
				break;
			case 7:
				printf("Seven hundred ");
				break;
			case 8:
				printf("Eight hundred ");
				break;
			case 9:
				printf("Nine hundred ");
				break;
			default:
				break;
            }


            if(tmillionth1 != 10)
            {
                switch(tmillionth1){
				case 20:
					printf("Twenty ");
					break;
				case 30:
					printf("Thirty ");
					break;
				case 40:
					printf("Forty ");
					break;
				case 50:
					printf("Fifty ");
					break;
				case 60:
					printf("Sixty ");
					break;
				case 70:
					printf("Seventy ");
					break;
				case 80:
					printf("Eighty ");
					break;
				case 90:
					printf("Ninety ");
					break;

			}
			switch(millionth){
				case 1:
					printf("One Million ");
					break;
				case 2:
					printf("Two Million ");
					break;
				case 3:
					printf("Three Million ");
					break;
				case 4:
					printf("Four Million ");
					break;
				case 5:
					printf("Five Million ");
					break;
				case 6:
					printf("Six Million ");
					break;
				case 7:
					printf("Seven Million ");
					break;
				case 8:
					printf("Eight Million ");
					break;
				case 9:
					printf("Nine Million ");
					break;

			}
            }
            else if((tmillionth >= 10) && (tmillionth <= 19))
            {
                switch(tmillionth){
				case 10:
					printf("Ten Million ");
					break;
				case 11:
					printf("Eleven Million ");
					break;
				case 12:
					printf("Twelve Million ");
					break;
				case 13:
					printf("Thirteen Million ");
					break;
				case 14:
					printf("Fourteen Million ");
					break;
				case 15:
					printf("Fifteen Million ");
					break;
				case 16:
					printf("Sixteen Million ");
					break;
				case 17:
					printf("Seventeen Million ");
					break;
				case 18:
					printf("Eighteen Million ");
					break;
				case 19:
					printf("Nineteen Million ");
					break;
			}
            }
            }
        }




        else if (hmillionth == 0)
        {
            if((tmillionth1 != 0) && (millionth == 0) )
            {
            switch(tmillionth1){
                case 10:
                    printf("Ten Million ");
                    break;
				case 20:
					printf("Twenty Million ");
					break;
				case 30:
					printf("Thirty Million ");
					break;
				case 40:
					printf("Forty Million ");
					break;
				case 50:
					printf("Fifty Million ");
					break;
				case 60:
					printf("Sixty Million ");
					break;
				case 70:
					printf("Seventy Million ");
					break;
				case 80:
					printf("Eighty Million ");
					break;
				case 90:
					printf("Ninety Million ");
					break;

			}
            }
            else if((tmillionth1 == 0) && (millionth != 0))
            {

            switch(millionth){
				case 1:
					printf("One Million ");
					break;
				case 2:
					printf("Two Million ");
					break;
				case 3:
					printf("Three Million ");
					break;
				case 4:
					printf("Four Million ");
					break;
				case 5:
					printf("Five Million ");
					break;
				case 6:
					printf("Six Million ");
					break;
				case 7:
					printf("Seven Million ");
					break;
				case 8:
					printf("Eight Million ");
					break;
				case 9:
					printf("Nine Million ");
					break;

			}

            }
            else if ((tmillionth1 != 0) && (millionth != 0))
            {
            if(tmillionth1 != 10)
            {
                switch(tmillionth1){
				case 20:
					printf("Twenty ");
					break;
				case 30:
					printf("Thirty ");
					break;
				case 40:
					printf("Forty ");
					break;
				case 50:
					printf("Fifty ");
					break;
				case 60:
					printf("Sixty ");
					break;
				case 70:
					printf("Seventy ");
					break;
				case 80:
					printf("Eighty ");
					break;
				case 90:
					printf("Ninety ");
					break;

			}
			switch(millionth){
				case 1:
					printf("One Million ");
					break;
				case 2:
					printf("Two Million ");
					break;
				case 3:
					printf("Three Million ");
					break;
				case 4:
					printf("Four Million ");
					break;
				case 5:
					printf("Five Million ");
					break;
				case 6:
					printf("Six Million ");
					break;
				case 7:
					printf("Seven Million ");
					break;
				case 8:
					printf("Eight Million ");
					break;
				case 9:
					printf("Nine Million ");
					break;

			}
            }
            else if((tmillionth >= 10) && (tmillionth <= 19))
            {
                switch(tmillionth){
				case 10:
					printf("Ten Million ");
					break;
				case 11:
					printf("Eleven Million ");
					break;
				case 12:
					printf("Twelve Million ");
					break;
				case 13:
					printf("Thirteen Million ");
					break;
				case 14:
					printf("Fourteen Million ");
					break;
				case 15:
					printf("Fifteen Million ");
					break;
				case 16:
					printf("Sixteen Million ");
					break;
				case 17:
					printf("Seventeen Million ");
					break;
				case 18:
					printf("Eighteen Million ");
					break;
				case 19:
					printf("Nineteen Million ");
					break;
			}
            }
            }
        }

	}
	return 1;
}



int thousands (int y)//thousands function that prints the word equivalent of each digit in hundredth thousandth, tenth thousand, and thousandth
{

	int thousandth, tthousandth, hthousandth, tthousandth1 = 0; // Variable Declaration

	if(y != 0) // Sets that the input in the thousands places is not zero
	{

		hthousandth = y / 100; // Parses the input
		thousandth = y % 10;
		tthousandth = (y % 100);
		tthousandth1 = (y % 100) - thousandth;
        // Prints out the equivalent word of each digit in its places
		if(hthousandth != 0)
        {
            if((tthousandth1 == 0) && (thousandth == 0))
            {
            switch (hthousandth){

			case 1:
				printf("One hundred Thousand ");
				break;
			case 2:
				printf("Two hundred Thousand ");
				break;
			case 3:
				printf("Three hundred Thousand ");
				break;
			case 4:
				printf("Four hundred Thousand ");
				break;
			case 5:
				printf("Five hundred Thousand ");
				break;
			case 6:
				printf("Six hundred Thousand ");
				break;
			case 7:
				printf("Seven hundred Thousand ");
				break;
			case 8:
				printf("Eight hundred Thousand ");
				break;
			case 9:
				printf("Nine hundred Thousand ");
				break;
			default:
				break;
            }
            }
            else if((tthousandth1 != 0) && (thousandth == 0) )
            {
            switch (hthousandth){

			case 1:
				printf("One hundred ");
				break;
			case 2:
				printf("Two hundred ");
				break;
			case 3:
				printf("Three hundred ");
				break;
			case 4:
				printf("Four hundred ");
				break;
			case 5:
				printf("Five hundred ");
				break;
			case 6:
				printf("Six hundred ");
				break;
			case 7:
				printf("Seven hundred ");
				break;
			case 8:
				printf("Eight hundred ");
				break;
			case 9:
				printf("Nine hundred ");
				break;
			default:
				break;
            }
            switch(tthousandth1){
                case 10:
                    printf("Ten Thousand ");
                    break;
				case 20:
					printf("Twenty Thousand ");
					break;
				case 30:
					printf("Thirty Thousand ");
					break;
				case 40:
					printf("Forty Thousand ");
					break;
				case 50:
					printf("Fifty Thousand ");
					break;
				case 60:
					printf("Sixty Thousand ");
					break;
				case 70:
					printf("Seventy Thousand ");
					break;
				case 80:
					printf("Eighty Thousand ");
					break;
				case 90:
					printf("Ninety Thousand ");
					break;

			}
            }
            else if((tthousandth1 == 0) && (thousandth != 0))
            {
            switch (hthousandth){

			case 1:
				printf("One hundred ");
				break;
			case 2:
				printf("Two hundred ");
				break;
			case 3:
				printf("Three hundred ");
				break;
			case 4:
				printf("Four hundred ");
				break;
			case 5:
				printf("Five hundred ");
				break;
			case 6:
				printf("Six hundred ");
				break;
			case 7:
				printf("Seven hundred ");
				break;
			case 8:
				printf("Eight hundred ");
				break;
			case 9:
				printf("Nine hundred ");
				break;
			default:
				break;
            }
            switch(thousandth){
				case 1:
					printf("One Thousand ");
					break;
				case 2:
					printf("Two Thousand ");
					break;
				case 3:
					printf("Three Thousand ");
					break;
				case 4:
					printf("Four Thousand ");
					break;
				case 5:
					printf("Five Thousand ");
					break;
				case 6:
					printf("Six Thousand ");
					break;
				case 7:
					printf("Seven Thousand ");
					break;
				case 8:
					printf("Eight Thousand ");
					break;
				case 9:
					printf("Nine Thousand ");
					break;

			}

            }
            else if ((tthousandth1 != 0) && (thousandth != 0))
            {
                switch (hthousandth){

			case 1:
				printf("One hundred ");
				break;
			case 2:
				printf("Two hundred ");
				break;
			case 3:
				printf("Three hundred ");
				break;
			case 4:
				printf("Four hundred ");
				break;
			case 5:
				printf("Five hundred ");
				break;
			case 6:
				printf("Six hundred ");
				break;
			case 7:
				printf("Seven hundred ");
				break;
			case 8:
				printf("Eight hundred ");
				break;
			case 9:
				printf("Nine hundred ");
				break;
			default:
				break;
            }


            if(tthousandth1 != 10)
            {
                switch(tthousandth1){
				case 20:
					printf("Twenty ");
					break;
				case 30:
					printf("Thirty ");
					break;
				case 40:
					printf("Forty ");
					break;
				case 50:
					printf("Fifty ");
					break;
				case 60:
					printf("Sixty ");
					break;
				case 70:
					printf("Seventy ");
					break;
				case 80:
					printf("Eighty ");
					break;
				case 90:
					printf("Ninety ");
					break;

			}
			switch(thousandth){
				case 1:
					printf("One Thousand ");
					break;
				case 2:
					printf("Two Thousand ");
					break;
				case 3:
					printf("Three Thousand ");
					break;
				case 4:
					printf("Four Thousand ");
					break;
				case 5:
					printf("Five Thousand ");
					break;
				case 6:
					printf("Six Thousand ");
					break;
				case 7:
					printf("Seven Thousand ");
					break;
				case 8:
					printf("Eight Thousand ");
					break;
				case 9:
					printf("Nine Thousand ");
					break;

			}
            }
            else if((tthousandth >= 10) && (tthousandth <= 19))
            {
                switch(tthousandth){
				case 10:
					printf("Ten Thousand ");
					break;
				case 11:
					printf("Eleven Thousand ");
					break;
				case 12:
					printf("Twelve Thousand ");
					break;
				case 13:
					printf("Thirteen Thousand ");
					break;
				case 14:
					printf("Fourteen Thousand ");
					break;
				case 15:
					printf("Fifteen Thousand ");
					break;
				case 16:
					printf("Sixteen Thousand ");
					break;
				case 17:
					printf("Seventeen Thousand ");
					break;
				case 18:
					printf("Eighteen Thousand ");
					break;
				case 19:
					printf("Nineteen Thousand ");
					break;
			}
            }
            }
        }




        else if (hthousandth == 0)
        {
            if((tthousandth1 != 0) && (thousandth == 0) )
            {
            switch(tthousandth1){
                case 10:
                    printf("Ten Thousand ");
                    break;
				case 20:
					printf("Twenty Thousand ");
					break;
				case 30:
					printf("Thirty Thousand ");
					break;
				case 40:
					printf("Forty Thousand ");
					break;
				case 50:
					printf("Fifty Thousand ");
					break;
				case 60:
					printf("Sixty Thousand ");
					break;
				case 70:
					printf("Seventy Thousand ");
					break;
				case 80:
					printf("Eighty Thousand ");
					break;
				case 90:
					printf("Ninety Thousand ");
					break;

			}
            }
            else if((tthousandth1 == 0) && (thousandth != 0))
            {

            switch(thousandth){
				case 1:
					printf("One Thousand ");
					break;
				case 2:
					printf("Two Thousand ");
					break;
				case 3:
					printf("Three Thousand ");
					break;
				case 4:
					printf("Four Thousand ");
					break;
				case 5:
					printf("Five Thousand ");
					break;
				case 6:
					printf("Six Thousand ");
					break;
				case 7:
					printf("Seven Thousand ");
					break;
				case 8:
					printf("Eight Thousand ");
					break;
				case 9:
					printf("Nine Thousand ");
					break;

			}

            }
            else if ((tthousandth1 != 0) && (thousandth != 0))
            {
            if(tthousandth1 != 10)
            {
                switch(tthousandth1){
				case 20:
					printf("Twenty ");
					break;
				case 30:
					printf("Thirty ");
					break;
				case 40:
					printf("Forty ");
					break;
				case 50:
					printf("Fifty ");
					break;
				case 60:
					printf("Sixty ");
					break;
				case 70:
					printf("Seventy ");
					break;
				case 80:
					printf("Eighty ");
					break;
				case 90:
					printf("Ninety ");
					break;

			}
			switch(thousandth){
				case 1:
					printf("One Thousand ");
					break;
				case 2:
					printf("Two Thousand ");
					break;
				case 3:
					printf("Three Thousand ");
					break;
				case 4:
					printf("Four Thousand ");
					break;
				case 5:
					printf("Five Thousand ");
					break;
				case 6:
					printf("Six Thousand ");
					break;
				case 7:
					printf("Seven Thousand ");
					break;
				case 8:
					printf("Eight Thousand ");
					break;
				case 9:
					printf("Nine Thousand ");
					break;

			}
            }
            else if((tthousandth >= 10) && (tthousandth <= 19))
            {
                switch(tthousandth){
				case 10:
					printf("Ten Thousand ");
					break;
				case 11:
					printf("Eleven Thousand ");
					break;
				case 12:
					printf("Twelve Thousand ");
					break;
				case 13:
					printf("Thirteen Thousand ");
					break;
				case 14:
					printf("Fourteen Thousand ");
					break;
				case 15:
					printf("Fifteen Thousand ");
					break;
				case 16:
					printf("Sixteen Thousand ");
					break;
				case 17:
					printf("Seventeen Thousand ");
					break;
				case 18:
					printf("Eighteen Thousand ");
					break;
				case 19:
					printf("Nineteen Thousand ");
					break;
			}
            }
            }
        }


	}
	return 1;
}

int hundreds (int z)//hundreds function that prints the word equivalent of each digit in hundredth, tenths, and ones.
{

	int hundredth, thundredth, hhundredth, thundredth1 = 0; // Variable declaration

	if(z != 0) //Sets that the input on hundreds places is not zero
	{

		hhundredth = z / 100; // Parses the input
		hundredth = z % 10;
		thundredth = (z % 100);
		thundredth1 = (z % 100) - hundredth;
		//Prints out the word equivalent of the digits in its proper places.
		switch (hhundredth){

			case 1:
				printf("One hundred ");
				break;
			case 2:
				printf("Two hundred ");
				break;
			case 3:
				printf("Three hundred ");
				break;
			case 4:
				printf("Four hundred ");
				break;
			case 5:
				printf("Five hundred ");
				break;
			case 6:
				printf("Six hundred ");
				break;
			case 7:
				printf("Seven hundred ");
				break;
			case 8:
				printf("Eight hundred ");
				break;
			case 9:
				printf("Nine hundred ");
				break;
			default:
				break;
		}
		if(thundredth1 != 10)
		{
			switch(thundredth1){
				case 20:
					printf("Twenty ");
					break;
				case 30:
					printf("Thirty ");
					break;
				case 40:
					printf("Forty ");
					break;
				case 50:
					printf("Fifty ");
					break;
				case 60:
					printf("Sixty ");
					break;
				case 70:
					printf("Seventy ");
					break;
				case 80:
					printf("Eighty ");
					break;
				case 90:
					printf("Ninety ");
					break;

			}
			switch(hundredth){
				case 1:
					printf("One ");
					break;
				case 2:
					printf("Two ");
					break;
				case 3:
					printf("Three ");
					break;
				case 4:
					printf("Four ");
					break;
				case 5:
					printf("Five ");
					break;
				case 6:
					printf("Six ");
					break;
				case 7:
					printf("Seven ");
					break;
				case 8:
					printf("Eight ");
					break;
				case 9:
					printf("Nine ");
					break;

			}
		}
		else if ((thundredth >= 10) && (thundredth <= 19)){
			switch(thundredth){
				case 10:
					printf("Ten ");
					break;
				case 11:
					printf("Eleven ");
					break;
				case 12:
					printf("Twelve ");
					break;
				case 13:
					printf("Thirteen ");
					break;
				case 14:
					printf("Fourteen ");
					break;
				case 15:
					printf("Fifteen ");
					break;
				case 16:
					printf("Sixteen ");
					break;
				case 17:
					printf("Seventeen ");
					break;
				case 18:
					printf("Eighteen ");
					break;
				case 19:
					printf("Nineteen ");
					break;
			}
		}
		/*if(thundredth == 0 && hundredth == 0)
		{
			switch(hhundredth){
				case 1:
					printf("One hundred ");
					break;
				case 2:
					printf("Two hundred  ");
					break;
				case 3:
					printf("Three hundred  ");
					break;
				case 4:
					printf("Four hundred ");
					break;
				case 5:
					printf("Five hundred ");
					break;
				case 6:
					printf("Six hundred ");
					break;
				case 7:
					printf("Seven hundred ");
					break;
				case 8:
					printf("Eight hundred ");
					break;
				case 9:
					printf("Nine hundred ");
					break;}
		}*/
		/*else if( hundredth == 0)
		{
			switch (hhundredth){

			case 1:
				printf("One hundred ");
				break;
			case 2:
				printf("Two hundred ");
				break;
			case 3:
				printf("Three hundred ");
				break;
			case 4:
				printf("Four hundred ");
				break;
			case 5:
				printf("Five hundred ");
				break;
			case 6:
				printf("Six hundred ");
				break;
			case 7:
				printf("Seven hundred ");
				break;
			case 8:
				printf("Eight hundred ");
				break;
			case 9:
				printf("Nine hundred ");
				break;
			default:
				break;}
		}*/
		/*if(thundredth1 != 10)
		{
			switch(thundredth1){
				case 20:
					printf("Twenty ");
					break;
				case 30:
					printf("Thirty ");
					break;
				case 40:
					printf("Forty ");
					break;
				case 50:
					printf("Fifty ");
					break;
				case 60:
					printf("Sixty ");
					break;
				case 70:
					printf("Seventy ");
					break;
				case 80:
					printf("Eighty ");
					break;
				case 90:
					printf("Ninety ");
					break;

			}

		}*/

	}
	return 1;
}
