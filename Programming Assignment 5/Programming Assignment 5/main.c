#define MAX_LENGTH 100
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Vector Vector;
typedef struct MoveInfo MoveInfo;

struct Vector
{
	float x;
	float y;
	float z;
};

struct MoveInfo
{
	Vector direction;
	float duration;
};


int countInputFileLines(char inputFileName[]);
void getPointFromString(char string[], Vector* point);
void getMoveInfoBetweenPoints(MoveInfo *moveInfo, Vector firstPoint, Vector secondPoint);
void writeMoveInfoToFile(MoveInfo moveInfo[], int count);
void printFileContents(char* fileName, int numLines);


int main(int argc, char** argv)
{
	int numLines;
	int i = 0;
	
	float duration = 0.0;

	char line[MAX_LENGTH];

	numLines = countInputFileLines("points.txt");

	Vector* points = malloc((numLines + 1) * sizeof(Vector));
	MoveInfo* output = malloc((numLines) * sizeof(MoveInfo));

	FILE* fp = fopen("points.txt", "r");
	while (i < numLines)
	{
		fgets(line, MAX_LENGTH, fp);
		getPointFromString(line,&points[i]);
		i += 1;
	}

	i = 0;

	while (i < numLines - 1)
	{
		getMoveInfoBetweenPoints(&output[i], points[i],points[i+1]);
		duration += output[i].duration;
		i += 1;
	}

	printf("%.4f\n", duration);

	writeMoveInfoToFile(output, numLines);

	printFileContents("results.txt", numLines - 1);

	fclose(fp);
}

void writeMoveInfoToFile(MoveInfo moveInfo[], int count)
{
	FILE* fp = fopen("results.txt", "w");

	int i = 0;

	while (i < count)
	{
		fprintf(fp, "%.4f,%.4f,%.4f,%.4f\n", moveInfo[i].direction.x, moveInfo[i].direction.y, moveInfo[i].direction.z, moveInfo[i].duration);
		i += 1;
	}

	fclose(fp);

}

void getMoveInfoBetweenPoints(MoveInfo* moveInfo, Vector firstPoint, Vector secondPoint)
{
	float deltaX;
	float deltaY;
	float deltaZ;
	float duration;

	Vector hold;

	deltaX = secondPoint.x - firstPoint.x;
	deltaY = secondPoint.y - firstPoint.y;
	deltaZ = secondPoint.z - firstPoint.z;

	duration = sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);

	hold.x = deltaX / duration;
	hold.y = deltaY / duration;
	hold.z = deltaZ / duration;

	moveInfo->duration = duration;
	moveInfo->direction = hold;

}

void getPointFromString(char string[], Vector* point)
{
	char* result = strchr(string, ',');
	char* stringStart = &string[0];

	int commaIndex = result - stringStart;

	char* x = malloc((commaIndex + 1) * sizeof(char));

	strncpy(x, string, commaIndex);

	x[commaIndex] = '\0';

	point->x = atoi(x);


	string = &string[0] + commaIndex + 1;
	result = strchr(string, ',');

	stringStart = &string[0];
	commaIndex = result - stringStart;

	char* y = malloc((commaIndex + 1) * sizeof(char));
	strncpy(y, string, commaIndex);

	y[commaIndex] = '\0';
	point->y = atof(y);

	string = &string[0] + commaIndex + 1;
	point->z = atof(string);

	free(x);
	free(y);

}

int countInputFileLines(char FileName[])
{
	char c;
	int count = 0;

	FILE* fp = fopen(FileName, "r");

	if (fp == NULL)
	{
		printf("Could not open file %s", FileName);
		return 0;
	}

	for (c = getc(fp); c != EOF; c = getc(fp))
		if (c == '\n') 
			count = count + 1;

	fclose(fp);
	return count;
}



void printFileContents(char* fileName, int numLines)
{
	char line[100];


	FILE* inputFile = fopen(fileName, "r");
	if (inputFile == NULL)
	{
		printf("File open failed in printFileContents\n");
		return (EXIT_FAILURE);
	}

	for (int i = 0; i < numLines; i++)
	{
		fgets(line, sizeof(line), inputFile);
		printf(line);
	}

	fclose(inputFile);
}