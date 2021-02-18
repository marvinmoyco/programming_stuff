#!/usr/bin/env python3

# Adding a chebang so the script can run by itself...
# This script assumes that the system is a Linux System (I used Ubuntu)...

import math

def main():
    check = True
    while check:    # While loop lets user select which mode to do.
        s_or_c = input("Select whether sphere (S) or cylinder (C): ").lower()
        if s_or_c == 's':
            check = False
        elif s_or_c == 'c':
            check = False
        else:
            check = True
    print("Assume the units used is meters.")
    if s_or_c == 's':   # Computes for volume and surface area of sphere
        radius = float(input("Enter a radius of the sphere: "))
        volume = (4/3) * math.pi * radius**3 
        surface_area = 4 * math.pi * radius**2
        print("The volume of the sphere (with radius of {} meters) is {} cubic meters while the surface area is {} square meters.".format(radius,volume,surface_area))
    elif s_or_c == 'c': # Computes for volume and surface area of cylinder
        radius = float(input("Enter a radius of the cylinder: "))
        height = float(input("Enter a height of the cylinder: "))
        volume = math.pi * radius**2 * height
        surface_area = (2 * math.pi * radius * height) + (2 * math.pi * radius**2)
        print("The volume of the cylinder (with radius of {} meters and height of {} meters) is {} cubic meters while the surface area is {} square meters.".format(radius,height,volume,surface_area))

if __name__ == "__main__":
    main()


    
