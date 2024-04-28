#include <stdio.h.>
#include <stdlib.h>
#include <time.h>

void printMessage();

float averageScores(int firstScore, int secondScore);

float averageScoreArray(int scores[], int count);

#define _CRT_SERCURE_NO_WARNINGS

int main(int argc, char** argv)
{
	int score1 = 100;
	int score2 = 99;
	int scores[] = { 98, 99, 100 };


	float averageScore = averageScores(score1, score2);

	printf("Average of %d and %d: %.2f\n", score1, score2, averageScore);

	printf("Average of scores in array: %.2f\n", averageScoreArray(scores, (sizeof(scores) / sizeof(scores[0])));
	return (EXIT_SUCCESS);
}

float averageScoreArray(int scores[], int count)
{
	int sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += scores[i];
	}
	return (float)sum / count;
}

float averageScores(int firstScore, int secondScore)
{
	return (float)(firstScore + secondScore) / 2;
}


int getRandom()
{
	return rand();
}

void printMessage()
{
	printf("welcome\n\n");
	printf("This was output by a function");
}