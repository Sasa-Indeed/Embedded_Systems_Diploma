/*
 * main.c
 *
 *  Created on: 31 Jul 2022
 *      Author: Ahmed
 */
#include <stdio.h>

int main(){

	char arr[27];
	char* ptr = arr;
	int i = 0;
	printf("The Alphabets are :\n");
	fflush(stdout);
	for(;i < 26; ++i){
		*ptr = i + 'A';
		printf("%c ",*ptr);
		++ptr;
	}




	return 0;
}
