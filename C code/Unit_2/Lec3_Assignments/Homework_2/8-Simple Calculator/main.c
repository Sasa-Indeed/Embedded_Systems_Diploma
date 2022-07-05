/*
 * main.c
 *
 *  Created on: 3 Jul 2022
 *      Author: Ahmed
 */
#include <stdio.h>
#include<stdlib.h>

int main(){
	float x,y;
	char operator;

	printf("Enter operator either + or - or * or /: ");
	fflush(stdout);
	scanf("%c", &operator);
	fflush(stdout);fflush(stdin);

	printf("Enter two integers: ");
	fflush(stdout);
	scanf("%f%f",&x,&y);
	fflush(stdout);fflush(stdin);

	switch(operator){
	case '+':
		printf("%f + %f = %f",x,y,(x+y));
	break;
	case '-':
			printf("%f - %f = %f",x,y,(x-y));
		break;
	case '*':
			printf("%f * %f = %f",x,y,(x*y));
		break;
	case '/':
			printf("%f / %f = %f",x,y,(x/y));
		break;
	default:
		printf("Error");
		break;
	}


	return 0;
}


