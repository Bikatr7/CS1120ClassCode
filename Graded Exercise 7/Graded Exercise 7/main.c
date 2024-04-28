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
	char userInput;

	printf("**************\nMenu:\nN   New Game\nL   Load Game\nO   Options\nQ   Quit\n**************\n");
	scanf_s("%c", &userInput);

	switch(userInput)
	{
	case 'n':
		printf("Starting");
		break;
	case 'l':
		printf("Loading");
		break;
	case 'o':
		printf("Options");
		break;
	case 'q':
		printf("Quitting");
		break;
	default:
		printf("Invalid");
		break;
	}
}
