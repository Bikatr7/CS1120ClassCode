/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  SpeedAndDirection
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
	int score = -1;

	while (score < 0 || score > 100) 
	{
		printf("Enter test score (0-100): \n");
		scanf_s("%d", &score);

	}



	
	/*int i, n;
	i = 0;
	printf("Enter any number\n");
	scanf_s("%d", &n);

	while(i <= n)
	{	
		printf("%d\n", i);
		i = i + 1;

	}
	*/
	
	
	
	
	/*for (int i = 1; i <= 10; i++)
	{
		printf("%5d", i);
	};

	printf("\n\n");
	for (int i = 1; i <= 10; i++)
	{
		printf("%5d", i);
		for(int ii =1; ii <= 10; ii++)
		{
			printf("%5d", ii * i);
		}
		printf("\n");
	}; */
}