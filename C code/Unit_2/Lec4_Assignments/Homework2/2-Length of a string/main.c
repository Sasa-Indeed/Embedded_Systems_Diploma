/*
 * main.c
 *
 *  Created on: 5 Jul 2022
 *      Author: Ahmed
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char text[1000];
	int i = 0, count = 0;

	printf("Enter a string: ");
	fflush(stdout);fflush(stdin);
	scanf("%[^\n]", text);

	while(text[i] != 0){
		count++;
		i++;
	}

	printf("Length of string: %d",count);

	return 0;
}

