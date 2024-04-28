/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  Graded Exercise 9
 */

#define _CRT_NO_SECURE_WARNINGS

#include <stdio.h>
#include <stdlib.h>

 /*
  \n
  */
int main(int argc, char** argv)
{
	int scores[5];
	int userA = 0;
	int max;
	int min;



	for(int i = 0; i <= 4; i++)
	{
		scanf_s("%d", &userA);
		while(userA > 100 || userA < 0)
		{
			scanf_s("%d", &userA);
		}
		scores[i] = userA;
	}

	max = scores[0];
	min = scores[0];

	for (int i = 1; i <= 4; i++)
	{
		if(scores[i] > max)
		{
			max = scores[i];

		}

		if(scores[i] < min)
		{
			min = scores[i];
		}
	}

	printf("%d %d", min, max);
}
