/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  FloatingPointDataTypes
 */

#include <stdio.h>
#include <stdlib.h>

 /*
  *
  */
int main(int argc, char** argv)
{
	int hoursDriven = 5;
	int milesDriven = 262;

	float mph = (float) milesDriven / hoursDriven;

	printf("mph : %.1f\n", mph);
		 
}
