/*
 * main.c
 *
 *  Created on: 2 Jul 2022
 *      Author: Ahmed
 */
#include <stdio.h>
#include<stdlib.h>

int main(){
	int x;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&x);
	fflush(stdout);fflush(stdin);

	if((x%2) == 0){
		printf("%d is even.",x);
	}else{
		printf("%d is odd.",x);
	}

	return 0;
}

