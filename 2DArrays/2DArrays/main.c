#define _CRT_NO_SECURE_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{

	int first_matrix[2][3] = { {1,2,3},{4,5,6} };
	int second_matrix[3][2] = { {7,8},{9,10},{11,12} };
	int result_matrix[2][2] = { 0 };

	for(int i = 0; i < 2; i++)
	{
		for (int ii = 0; ii <3; ii++)
		{
			int first_column = 0;
			int second_row = 0;

			for (int iii = 0; iii < 2; iii++)
			{
				result_matrix[i][ii] += first_matrix[i][first_column] * second_matrix[second_row][ii];

				first_column++;
				second_row++;
			}
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int ii = 0; ii < 2; ii++)
		{
			printf("%5d", result_matrix[i][ii]);
		}
		printf("\n");
	}













	/*int table[3][5];
	for (int i = 0; i < 3; i++)
	{
		for (int ii = 0; ii < 5; ii++)
		{
			table[i][ii] = (i + 1) * (ii + 1);

		}

	}


	for (int i = 1; i <= sizeof(table[0]) / sizeof(table[0][0]); i++)
	{
		printf("%5d", i);
	}

	printf("\n");

	for (int i = 1; i <= 3; i++)
	{
		printf("%5d", i);
		for (int ii = 1; ii <= sizeof(table[0]) / sizeof(table[0][0]); ii++)
		{
			printf("%5d", table[i-1][ii-1]);
		}
		printf("\n");
	}
	*/
}