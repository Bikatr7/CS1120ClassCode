/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  FloatingPointDataTypes
 */

#define _CRT_NO_SECURE_WARNINGS

#include <stdio.h>
#include <stdlib.h>

 /*
  \n
  */
int main(int argc, char** argv)
{
	int userI = 0;
	int userMWidth = 0;
	int userRows = 0;

	scanf_s("%d", &userI);


	for (int i = 0; i <= userI; i+=2)
	{
		printf("%d", i);
		printf("\n");
	}

	scanf_s("%d", &userMWidth);

	for (int i = 0; i < userMWidth; i++)
	{
		printf("*");
	}

	printf("\n");
	scanf_s("%d", &userMWidth);
	scanf_s("%d", &userRows);

	for (int i = 0; i < userRows; i++)
	{
		for (int i = 0; i < userMWidth; i++)
		{
			printf("*");
		}

		printf("\n");
	}
}
