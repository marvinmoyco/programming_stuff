#!/usr/bin/env python3

import math
import sys

def main():
    check = True
    while check:
        mode_input = int(input("Choose a mode: (1) Factorial Computer, \n(2) Sum and Average, \n(3) Prime Number Detector, \n(4) Multiplication Table\n (5) Age Group: "))
        if mode_input >=1 and mode_input <= 5:
            check = False
        else:
            check = True


    if mode_input == 1: # Mode: Factorial Computer
        print("Mode: Factorial Computer...")
        integer = int(input("Enter an integer from 1 to 12 (inclusive): "))
        if integer >= 1 and integer <=12:
            factorial = 1
            result = 1
            while factorial <= integer:
                result = result * factorial
                factorial += 1
            print("The operation {}! is equal to {}".format(integer,result))
        else:
            print("Invalid input...")
            sys.exit(1)

    elif mode_input == 2: # Mode: Sum and Average
        print("Mode: Sum and Average...")
        iteration =1
        sum = 0
        average = 0
        while True:
            num = int(input("Enter a number: "))
            if num < 0:
                break
            sum = sum + num
            average = sum / iteration

            print("Iteration number {}, Sum: {}, Average: {}".format(iteration,sum,average))
            iteration += 1
            
    elif mode_input == 3: # Mode: Prime Number Detector
        print("Mode: Prime Number Detector...")
        num = int(input("Enter a number (1-1000): "))
        not_prime = False
        if num >=1 and num <= 1000:
            for i in range(int(num/2)):
                if i < 2:
                    continue
                if num%i == 0:
                    not_prime = True
                    break
            if not_prime == False and num != 1:
                print("The number {} is a prime number!".format(num))
            else:
                print("The number {} is not a prime number.".format(num))
        else:
            print("Invalid input.")
    elif mode_input == 4: # Mode: Multiplication Table
        print("Mode: Multiplication Table...")
        rows = int(input("Enter number of rows (1-10): "))
        cols = int(input("Enter number of columns (1-10): "))
        table = []
        # Used Python's lists data structure here to print it in a table-like style.
        if rows >= 1 and rows <= 10 and cols >=1 and cols <= 10:
            for x in range(rows + 1):
                if x == 0:
                    continue
                row = []
                for y in range(cols + 1):
                    if y == 0:
                        continue
                    row.append(x*y)
                table.append(row)
            for i in table:
                print(i)
        else:
            print("Invalid input..")
    elif mode_input == 5: # Mode: Age Group
        print("Mode: Age Group...")
        age = int(input("Enter an age: "))
        if age >= 0:
            if age >=0 and age <= 2:
                print("He/She is Inelligible.")
            if age >=3 and age <=5:
                print("He/She is in Preschool.")
            if age >=3 and age <=4:
                print("He/She is in Nursery.")
            if age == 5:
                print("He/She is in Kindergarten.")
            if age >=6 and age <=11:
                print("He/She is in Elementary.")
            if age >=12 and age <=17:
                print("He/She is in Secondary.")
            if age >=18 and age <=59:
                print("He/She is in Work Force.")
            if age >=18 and age <=22:
                print("He/She is in College.")
            if age >=23 and age <=59:
                print("He/She is in Postgraduate.")
            if age >=60:
                print("He/She is in Senior.")
        else:
            print("Invalid input")
if __name__ == "__main__":
    main()