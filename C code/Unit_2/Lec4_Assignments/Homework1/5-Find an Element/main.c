/*
 * main.c
 *
 *  Created on: 5 Jul 2022
 *      Author: Ahmed
 */
#include <stdio.h>
#include <stdlib.h>

int main(){

	int i = 0, Asize, data [100], number, index, found = 0;

	printf("Enter no of elements : ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &Asize);

	for(i = 0; i < Asize; ++i){
		fflush(stdout);fflush(stdin);
		scanf("%d", &data[i]);
	}

	printf("Enter the element to be searched : ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &number);


	for(i = 0; i < Asize; ++i){
		if(data[i] == number){
			found = number;
			index = i + 1;
		}
	}

	if(found != number){
		printf("%d was not found", number);
	}else{
		printf("Number found at the location = %d", index);
	}



	return 0;
}

