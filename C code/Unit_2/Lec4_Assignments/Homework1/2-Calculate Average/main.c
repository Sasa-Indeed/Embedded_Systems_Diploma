/*
 * main.c
 *
 *  Created on: 5 Jul 2022
 *      Author: Ahmed
 */
#include <stdio.h>
#include <stdlib.h>

int main(){

	float data [100], average = 0;
	int i = 0, Asize;

	printf("Enter number of data: ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &Asize);
	for(i = 0; i < Asize; ++i){
		printf("Enter number: ");
		fflush(stdout);fflush(stdin);
		scanf("%f", &data[i]);
	}

	for(i = 0; i < Asize; ++i){
		average += data[i];
	}
	average /= Asize;
	printf("Average = %.2f",average);


	return 0;
}
