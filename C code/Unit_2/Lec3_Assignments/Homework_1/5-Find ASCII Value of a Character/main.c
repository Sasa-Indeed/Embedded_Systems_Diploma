/*
 * main.c
 *
 *  Created on: 2 Jul 2022
 *      Author: Ahmed
 */
#include <stdio.h>
#include<stdlib.h>

int main(){
	char x;
	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&x);
	printf("ASCII value of %c = %d",x,x);
	return 0;
}

