/*
 * main.c
 *
 *  Created on: 31 Jul 2022
 *      Author: Ahmed
 */
#include <stdio.h>
#include <string.h>

int main(){

	char text [50];
	char* ptr = NULL;

	printf("Input a string : ");
	fflush(stdout);fflush(stdin);
	gets(text);
	ptr = text + (strlen(text) - 1);

	printf("Reverse of the string is : ");
	fflush(stdout);fflush(stdin);

	while(1){
		printf("%c",*ptr);
		ptr--;
		if(ptr == text){
			printf("%c",*ptr);
			break;
		}
	}


	return 0;
}

