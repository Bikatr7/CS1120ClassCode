/*
 * File:   main.c
 * Author: Kaden Bilyeu
 * Title:  SpeedAndDirection
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI;
	#define M_PI 3.1415926535858979323846
#endif


#define _CRT_SECURE_NO_WARNINGS

 /*
  *
  */
int main(int argc, char** argv)
{
	typedef struct Vector Vector;
	struct Vector
	{
		float x;
		float y;
	};
	const TIME_TO_MOVE = 3;

	float p1x;
	float p1y;
	float p2x;
	float p2y;

	float speed;
	float distance;
	float direction;
	float length;

	float deltaX;
	float deltaY;

	printf("Enter x for the first point: ");
	scanf_s("%f", &p1x);
	printf("\nEnter y for the first point: ");
	scanf_s("%f", &p1y);
	printf("\nEnter x for the second point: ");
	scanf_s("%f", &p2x);
	printf("\nEnter y for the second point: ");
	scanf_s("%f", &p2y);

	deltaX = p2x - p1x;
	deltaY = p2y - p1y;

	distance = sqrtf(powf((deltaX), 2) + powf((deltaY), 2));
	speed = distance / TIME_TO_MOVE;
	direction = (atan2f(deltaY, deltaX) * 180.0 / M_PI);

	Vector velocity;
	Vector unitDirection;

	velocity.x = deltaX / TIME_TO_MOVE;
	velocity.y = deltaY / TIME_TO_MOVE;

	unitDirection.x = deltaX;
	unitDirection.y = deltaY;

	length = sqrtf(powf(unitDirection.x,2) + powf(unitDirection.y, 2));

	unitDirection.x /= length;
	unitDirection.y /= length;
	
	velocity.x = unitDirection.x * speed;
	velocity.y = unitDirection.y * speed;

	printf("\n\nDistance between points : %.2f", distance);
	printf("\nSpeed : %.2f", speed);
	printf("\nDirection: %.2f", direction);
	printf("\nVelocity vector : (%.2f,%.2f)\n", velocity.x, velocity.y);
}