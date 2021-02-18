#include <stdio.h>

/* This program asks a letter from the user and identifies it if it is a vowel or consonant */
int main(void)
{
	char input; // Variable declaration
	printf("enter a letter in the Alphabet to identify if it is a vowel or consonant: "); //Asks the user for an input letter
	scanf("%c", &input); // Waits for the user to enter a letter
	switch (input) // This switch statement identifies which letter the user chose (based on the ASCII Table) and identifies it if a vowel or a consonant
	{
	case 65:
		printf("\nYou input the letter %c\n", input);
		printf("%c is a Vowel. Example: Apple\n", input);
		break;
	case 97:
		printf("\nYou input the letter %c\n", input);
		printf("%c is a Vowel. Example: Apple\n", input);
		break;
	case 69:	
		printf("\nYou input the letter %c\n", input);
		printf("%c is a Vowel. Example: Elementary\n", input);
		break;
	case 101:
		printf("\nYou input the letter %c\n", input);
		printf("%c is a Vowel. Example: Elementary\n", input);
		break;
	case 73:	
		printf("\nYou input the letter %c\n", input);
		printf("%c is a Vowel. Example: India\n", input);
		break;
	case 105:
		printf("\nYou input the letter %c\n", input);
		printf("%c is a Vowel. Example: India\n", input);
		break;
	case 79:	
		printf("\nYou input the letter %c\n", input);
		printf("%c is a Vowel. Example: Orangutan\n", input);
		break;
	case 111:
		printf("\nYou input the letter %c\n", input);
		printf("%c is a Vowel. Example: Orangutan\n", input);
		break;
	case 85:	
		printf("\nYou input the letter %c\n", input);
		printf("%c is a Vowel. Example: Uganda\n", input);
		break;
	case 117:
		printf("\nYou input the letter %c\n", input);
		printf("%c is a Vowel. Example: Uganda\n", input);
		break;
	default:
		printf("\nYou input the letter %c\n", input);
		printf("%c is a Consonant.\n", input);
		break;
	
	}
	return 0;
}
