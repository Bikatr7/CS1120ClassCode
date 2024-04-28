/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  9-12-22
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS

 /*
  *
  */
int main(int argc, char** argv)
{
	float x = 0.0;

	printf("Enter floating-point number : ");
	scanf_s("%f", &x);

	printf("Floor: %d\n", (int)x);

	printf("Ceiling: %d\n", (int)(x + 0.99));

	float p1x;
	float p1y;
	float p2x;
	float p2y;
	float distance;

	printf("Enter x for the first point: ");
	scanf_s("%f", &p1x);
	printf("\nEnter y for the first point: ");
	scanf_s("%f", &p1y);
	printf("\nEnter x for the second point: ");
	scanf_s("%f", &p2x);
	printf("\fEnter y for the second point: ");
	scanf_s("%f", &p2y);

	distance = sqrtf(powf((p1x - p2x), 2) + powf((p1y - p2y), 2));
	printf("Distance between points : %.2f", distance);
}	
