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
	int userA = 0;
	float average = 0;
	int count = 0;

	while(1)		
	{	
		scanf_s("%d", &userA);
		if(userA >= 0)
		{
			average += (float) userA;
			count += 1;
		}
		else if(userA == -1)
		{
			break;
		}

	}

	if(count == 0)
	{
		printf("NO INPUT");
	}
	else
	{
		average = average / (float)count;
		printf("%d %.2f", count, average);
		printf("\n");
	}
}
