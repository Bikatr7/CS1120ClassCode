/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  IFStatements
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
	char answer;

	printf("Do you like pizza (y or n)?\n");
	scanf_s("%c", &answer);

	if (answer == 'y' || answer == 'Y')
	{
		printf("That's great! I like pizza too.\n");
	}
	else if(answer == 'n' || answer == 'N')
	{
		printf("That's okay, I'll eat enough for both of us.\n");
	}
	else
	{
		printf("I said y or n!!!\n");
	}

}
