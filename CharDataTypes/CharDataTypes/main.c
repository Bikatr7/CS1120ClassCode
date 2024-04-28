/*
    *File: main.c
    *Author: Kaden Bilyeu
    *Title: CharDataTypes

*/

/*
* 
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    typedef struct Student Student;

    struct Student
    {
        int number;
        float percent;
        char grade;
    };

    Student student0 = { 101010101,89.5,'B'};
    printf("Student0\n");
    printf("----------\n");
    printf("Number: %d\n",student0.number);
    printf("Percent: %.2f\n", student0.percent);
    printf("Grade: %c\n", student0.grade);
    printf("\n");

    Student student1;
    student1.number = 222222222;
    student1.percent = 59.99;
    student1.grade = 'F';

    printf("Student1\n");
    printf("----------\n");
    printf("Number: %d\n", student1.number);
    printf("Percent: %.2f\n", student1.percent);
    printf("Grade: %c\n", student1.grade);
    printf("\n");

    return (EXIT_SUCCESS);
}