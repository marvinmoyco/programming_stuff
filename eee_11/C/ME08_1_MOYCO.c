/* This program converts the input hexadecimal number to its octal and binary equivalent numbers */
#include <stdio.h>
#include <string.h>

int main()
{
    char input[4];//Variable Declaration
    int i=0;
    unsigned short int hexval[4]={0,0,0,0};
    //unsigned short int decival[5];
    unsigned short int octval[6]={0,0,0,0,0,0};
    unsigned short int binval[16]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    unsigned short int temp[4] = {0,0,0,0};
    int sumdec=0;
    int quot=0;
    int quot1=0;
    int len=0;
    //int d1,d2,d3,d4 = 0;
    //int r1,r2,r3,r4 = 0;
    printf("Please enter a hexadecimal number (Base 16): ");//Waiting for string input

    scanf("%s", input);
    len = strlen(input);//Gets how many elements are stored in the input array
   //printf("\n The length of string is %d\n", len);
    printf("\nThe input hexadecimal number: ");
    for(i=0;i<len;i++)// Converts the char elements into its hexadecimal value based on the ASCII table
    {
        switch(input[i]){
            case 48:
            hexval[i] = 0;
            break;
            case 49:
            hexval[i] = 1;
            break;
            case 50:
            hexval[i] = 2;
            break;
            case 51:
            hexval[i] = 3;
            break;
            case 52:
            hexval[i] = 4;
            break;
            case 53:
            hexval[i] = 5;
            break;
            case 54:
            hexval[i] = 6;
            break;
            case 55:
            hexval[i] = 7;
            break;
            case 56:
            hexval[i] = 8;
            break;
            case 57:
            hexval[i] = 9;
            break;
            case 65:
            case 97:
            hexval[i] = 10;
            break;
            case 66:
            case 98:
            hexval[i] = 11;
            break;
            case 67:
            case 99:
            hexval[i] = 12;
            break;
            case 68:
            case 100:
            hexval[i] = 13;
            break;
            case 69:
            case 101:
            hexval[i] = 14;
            break;
            case 70:
            case 102:
            hexval[i] = 15;
            break;
            default:
            break;
        }
        //printf("\nThe string number %d is %c\n",i+1, input[i]);
        //printf("\nThe hex number %d is %x\n",i+1, hexval[i]);
        printf("%x",hexval[i]); //Prints the hexadecimal value
    }

    for(i=len-1;i>=0;i--)   //Converts the hexadecimal to its decimal (Base 10) equivalent.
    {
        if(len == 4)
        {
            switch(i)
            {
                case 0:
                temp[i] = ((hexval[i]*16)*16)*16;
                break;
                case 1:
                temp[i] = (hexval[i]*16)*16;
                break;
                case 2:
                temp[i] = hexval[i]*16;
                break;
                case 3:
                temp[i] = hexval[i]*1;
                break;
                default:
                break;
            }
            //printf("%d\n", temp[i]);
        }
        else if(len == 3)
        {
            switch(i)
            {
                case 0:
                temp[i] = (hexval[i]*16)*16;
                break;
                case 1:
                temp[i] = hexval[i]*16;
                break;
                case 2:
                temp[i] = hexval[i]*1;
                break;
                default:
                break;
            }
            //printf("%d\n", temp[i]);
        }
        else if(len == 2)
        {
            switch(i)
            {
                case 0:
                temp[i] = hexval[i]*16;
                break;
                case 1:
                temp[i] = hexval[i]*1;
                break;
                default:
                break;
            }
           // printf("%d\n", temp[i]);
        }
        else if(len == 1)
        {
            switch(i)
            {
                case 0:
                temp[i] = hexval[i]*1;
                break;
                default:
                break;
            }
            //printf("%d\n", temp[i]);
        }
    }
    for(i=0;i<len;i++) // Gets the sum of the temp array to get the decimal equivalent
    {
        sumdec = sumdec+temp[i];
    }
    /*printf("%d\n", sumdec);
    d1 = sumdec/10000;
    r1 = sumdec%10000;
    d2 = r1/1000;
    r2 = r1%1000;
    d3 = r2/100;
    r3 = r2%100;
    d4 = r3/10;
    r4 = r3%10;
    decival[0] = d1;
    decival[1] = d2;
    decival[2] = d3;
    decival[3] = d4;
    decival[4] = r4;
    for(i=0;i<5;i++)
    {
        printf("%d", decival[i]);
    }*/
    printf("\n");
    i=1;
    octval[0] = sumdec%8; // Converts the decimal number to its octal equivalent
    quot = sumdec/8;
    do{
        octval[i] = quot%8;
        quot = quot/8;
        i=i+1;
    }while(quot !=0);
    printf("\nThe octal (Base 8) number equivalent: ");
    for(i=5;i>=0;i--)// Prints the octal equivalent
    {
        printf("%d", octval[i]);
    }
    printf("\n");
    i=1;
    binval[0] = sumdec%2;  // Gets the binary equivalent of the decimal number
    quot1 = sumdec/2;
    do{
        binval[i] = quot1%2;
        quot1 = quot1/2;
        i=i+1;
    }while(quot1 !=0);
    printf("\nThe binary (Base 2) number equivalent: ");
    for(i=15;i>=0;i--) // Prints the binary equivalent
    {
        printf("%d", binval[i]);
    }
    printf("\n");
    
    return 0;
}