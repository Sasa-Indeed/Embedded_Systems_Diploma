/*
 * main.c
 *
 *  Created on: 3 Jul 2022
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

	if(x < 0){
		printf("Entered negative number");
	}else{
		int i;
		int sum;
		for(i = 0; i <= x; ++i){
			 sum += i;
		}

		printf("Sum = %d",sum);
	}

	return 0;
}

