/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  FloatingPointDataTypes
 */

#define _CRT_NO_SECURE_WARNINGS

#include <stdio.h>
#include <stdlib.h>

 /*
  *
  */
int main(int argc, char** argv)
{

	int width;
	int height;

	printf("Enter width \n");
	scanf_s("%d", &width);

	while(width < 3 || width > 20)
	{
		printf("\nWidth must be between 3 and 20");
		printf("\nEnter width \n");
		scanf_s("%d", &width);
	}

	printf("Enter height \n");
	scanf_s("%d", &height);

	while (height < 3 || height > 20)
	{
		printf("\Height must be between 3 and 20");
		printf("\nEnter height \n");
		scanf_s("%d", &height);
	}

	printf("\n");

	for (int i = 0; i < width; i++)
	{
		printf("*");
	};

	printf("\n");

	for (int i = 0; i < height - 2; i++)
	{
		printf("*");
		for (int ii = 0; ii < width - 2; ii++)
		{
			printf(" ");
		};
		printf("*\n");
	};

	for (int i = 0; i < width; i++)
	{
		printf("*");
	};

	/*int score;

	do
	{
		printf("Enter test score (0-100): \n");
		scanf_s("%d", & score);

		if (score < 0 || score > 100)
		{
			printf("\nScore must be between 0 and 100.\n");
		}
	} 
	while(score < 0 || score > 100);
	*/
}
