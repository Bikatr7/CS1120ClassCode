/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  Programming Assignment 1
 */

 /*
 * Calculates the maximum height and horizontal distance
 * for a shell given an initial angle and speed
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#define G 9.81
#ifndef M_PI
	#define M_PI 3.14159265358979323846f
#endif

float getFloat()
{
	float number;
	scanf_s("%f", &number);
	return number;
}

int main(int argc, char** argv)
{
	float theta = getFloat() * (M_PI / 180.0);
	float speed = getFloat();

	float velocityX = speed * cosf(theta);
	float velocityY = speed * sinf(theta);
	float time = velocityY / G;

	float height = ((velocityY * velocityY) / (G * 2));
	float horDistance = velocityX * (time * 2);


	printf("\n%.4f",height);
	printf(",");
	printf("%.4f", horDistance);

}
