/*Header file for ME05_2_Moyco.c*/
#define PI 3.1416 // Macro definition

float get_spherevolume(int radius) // Function for sphere volume
{
	float sV =  (4*PI*(radius*radius*radius))/3;
	return sV;
}




float get_spheresurfacearea(int radius) // Function for sphere surface area
{
	float sSA =  4*PI*radius*radius;
	return sSA;
}
float get_cylindervolume(int radius, int height)// Function for cylinder volume
{
	float cV =  PI*(radius*radius)*height;
	return cV;
}

float get_cylindersurfacearea(int radius, int height)//Function for cylinder surface area
{
	float cSA1 =  2*PI*radius*height;
	float cSA2 =  2*PI*radius*radius;
	float cSA =  cSA1 + cSA2;
	return cSA;
}



