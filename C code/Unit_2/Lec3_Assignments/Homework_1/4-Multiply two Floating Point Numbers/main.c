/*
 * main.c
 *
 *  Created on: 2 Jul 2022
 *      Author: Ahmed
 */
#include <stdio.h>
#include<stdlib.h>

int main(){
	float x,y;
	printf("Enter two integers: ");
	fflush(stdout);
	scanf("%f%f",&x,&y);
	printf("Product: %f",(x*y));
	return 0;
}


