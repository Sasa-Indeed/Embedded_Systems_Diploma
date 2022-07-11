/*
 * main.c
 *
 *  10 Jul 2022
 *      Ahmed
 */
#include <stdio.h>
#include <stdlib.h>


int isPrime(int num);


int main(){
	int x = 0,y = 0;


	printf("Enter two number(intervals): ");
	fflush(stdout);fflush(stdin);
	scanf("%d%d",&x,&y);


	printf("Prime numbers between %d and %d are: ",x,y);
	fflush(stdout);

	if(x > y){
		int c = x;
		x = y;
		y = c;
	}

	for(;x <= y; ++x){
		if(isPrime(x)){
			printf("%d ",x);
			fflush(stdout);
		}
	}


	return 0;
}


int isPrime(int num){
	int i, x = num/2;

	if(num == 1 || num ==0)
		return 0;

	for(i = 2 ; i <= x; ++i){
		if(num%i ==0)
			return 0;
	}

	return 1;
}
