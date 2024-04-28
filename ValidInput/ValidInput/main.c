#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int getValidInteger(char promptString[], char errorString[], int lowerBound, int upperBound);

int main(int argc, char** argv)
{
	int n = getValidInteger("How many scores do you want to enter\n", "Number of scores must be between 1 and 10!", 1, 10);

	printf("N is %d", n);

	return (EXIT_SUCCESS);
}

int getValidInteger(char promptString[], char errorString[], int lowerBound, int upperBound)
{
	int input;

	printf(promptString);
	scanf_s("%d", &input);

	while (input < lowerBound || input > upperBound)
	{
		printf(errorString);
		printf("\n");
		printf(promptString);
		scanf_s("%d", &input);
		
	}

	return input;
}