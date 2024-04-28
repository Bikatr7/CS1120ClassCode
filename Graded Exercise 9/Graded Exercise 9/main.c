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
	int high;
	int count = 0;

	while (userA != -1)
	{
		scanf_s("%d", &userA);
		if(userA == -1)
		{
			break;

		}
		if(count == 0 || high < userA)
		{
			high = userA;

		}
		count++;
	}
	if (count != 0)
	{
		printf("%d", high);
	}
	else
	{
		printf("NO INPUT");
	}
}	
