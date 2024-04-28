/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  Graded Exercise 9
 */

#define _CRT_SECURE_NO_WARNINGS


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#include<windows.h>

int getValidInteger(int lBound, int hBound);

float averageIntegerArray(int values[], int count);

int findExtremeInIntegerArray(int minOrMax, int values[], int count);

int main(int argc, char** argv)
{
	const min = 0;
	const max = 1;

	int values[100];
	int numH = 0;
	int i = 0;
	int minValue = 0;
	int maxValue = 0;
	
	float average = 0.0;

	numH = getValidInteger(1, 100);

	while (i < numH)
	{
		values[i] = getValidInteger(1, 96);
		i += 1;
	}

	average = averageIntegerArray(values, numH);

	minValue = findExtremeInIntegerArray(min, values, numH);
	maxValue = findExtremeInIntegerArray(max, values, numH);

	printf("%.2f %d %d", average, minValue, maxValue);


}

int findExtremeInIntegerArray(int minOrMax, int values[], int count)
{
	int extrema = 0;
	int i = 0;

	if (minOrMax == 0)
	{
		extrema = 97;
	}
	else
	{
		extrema = 0;
	}

	while(i < count)
	{
		if (minOrMax == 0 && values[i] < extrema)
		{
			extrema = values[i];
		}
		else if (minOrMax == 1 && values[i] > extrema)
		{
			extrema = values[i];
		}

		i += 1;
	}

	return extrema;
}

float averageIntegerArray(int values[], int count)
{
	int i = 0;
	int total = 0;

	while (i < count)
	{
		total += values[i];
		i += 1;
	}

	return (float)total / (float) count;
}
int getValidInteger(int lBound, int hBound)
{
	int input = hBound + 1;

	while (input > hBound || input < lBound)
	{
		scanf_s("%d", &input);
	}

	return input;
}