/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  Graded Exercise 5
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

 /*
 * Graded Exercise 5
 */





int main(int argc, char** argv)
{
	int chosen = 77;
	int guess = 0;
	int count = 3;

	printf("This is a guessing game.\n");
	printf("I have chosen a number between 1 and 100 which you must guess.\n");

	for(; count > 0;--count)
	{
		printf("You have %d tries left.\n", count);
		printf("Enter a guess:\n");
		scanf_s("%d", &guess);

		if(guess == chosen)
		{
			printf("Congratulations. You guessed it.\n");
			return 0;
		}
		else if (guess < 1 || guess > 100) 
		{
			printf("I said the number is between 1 and 100.\n");
		}
		else 
		{
			if (chosen > guess)
			{
				printf("Sorry, %d is wrong. My number is greater than that\n", guess);
			}
			else
			{
				printf("Sorry, %d is wrong. My number is less than that.\n", guess);
			}

		}
	}

	printf("You had three times but you used them all, you have failed the number wa %d.\n",chosen);
}


	