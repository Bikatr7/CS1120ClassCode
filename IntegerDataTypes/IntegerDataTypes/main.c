/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  IntegerDataTypes
 */

#include <stdio.h>
#include <stdlib.h>

#define MINUTES_PER_HOUR  60;
 /*
  *
  */
int main(int argc, char** argv)
{
	int totalMinutes = 113;

	// calculate and print hours
	int hours = totalMinutes / MINUTES_PER_HOUR;

	printf("Hours : %d\n", hours);
	printf(hours);

	// calculate and print minutes
	int minutes = totalMinutes % MINUTES_PER_HOUR;

	printf("Minutes : %d\n", minutes);

}
