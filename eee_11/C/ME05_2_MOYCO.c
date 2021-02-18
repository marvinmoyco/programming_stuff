/* This program calculates the volume and surface area of a sphere and a cylinder*/
#include <stdio.h>
#include "get_equations.h" // Header file

int main()
{
	int cRadius, sRadius, cHeight; // Variable declaration
	float sphereV, sphereSA, cylinderV, cylinderSA;
	printf("Please enter the radius of sphere: "); // Waits user input
	scanf("%d", &sRadius);
	printf("\nPlease enter the radius of cylinder: ");
	scanf("%d", &cRadius);
	printf("\nPlease enter the height of the cylinder: ");
	scanf("%d", &cHeight);
	if ((cRadius > 0 && sRadius > 0) && cHeight > 0) // Checks if the input is positive
	{
		sphereV = get_spherevolume(sRadius); // Calls the function to calculate the volume and surface area and to return the value to the float variables
		sphereSA = get_spheresurfacearea(sRadius);
		cylinderV = get_cylindervolume(cRadius, cHeight);
		cylinderSA = get_cylindersurfacearea(cRadius, cHeight);
		printf("\nSphere radius: %d\n", sRadius);// Prints the input
		printf("\nCylinder radius: %d, Cylinder height: %d\n", cRadius, cHeight);
		printf("Sphere Volume: %f, Sphere Surface Area: %f\n", sphereV, sphereSA);// Prints the output
		printf("Cylinder Volume: %f, Cylinder Surface Area: %f\n", cylinderV, cylinderSA);
	}
	else
	{
		printf("Invalid input");
	}
	return 0;
}
