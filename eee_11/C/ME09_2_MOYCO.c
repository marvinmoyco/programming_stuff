/* This program checks the average of the scores and prints the name and score of the highest and lowest scorers */
#include <stdio.h>

struct grades // Structure declaration
    {
      char name[15];
      float score;
    };

int main()
{
    
    struct grades student1, student2, student3, student4, student5; // Variable declarations
    int i,j;
    float input[5] = {0,0,0,0,0};
    float average=0;
    float temp = 0;
    printf("Please enter the name of the first student: "); // Input gathering
    scanf("%s", (student1.name));
    printf("\nPlease enter the score of the first student: ");
    scanf("%f", &(student1.score));
    
    printf("\nPlease enter the name of the second student: ");
    scanf(" %s", (student2.name));
    printf("\nPlease enter the score of the second student: ");
    scanf(" %f", &(student2.score));
    
    printf("\nPlease enter the name of the third student: ");
    scanf(" %s", (student3.name));
    printf("\nPlease enter the score of the third student: ");
    scanf(" %f", &(student3.score));
    
    printf("\nPlease enter the name of the fourth student: ");
    scanf(" %s", (student4.name));
    printf("\nPlease enter the score of the fourth student: ");
    scanf(" %f", &(student4.score));
    
    printf("\nPlease enter the name of the fifth student: ");
    scanf(" %s", (student5.name));
    printf("\nPlease enter the score of the fifth student: ");
    scanf(" %f", &(student5.score));
    
    printf("\n");
    
    average = (float) (student1.score + student2.score + student3.score + student4.score + student5.score) / 5; // Gets the average of all of the scores
    
    printf("The average of the 5 scores is %f\n", average); // Prints out the average of the scores 
    input[0] = (student1.score); // Stores the scores in an array to be arranged from least value to greatest value
    input[1] = (student2.score);
    input[2] = (student3.score);
    input[3] = (student4.score);
    input[4] = (student5.score);
    
    for(j = 0; j<5; j++)// Nested for loop that rearranges the floating points based on their value
	{
		for(i=0;i<j;i++)
		{
			if(input[i] > input[j])
			{ 
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
			
		}
	}
	
	if(input[0] == (student1.score)) // If statements that check if the input[0] or the lowest score is equal to one of the students' scores and prints out that student's name and score (which is the lowest)
	{
	    printf("\nThe student who got the lowest score is ");
        puts(student1.name);
        printf(" and his/her score is %f\n", student1.score);
	}
	if(input[0] == (student2.score))
	{
	    printf("\nThe student who got the lowest score is ");
        puts(student2.name);
        printf(" and his/her score is %f\n", student2.score);
	}
	if(input[0] == (student3.score))
	{
	    printf("\nThe student who got the lowest score is ");
        puts(student3.name);
        printf(" and his/her score is %f\n", student3.score);
	}
	if(input[0] == (student4.score))
	{
	    printf("\nThe student who got the lowest score is ");
        puts(student4.name);
        printf(" and his/her score is %f\n", student4.score);
	}
	if(input[0] == (student5.score))
	{
	    printf("\nThe student who got the lowest score is ");
        puts(student5.name);
        printf(" and his/her score is %f\n", student5.score);
	}
	
	
	
	if(input[4] == (student1.score)) // Finds whose score is the greatest by comparing the last element of the arranged array to all of the student's scores and prints that student's name and score if the last element of the array (greatest value) is equal to the score of the student being compared
	{
	    printf("\nThe student who got the highest score is ");
        puts(student1.name);
        printf(" and his/her score is %f\n", student1.score);
	}
	if(input[4] == (student2.score))
	{
	    printf("\nThe student who got the highest score is ");
        puts(student2.name);
        printf(" and his/her score is %f\n", student2.score);
	}
	if(input[4] == (student3.score))
	{
	    printf("\nThe student who got the highest score is ");
        puts(student3.name);
        printf(" and his/her score is %f\n", student3.score);
	}
	if(input[4] == (student4.score))
	{
	    printf("\nThe student who got the highest score is ");
        puts(student4.name);
        printf(" and his/her score is %f\n", student4.score);
	}
	if(input[4] == (student5.score))
	{
	    printf("\nThe student who got the highest score is ");
        puts(student5.name);
        printf(" and his/her score is %f\n", student5.score);
	}
  
    /*
    if((((student1.score < student2.score) && (student1.score < student3.score)) && (student1.score < student4.score)) && (student1.score < student5.score))
    {
        printf("\nThe student who got the lowest score is ");
        puts(student1.name);
        printf(" and his/her score is %f\n", student1.score);
    }
    else if((((student2.score < student1.score) && (student2.score < student3.score)) && (student2.score < student4.score)) && (student2.score < student5.score))
    {
        printf("\nThe student who got the lowest score is ");
        puts(student2.name);
        printf(" and his/her score is %f\n", student2.score);
    }
    else if((((student3.score < student1.score) && (student3.score < student2.score)) && (student3.score < student4.score)) && (student3.score < student5.score))
    {
        printf("\nThe student who got the lowest score is ");
        for(i=0;i<10;i++)
        puts(student3.name);
        printf(" and his/her score is %f\n", student3.score);
    }
    else if((((student4.score < student1.score) && (student4.score < student2.score)) && (student4.score < student3.score)) && (student4.score < student5.score))
    {
        printf("\nThe student who got the lowest score is ");
        puts(student4.name);
        printf(" and his/her score is %f\n", student4.score);
    }
    else if((((student5.score < student1.score) && (student5.score < student2.score)) && (student5.score < student3.score)) && (student5.score < student4.score))
    {
        printf("\nThe student who got the lowest score is ");
        puts(student5.name);
        printf(" and his/her score is %f\n", student5.score);
    }
    else{
        printf("Error in finding the lowest score\n");
        return 0;
    }
    
    
    
    
    
    
    
    if((((student1.score > student2.score) && (student1.score > student3.score)) && (student1.score > student4.score)) && (student1.score > student5.score))
    {
        printf("\nThe student who got the highest score is ");
        puts(student1.name);
        printf(" and his/her score is %f\n", student1.score);
    }
    else if((((student2.score > student1.score) && (student2.score > student3.score)) && (student2.score > student4.score)) && (student2.score > student5.score))
    {
        printf("\nThe student who got the highest score is ");
        puts(student2.name);
        printf(" and his/her score is %f\n", student2.score);
    }
    else if((((student3.score > student1.score) && (student3.score > student2.score)) && (student3.score > student4.score)) && (student3.score > student5.score))
    {
        printf("\nThe student who got the highest score is ");
        puts(student3.name);
        printf(" and his/her score is %f\n", student3.score);
    }
    else if((((student4.score > student1.score) && (student4.score > student2.score)) && (student4.score > student3.score)) && (student4.score > student5.score))
    {
        printf("\nThe student who got the highest score is ");
        puts(student4.name);
        printf(" and his/her score is %f\n", student4.score);
    }
    else if((((student5.score > student1.score) && (student5.score > student2.score)) && (student5.score > student3.score)) && (student5.score > student4.score))
    {
        printf("\nThe student who got the highest score is ");
        puts(student5.name);
        printf(" and his/her score is %f\n", student5.score);
    }
    else{
        printf("Error in finding the highest score\n");
        return 0;
    }*/

    
    return 0;
}
