/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  Graded Exercise 3
 */

#include <stdio.h>
#include <stdlib.h>

 /*
  *
  */
int main(int argc, char** argv)
{
	int score = 29586;
	int max_score = 150000;
	float percent = ((float)score / (float)max_score) * 100;

	printf("%d", score);
	printf("\n%.2f", percent);
	printf("\n%d", (int)percent);




}
