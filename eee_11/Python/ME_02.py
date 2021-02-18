#!usr/bin/env python3
#Chebang


import math

def main():
    check = True
    while check:
        mode_input = int(input("Choose a mode: (1) Integer Sign Identification, \n(2) Simple Questionnaire, \n(3) Month Converter, \n(4) Vowel Identifier: "))
        if mode_input >=1 and mode_input <= 4:
            check = False
        else:
            check = True

    if mode_input == 1: # Mode 1 - Integer Sign Identification
        print("Mode selected: Integer Sign Identification...")
        number = int(input("Enter any integer: "))
        if number > 0:
            print("The integer {} is positive!".format(number))
        elif number < 0:
            print("The integer {} is negative!".format(number))
        else:
            print("The integer {} is zero!".format(number))
    elif mode_input == 2: # Mode 2 - Simple Questionnaire
        pass
    elif mode_input == 3: # Mode 3 - Month Converter
        pass
    elif mode_input == 4: # Mode 4 - Vowel Identifier
        pass

if __name__ == "__main__":
    main()