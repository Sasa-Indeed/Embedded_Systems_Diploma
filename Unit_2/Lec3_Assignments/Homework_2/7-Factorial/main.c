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
		printf("Error!!! Factorial of a negative number does not exist");
	}else if(x == 0){
		printf("Factorial = 1");
	}else{
		int i;
		unsigned long long sum = 1;
		for(i = 1; i <= x; ++i){
			 sum *= i;
		}

		printf("Factorial = %u",sum);
	}

	return 0;
}


