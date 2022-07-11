/*
 * main.c
 *
 *  11 Jul 2022
 *      Ahmed
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printReverse(char text []);

int main(){

	char string [1000];

	printf("Enter a sentence: ");
	fflush(stdout);fflush(stdin);
	gets(string);
	printReverse(string);

	return 0;
}

void printReverse(char text []){

	if(text[0] != '\0'){
		printReverse(text +1);
		printf("%c",text[0]);
	}
}
