/*
 * main.c
 *
 *  Created on: 23 Jul 2022
 *      Author: Ahmed
 */
#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415
#define area(R)(PI*R*R)

int main(){
	int radius;

	printf("Enter the radius: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&radius);
	printf("Area = %.2f",(float)area(radius));

	return 0;
}

