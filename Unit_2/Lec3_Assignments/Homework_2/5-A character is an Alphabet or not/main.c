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
	fflush(stdout);fflush(stdin);

	if(((x >= 'a') && (x <= 'z'))||((x >= 'A') && (x <= 'Z'))){
		printf("%c is an alphabet.",x);
	}else{
		printf("%c is not an alphabet.",x);
	}

	return 0;
}

