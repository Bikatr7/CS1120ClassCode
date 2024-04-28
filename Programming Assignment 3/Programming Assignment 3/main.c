/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  Graded Exercise 9
 */

#define _CRT_SECURE_NO_WARNINGS


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include<windows.h>

int main(int argc, char** argv)
{
	char msg[100] = ""; 

	char alphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	int count[26] = {0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	fgets(msg, sizeof(msg), stdin);

	for (int i = 0; i < strlen(msg); i++)
	{
		for (int ii = 0; ii < 26; ii++)
		{
			if (alphabet[ii] == toupper(msg[i]))
			{
				count[ii] += 1;
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if(count[i] > 0)
		{
			printf("%c%d ", alphabet[i], count[i]);
		}
	}

	

}
