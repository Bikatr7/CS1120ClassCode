/*
* File:   main.c
* Author: Dr. T
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUM_STUDENTS 3

typedef struct Student Student;
struct Student
{
	int number;
	float percent;
	char grade;
};



/*
* Reads student data from a file
*/

int getValidInteger(char promptString[], char errorString[], int lowerBound, int upperBound);
int getValidFloat(char promptString[], char errorString[], float lowerBound, float upperBound);
bool isValid(char character, char validValues[], int count);
void writeStudentToFile(Student student, FILE* file);
void getValidStudentData(Student* student, char validValues[], int count);
char getValidChar(char promptString[], char errorString[], char validValues[], int count);



int main(int argc, char** argv)
{
	Student students[NUM_STUDENTS];
	char validGrades[] = { 'a','b','c','d','f'};

	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		getValidStudentData(&students[i], validGrades, sizeof(validGrades) / sizeof(validGrades[0]));
	}

	return (EXIT_SUCCESS);
}

void writeStudentToFile(Student student, FILE* file)
{
	fprintf(file, "%09d, %.2f,%c\n", student.number, student.percent, student.grade);
}

void getValidStudentData(Student* student, char validValues[], int count)
{
	student->number = getValidInteger("Enter 9-digit student number: ", "Student number must be 9 digits", 0, 999999999);
	student->percent = getValidFloat("Enter percentage (0-100)", "Percentage must be between 0 and 100", 0, 100);
	getchar();
	student->grade = getValidChar("Enter letter grade: ", "Letter grade must be between a-f", validValues, count);
}

bool isValid(char character, char validValues[], int count)
{
	for (int i = 0; i < count; i++)
	{
		if (character == validValues[i])
		{
			return true;
		}
	}
	return false;
}

char getValidChar(char promptString[], char errorString[], char validValues[] , int count)
{
	char input;

	printf(promptString);
	scanf_s("%c", &input);

	while (!isValid(input, validValues,count))
	{
		printf("\n");
		printf(errorString);
		printf("\n");
		printf(promptString);
		scanf_s("%c", &input);
	}

	return input;
}

int getValidFloat(char promptString[], char errorString[], float lowerBound, float upperBound)
{
	float input;

	printf(promptString);
	scanf_s("%f", &input);

	while (input < lowerBound || input > upperBound)
	{
		printf("\n");
		printf(errorString);
		printf("\n");
		printf(promptString);
		scanf_s("%f", &input);
	}

	return input;
}

int getValidInteger(char promptString[], char errorString[], int lowerBound, int upperBound)
{
	int input;

	printf(promptString);
	scanf_s("%d", &input);

	while (input < lowerBound || input > upperBound)
	{
		printf("\n");
		printf(errorString);
		printf("\n");
		printf(promptString);
		scanf_s("%d", &input);
	}

	return input;
}