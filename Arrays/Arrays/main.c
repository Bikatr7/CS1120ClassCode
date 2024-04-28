/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  Arrays
 */

#define _CRT_NO_SECURE_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 /*
  *
  */
int main(int argc, char** argv)
{
	int scores[5];
	int sum = 0;
	int size = sizeof(scores) / sizeof(scores[0]);

	float mean = 0.0;
	float sum_of_squared_diff = 0.0;
	float stan_diff = 0.0;

	printf("\nTotal array size: %lu\n", sizeof(scores));

	printf("Array element size: %lu\n", sizeof(scores[0]));

	printf("Number of array elements: %lu\n", size);

	for(int i = 0; i < size; i++)
	{
		printf("Enter score %d (0-100): ", i + 1);
		scanf_s("%d", &scores[i]);
		while (scores[i] < 0 || scores[i] > 100)
		{
			printf("\nScore must be between 0 and 100\nEnter score %d (0-100) : ", i + 1);
			scanf_s("%d", &scores[i]);

		}
	}

	for (int i = 0; i < size; i++)
	{
		printf("Score %d is %d\n", i + 1, scores[i]);
		sum += scores[i];

	}

	mean = (float) sum / size;

	for (int i = 0; i < size; i++)
	{
		sum_of_squared_diff += powf(scores[i] - mean, 2);
	}

	stan_diff = sqrtf(sum_of_squared_diff / (size-1));

	printf("Mean: %.2f\n", mean);
	printf("Standard Deviation %.2f\n", stan_diff);
}