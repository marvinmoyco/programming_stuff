/* This program calculates the bitwise AND (&), OR (|), Left Shift (<<), and Right Shift (>>) of two integers and prints out the decimal and binary equivalent.*/
#include <stdio.h>

int main()
{
    int input1 = 0;//Variable declaration
    int input2 = 0;
    int bitwand = 0;
    int bitwor = 0;
    int bitwls = 0;
    int bitwrs = 0;
    int q1=0;
    int q2=0;
    int q3=0;
    int q4 = 0;
    int i = 0;
    unsigned short int binand[20]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    unsigned short int binor[20]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    unsigned short int binleft[20]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    unsigned short int binright[20]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    printf("Please enter the 1st integer: ");//Gets the 2 input integer
    scanf(" %i", &input1);
    printf("\nPlease enter the 2nd integer: ");
    scanf(" %i", &input2);
    
    if(((input1 >=0) && (input1 <= 65535)) && ((input2 >=0) && (input2<=65535)))//Sets the range of the input
    {
        bitwand = input1 & input2;//Calculates the bitwise AND of input 1 and 2
        bitwor = input1 | input2;//Calculates the bitwise OR of input 2 and 2
        bitwls = input1 << 4; //Calculates the Left shift by 4 of input 1
        bitwrs = input2 >> 4; // Calculates the right shift by 4 of input 2
        
        
        i=1;                   //Converts the decimal value of the result of bitwise AND into binary 
        binand[0] = bitwand%2;
        q1 = bitwand/2;
        do{
            binand[i] = q1%2;
            q1 = q1/2;
            i=i+1;
        }while(q1 !=0);
        
        
        
        
        i=1;                 //Converts the decimal value of the result of bitwise OR into binary
        binor[0] = bitwor%2;
        q2 = bitwor/2;
        do{
            binor[i] = q2%2;
            q2 = q2/2;
            i=i+1;
        }while(q2 !=0);
        
        
        
        
        i=1;                   // Converts the decimal value of the result of left shift by 4 into binary
        binleft[0] = bitwls%2;
        q3 = bitwls/2;
        do{
            binleft[i] = q3%2;
            q3 = q3/2;
            i=i+1;
        }while(q3 !=0);
        
        
        i=1;                   // Converts the decimal value of the result of the right shift by 4 into binary
        binright[0] = bitwrs%2;
        q4 = bitwrs/2;
        do{
            binright[i] = q4%2;
            q4 = q4/2;
            i=i+1;
        }while(q4 !=0);
        
        printf("\nDecimal Form (Base 10): \n");   //Prints out the Decimal values of the different bitwise operators
        printf("Bitwise AND of input 1 and input 2 = %d\n", bitwand);
        printf("Bitwise OR of input 1 and input 2 = %d\n", bitwor);
        printf("Left Shift by 4 on input 1 = %d\n",bitwls);
        printf("Right Shift by 4 on input 2 = %d\n",bitwrs);
        printf("\n");
        printf("\n Binary Form (Base 2): \n");   // Prints out the Binary values of the different bitwise operators
        printf("Bitwise AND of input 1 and input 2 = ");
        for(i=19;i>=0;i--)
        {
            printf("%d", binand[i]);
        }
        printf("\n");
        printf("Bitwise OR of input 1 and input 2 = ");
         for(i=19;i>=0;i--)
        {
            printf("%d", binor[i]);
        }
        printf("\n");
        printf("Left Shift by 4 on input 1 = ");
         for(i=19;i>=0;i--)
        {
            printf("%d", binleft[i]);
        }
        printf("\n");
        printf("Right Shift by 4 on input 2 = ");
         for(i=19;i>=0;i--)
        {
            printf("%d", binright[i]);
        }
        printf("\n");
        
        

    
    
    
    
    
    
        
    }
    else
    {
        printf("Invalid Input"); // Prints if the input is out of range.
    }
    return 0;
}
