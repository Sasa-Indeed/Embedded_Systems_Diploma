/*
 * main.c
 *
 *  Created on: 2 Jul 2022
 *      Author: Ahmed
 */
#include <stdio.h>
#include<stdlib.h>

int main(){
	float x;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%f",&x);
	fflush(stdout);fflush(stdin);

	if(x > 0){
		printf("%f is positive.",x);
	}else if (x < 0){
		printf("%f is negative.",x);
	}else{
		printf("You entered zero.");
	}

	return 0;
}

