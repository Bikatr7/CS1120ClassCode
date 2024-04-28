/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  Graded Exercise 4
 */

#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

 /*
  *
  */
int main(int argc, char** argv)
{
	float user_f = 0.0;
	float calculated_c = 0.0;
	float calculated_f = 0.0;

	scanf_s("%f", &user_f);

	calculated_c = (user_f - 32.0) / 9.0 * 5.0;
	calculated_f = (calculated_c) * 9.0 / 5.0 + 32.0;

	printf("%f", calculated_c);
	printf("\n%f", calculated_f);




}
