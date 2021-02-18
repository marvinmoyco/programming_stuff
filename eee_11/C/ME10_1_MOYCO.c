/*This program switches the values of integer A and B through the use of pointers */
#include <stdio.h>

void exchange(int* A, int* B);  //Function prototype

int main()
{
    int A = 0;  //Variable declaration
    int B = 0;
    printf("Please input the value of integer A: ");    //Getting of inputs of A and B
    scanf("%d", &A);
    printf("\nPlease input the value of integer B: ");
    scanf("%d", &B);
    printf("\n");
    exchange(&A, &B);   //Function call for the exchange function
    printf("Exchanged: A = %d and B = %d\n", A, B); //Prints out the switched value
    return 0;
    
}

void exchange(int* A, int* B)
{
    int temp=0; //Variable declaration
    temp = *A;  //temp temporarily stores the value of A
    *A = *B;    //The new value of A will be the value of B
    *B = temp;  //The new value of B will be the value of temp
    
}
