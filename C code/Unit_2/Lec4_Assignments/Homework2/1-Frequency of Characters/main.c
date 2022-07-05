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

	char text[1000], ch;
	int i = 0, count = 0;

	printf("Enter a string: ");
	fflush(stdout);fflush(stdin);
	gets(text);

	printf("Enter a character to find frequency: ");
	fflush(stdout);fflush(stdin);
	scanf("%c",&ch);

	while(text[i] != 0){
		if(text[i] == ch){
			count++;
		}
		i++;
	}

	printf("Frequency of %c = %d",ch,count);

	return 0;
}
