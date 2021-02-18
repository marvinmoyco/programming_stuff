/* This program asks a number from 1-12 and it converts it to the corresponding month */
#include <stdio.h>

int main(void)
{
	int input; // Variable declaration
	printf("Input an number from 1-12 to convert it to its corresponding month: "); // Asks the user for the input
	scanf("%d", &input); // Waits the user to input a number
	switch (input + 0) // The switch statement determines what number the user chose and what is it corresponding month
	{
	case 1:
		printf("\nYour number is %d\n", input);
		printf("%d is equal to the month of January!\n", input);
		break;
	case 2:
		printf("\nYour number is %d\n", input);
		printf("%d is equal to the month of February!\n", input);
		break;
	case 3:
		printf("\nYour number is %d\n", input);
		printf("%d is equal to the month of March!\n", input);
		break;
	case 4:
		printf("\nYour number is %d\n", input);
		printf("%d is equal to the month of April!\n", input);
		break;
	case 5:
		printf("\nYour number is %d\n", input);
		printf("%d is equal to the month of May!\n", input);
		break;
	case 6:
		printf("\nYour number is %d\n", input);
		printf("%d is equal to the month of June!\n", input);
		break;
	case 7:
		printf("\nYour number is %d\n", input);
		printf("%d is equal to the month of July!\n", input);
		break;
	case 8:
		printf("\nYour number is %d\n", input);
		printf("%d is equal to the month of August!\n", input);
		break;
	case 9:
		printf("\nYour number is %d\n", input);
		printf("%d is equal to the month of September!\n", input);
		break;
	case 10:
		printf("\nYour number is %d\n", input);
		printf("%d is equal to the month of October!\n", input);
		break;
	case 11:
		printf("\nYour number is %d\n", input);
		printf("%d is equal to the month of November!\n", input);
		break;
	case 12:
		printf("\nYour number is %d\n", input);
		printf("%d is equal to the month of December!\n", input);
		break;
	default:
		printf("\nYour number is %d\n", input);
		printf("%d is not a valid input!\n", input);
		break;
	}
	return 0;
}
