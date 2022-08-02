/*
 * main.c
 *
 *  Created on: 31 Jul 2022
 *      Author: Ahmed
 */
#include <stdio.h>

int main(){

	int m = 29;
	int* ab = NULL;

	printf("Address of m : %x\n",&m);
	fflush(stdout);
	printf("Value of m : %d\n",m);
	fflush(stdout);
	ab = &m;

	printf("\nAddress of pointer ab : %x\n",ab);
	fflush(stdout);
	printf("Content of pointer ab : %d\n",*ab);
	fflush(stdout);
	m = 34;

	printf("\nThe value of m assigned to 34 now.\n");
	fflush(stdout);
	printf("Address of pointer ab : %x\n",ab);
	fflush(stdout);
	printf("Content of pointer ab : %d\n",*ab);
	fflush(stdout);
	*ab = 7;

	printf("\nThe pointer variable ab is assigned with the value 7 now.\n");
	fflush(stdout);
	printf("Address of m : %x\n",&m);
	fflush(stdout);
	printf("Value of m : %d\n",m);
	fflush(stdout);

	return 0;
}
