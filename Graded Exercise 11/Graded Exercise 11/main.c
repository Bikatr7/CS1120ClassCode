#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <conio.h>
#include <ctype.h>

#include<windows.h>

int main(int argc, char** argv)
{
	char shiftDirection;  
	char og_msg[100] = "01213"; // pre-initalize so if statement prompts to fix it


	int shiftRange;
	int og_msg_len = strnlen(og_msg, sizeof(og_msg)) - 1; // inital length of og_msg
	int e_msg_len; 

	bool valid = false; 




	while (true)
	{
		printf("Input Shift Direction : \n");
		scanf_s("%c", &shiftDirection);

		shiftDirection = tolower(shiftDirection);
		if (shiftDirection == 'l' || shiftDirection == 'r')
		{
			break;

		}
		else
		{
			system("cls");
			printf("Invalid Shift Direction\n");
		}

	}
	system("cls");


	while (true)
	{
		printf("Input Shift Range and Message : \n");
		scanf_s("%d\n", &shiftRange);

		if (shiftRange <= 25 && shiftRange >= 1)
		{
			break;
		}
		else
		{
			system("cls");
			printf("Invalid Shift Range\n");

		}

	}

	while (!valid)
	{
		valid = true;

		for (int i = 0; i < og_msg_len; i++)
		{
			if (isalpha(og_msg[i]))
			{
				og_msg[i] = toupper(og_msg[i]);

			}
			else if(!isspace(og_msg[i]))
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

	char* e_msg = malloc((og_msg_len + 1) * sizeof(char));

	for (int i = 0; i < og_msg_len; i++)
	{
		if(shiftDirection == 'r')
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



	e_msg_len = og_msg_len;

	char* d_msg = malloc((e_msg_len + 1) * sizeof(char));

	for (int i = 0; i < e_msg_len; i++)
	{
		if(shiftDirection == 'r')
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
	d_msg[e_msg_len] = '\0';

	system("cls");

	printf("Shift Direction : %c\nShift Range : %d\nOrginal Message : %s\nEncrypted Message : %s\nDecrypted Message : %s\n", shiftDirection, shiftRange, og_msg, e_msg,d_msg);
}