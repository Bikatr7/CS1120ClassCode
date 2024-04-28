/*
    * File: main.c
    * Author: Thomas Kemph
    * Date: 12/7/22
    * Collaborated with: Alexis L, Austin R, Raymond M, Kaden B
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_LENGTH 100

/*
 * Programming Assignment 5
 */
typedef struct Vector Vector;
struct Vector
{
    float x;
    float y;
    float z;
};
typedef struct MoveInfo MoveInfo;
struct MoveInfo
{
    Vector direction;
    float duration;
};

void getPointFromString(char string[], Vector* point);
void getMoveInfoBetweenPoints(MoveInfo* moveInfo, Vector firstPoint, Vector secondPoint);
void writeMoveInfoToFile(MoveInfo moveInfo[], int count);
void printFileContents(char* fileName, int numLines);
int countInputFileLines(char inputFile[]);

int main(int argc, char** argv)
{
    int vectorLength = countInputFileLines("points.txt");
    int numPoints = 0;
    int i = 0;
    char currentLine[100];

    float duration = 0.0;

    Vector * vectorArr = malloc((vectorLength + 1) * sizeof(Vector));
    MoveInfo* Arr = malloc((vectorLength) * sizeof(MoveInfo));
    FILE* inputFile = fopen("points.txt", "r");

    while (i < vectorLength)
    {
        fgets(currentLine, MAX_LENGTH, inputFile);
        getPointFromString(currentLine, &vectorArr[i]);
        i += 1;
    }

    for (int i = 0; i < vectorLength - 1; i++)
    {
        getMoveInfoBetweenPoints(&Arr[i], vectorArr[i],vectorArr[i+1]);
        duration += Arr[i].duration;
    }

    fclose(inputFile);

    printf("%.4f\n", duration);

    writeMoveInfoToFile(Arr, vectorLength);

    printFileContents("results.txt", vectorLength - 1);
}
int countInputFileLines(char inputFile[])
{
    char line;
    int numlines = 0;

    FILE* fp = fopen(inputFile, "r");

    if (fp == NULL)
    {
        printf("Could not open file %s", inputFile);
        return 0;
    }

    for (line = getc(fp); line != EOF; line = getc(fp))
        if (line == '\n')
            numlines += 1; 

    fclose(fp);

    return numlines;

}
 void getPointFromString(char string[], Vector * point)
  {
        char* result = strchr(string, ',');
        char* stringStart = &string[0];

        int commaIndex = result - stringStart;

        char* xString = malloc(sizeof(char) * commaIndex + 1);

        strncpy(xString, string, commaIndex);

        xString[commaIndex] = '\0';

        point->x = atoi(xString);

        string = &string[0] + commaIndex + 1;
        result = strchr(string, ',');

        stringStart = &string[0];
        commaIndex = result - stringStart;

        char* yString = malloc((commaIndex + 1) * sizeof(char));
        strncpy(yString, string, commaIndex);

        yString[commaIndex] = '\0';
        point->y = atof(yString);

        string = &string[0] + commaIndex + 1;
        point->z = atof(string);

        free(xString);
        free(yString);
    }
    void getMoveInfoBetweenPoints(MoveInfo * moveInfo,Vector firstPoint, Vector secondPoint)
    {
        float deltaX = secondPoint.x - firstPoint.x;
        float deltaY = secondPoint.y - firstPoint.y;
        float deltaZ = secondPoint.z - firstPoint.z;
        float length = sqrtf(powf(deltaX, 2) + powf(deltaY, 2)+ powf(deltaZ, 2));

        moveInfo->duration = length;
        moveInfo->direction.x = deltaX / length;
        moveInfo->direction.y = deltaY / length;
        moveInfo->direction.z = deltaZ / length;


       
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