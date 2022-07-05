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
	printf("Enter an alphabet: ");
	fflush(stdout);
	scanf("%c",&x);
	fflush(stdout);fflush(stdin);

	switch(x){
	case 'a':case 'e':case 'i':case 'o':case 'u':
	case 'A':case 'E':case 'I':case 'O':case 'U':
		printf("%c is a vowel.",x);
		break;
	default:
		printf("%c is a consonant.",x);
		break;
	}

	return 0;
}

