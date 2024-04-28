/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  Graded Exercise 5
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*
* Graded Exercise 5
*/

float getFloat()
{
	float number;
	scanf_s("%f", &number);
	return number;
}



int main(int argc, char** argv)
{

	typedef struct point point;
	struct point
	{
		float lat;
		float lon;
	};

		point uccsLoc;

		uccsLoc.lat = 38.8936471;
		uccsLoc.lon = -104.8003126f;

		float userLat = 0.0;

		float userLong = 0.0;

		scanf_s("%f", &userLat);
		scanf_s("%f", &userLong);


		printf("\n%f", uccsLoc.lat - userLat);
		printf(",");
		printf("%f", uccsLoc.lon - userLong);

		return (EXIT_SUCCESS);
}


