/* This program computes the surface area and volume of a sphere and cylinder */
#include <stdio.h>


int main(void)
{
	const float PI = 3.1416;     // Declaration of variables and constant
	float sphereR;
	float cylinderR;
	float cylinderH;
	float sAreasphere;
	float sAreacylinder;
	float volumeSphere;
	float volumeCylinder;

	printf("What is the radius of the sphere?\n"); // User input of radius of sphere
	scanf("%f", &sphereR);

	printf("\n What is the radius and height of the cylinder? Enter the radius first and the height afterwards. \n Separate it with a comma (e.g. 21, 31)\n"); //User input of radius and heigt of cylinder
	scanf("%f, %f", &cylinderR, &cylinderH);
	
	sAreasphere = 4 * PI * sphereR * sphereR;  		// Computation of surface area and volume of sphere and cylinder
	sAreacylinder = (2 * PI * cylinderR * cylinderR) + (2 * PI * cylinderR * cylinderH);
	volumeSphere = (1.333333333 * PI) * (sphereR * sphereR * sphereR);
	volumeCylinder = (PI * cylinderR * cylinderR) * cylinderH;
	
	printf("Given values:\n radius of sphere =  %f,\n radius of cylinder = %f, height of cylinder = %f\n", sphereR, cylinderR, cylinderH); // Printing to screen the computed surface area and volume values of sphere and cylinder
	printf("Outputs: \n Surface area of sphere = %f,  Volume of sphere = %f\n, Surface area of cylinder = %f, Volume of cylinder = %f\n", sAreasphere, volumeSphere, sAreacylinder, volumeCylinder); 
	
}


