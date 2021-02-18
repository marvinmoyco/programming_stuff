#!usr/bin/env python3
#Chebang


import math
import datetime

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
        print("Mode selected: Simple Questionnaire...")
        answer = input("Question: Who is the Miss Universe 2017 winner?\n a. Philippines\nb. France\nc. Netherlands\nd. Haiti ").lower()
        if answer == "b":
            print("You have chosen the correct answer!")
        elif answer == "a" or answer == "c" or answer == "d":
            print("You have chosen an incorrect answer.")
        else:
            print("Invalid input...")
    elif mode_input == 3: # Mode 3 - Month Converter
        print("Mode selected: Month Converter...")
        month_number = int(input("Choose a month number (1-12): "))
        if month_number >=1 and month_number <= 12:
            month_string = datetime.datetime(2021,month_number,1) # Kinda cheating.. I am using datetime class fo python hehe
            print("The number {} is the month of {}.".format(month_number,month_string.strftime("%B")))
        else:
            print("Invalid input....")
    elif mode_input == 4: # Mode 4 - Vowel Identifier
        print("Mode selected: Vowel Identifier...")
        letter = input("Select a letter: ").lower()
        if letter == 'a' or letter == 'e' or letter == 'i' or letter == 'o' or letter == 'u':
            print("The letter {} is a vowel.".format(letter))
        else: 
            print("The letter {} is a consonant".format(letter))


if __name__ == "__main__":
    main()