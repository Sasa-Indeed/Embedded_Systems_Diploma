/*
 * main.c
 *
 *  Created on: 2 Jul 2022
 *      Author: Ahmed
 */
#include <stdio.h>
#include<stdlib.h>

int main(){
	float a,b;

	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f",&a);
	fflush(stdout);fflush(stdin);

	printf("Enter value of b: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&b);

	a = a + b; b = a - b; a = a - b;


	printf("After swapping, value of a = %f\n",a);
	fflush(stdout);
	printf("After swapping, value of b = %f",b);

	return 0;
}

