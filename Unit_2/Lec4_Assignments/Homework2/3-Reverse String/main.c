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

	char text[1000], reverse[1000];
	int i = 0, size;

	printf("Enter a string: ");
	fflush(stdout);fflush(stdin);
	scanf("%[^\n]", text);
	size = strlen(text);


	for(i = 0; i < size; ++i){
		reverse[i] = text[size-1-i];
	}
	reverse[i] = 0;

	printf("%s",reverse);

	return 0;
}


