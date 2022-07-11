/*
 * main.c
 *
 *  11 Jul 2022
 *      Ahmed
 */
#include <stdio.h>
#include <stdlib.h>

double powerClac(double base, int pow);

int main(){
	int power;
	double number;

	printf("Enter base number: ");
	fflush(stdout);fflush(stdin);
	scanf("%lf", &number);
	printf("Enter power number(positive integer): ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&power);

	printf("%.4lf^%d = %.4lf", number, power, powerClac(number ,power));


	return 0;
}

double powerClac(double base, int pow){
	if(pow == 0){
		return 1;
	}else{
		return base * powerClac(base,pow-1);
	}
}
