/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  Graded Exercise 2
 */

#include <stdio.h>
#include <stdlib.h>

 /*
  *
  */
int main(int argc, char** argv)
{
	int youngAge = 2022 - 2006;
	int oldAge = 2022 - 1963;
	int diffBetween = oldAge - youngAge;
	int sum = youngAge + oldAge;
	int ratio = oldAge / youngAge;

		printf("%d",youngAge);
		printf("\n%d", oldAge);
		printf("\n%d", diffBetween);
		printf("\n%d", sum);
		printf("\n%d", ratio);



}
