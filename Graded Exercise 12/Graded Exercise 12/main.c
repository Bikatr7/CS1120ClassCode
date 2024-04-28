#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <conio.h>
#include <ctype.h>

#include<windows.h>

int getValidShiftRange();

char getValidShiftDirection();
char getValidMessage(char* message, int messageSize);
char* encryptMessage(char* message, int messageSize, char shiftDirection, int shiftRange);
char* decryptMessage(char* message, int messageSize, char shiftDirection, int shiftRange);

int main(int argc, char** argv)
{
	char shiftDirection;
	char og_msg[100] = "01213"; // pre-initalize so if statement prompts to fix it


	int shiftRange;
	int og_msg_len = strnlen(og_msg, sizeof(og_msg)) - 1; // inital length of og_msg

	bool valid = false;

	shiftDirection = getValidShiftDirection();
	system("cls");

	shiftRange = getValidShiftRange();
	system("cls");

	og_msg, og_msg_len = getValidMessage(og_msg, og_msg_len);
	system("cls");

	char* e_msg = encryptMessage(og_msg, og_msg_len,shiftDirection,shiftRange);
	char* d_msg = decryptMessage(e_msg, og_msg_len, shiftDirection, shiftRange);



	printf("Shift Direction : %c\nShift Range : %d\nOrginal Message : %s\nEncrypted Message : %s\nDecrypted Message : %s\n", shiftDirection, shiftRange, og_msg, e_msg, d_msg);
}

char* decryptMessage(char* e_msg, int og_msg_len, char shiftDirection, int shiftRange)
{
	char* d_msg = malloc((og_msg_len + 1) * sizeof(char));
	for (int i = 0; i < og_msg_len; i++)
	{
		if (shiftDirection == 'r')
		{
			d_msg[i] = e_msg[i] - shiftRange;
		}
		else
		{
			d_msg[i] = e_msg[i] + shiftRange;
		}

		if (d_msg[i] > 'Z')
		{
			d_msg[i] -= 'Z' - 'A' + 1;

		}
		else if (d_msg[i] < 'A')
		{
			d_msg[i] -= 'A' - 'Z' - 1;
		}
	}
	d_msg[og_msg_len] = '\0';
	return d_msg;
}
char* encryptMessage(char* og_msg, int og_msg_len, char shiftDirection, int shiftRange)
{
	char* e_msg = malloc((og_msg_len + 1) * sizeof(char));

	for (int i = 0; i < og_msg_len; i++)
	{
		if (shiftDirection == 'r')
		{
			e_msg[i] = og_msg[i] + shiftRange;
		}
		else
		{
			e_msg[i] = og_msg[i] - shiftRange;
		}

		if (e_msg[i] > 'Z')
		{
			e_msg[i] -= 'Z' - 'A' + 1;

		}
		else if (e_msg[i] < 'A')
		{
			e_msg[i] -= 'A' - 'Z' - 1;
		}
	}
	e_msg[og_msg_len] = '\0';

	return e_msg;
}


char getValidMessage(char* og_msg, int og_msg_len)
{
	bool valid = false;

	while (!valid)
	{
		valid = true;

		for (int i = 0; i < og_msg_len; i++)
		{
			if (isalpha(og_msg[i]))
			{
				og_msg[i] = toupper(og_msg[i]);

			}
			else if (!isspace(og_msg[i]))
			{
				system("cls");
				printf("Invalid Msg\nPlease re-input : \n");
				fgets(og_msg, sizeof(og_msg), stdin);

				og_msg_len = strnlen(og_msg, sizeof(og_msg)) - 1;
				valid = false;
				break;


			}


		}

	}

	return og_msg, og_msg_len;
}
int getValidShiftRange()
{
	int input;
	while (true)
	{
		printf("Input Shift Range and Message : \n");
		scanf_s("%d\n", &input);

		if (input <= 25 && input >= 1)
		{
			break;
		}
		else
		{
			system("cls");
			printf("Invalid Shift Range\n");

		}

	}

	return input;
}


char getValidShiftDirection()
{
	char input;

	while (true)
	{
		printf("Input Shift Direction : \n");
		scanf_s("%c", &input);

		input = tolower(input);
		if (input == 'l' || input == 'r')
		{
			break;

		}
		else
		{
			system("cls");
			printf("Invalid Shift Direction\n");
		}

	}

	return input;
}