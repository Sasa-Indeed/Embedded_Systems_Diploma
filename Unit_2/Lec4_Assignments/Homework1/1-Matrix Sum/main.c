/*
 * main.c
 *
 *  Created on: 5 Jul 2022
 *      Author: Ahmed
 */
#include <stdio.h>
#include <stdlib.h>

int main(){

	float m_a [2][2], m_b [2][2];

	int i = 0, j = 0;

	printf("Enter elements of 1st matrix\n");
	fflush(stdout);
	for(i = 0; i < 2; ++i){
		for(j = 0; j < 2; ++j){
			printf("Enter a%d%d: ",(i+1),(j+1));
			fflush(stdout);fflush(stdin);
			scanf("%f",&m_a[i][j]);
		}
	}

	printf("Enter elements of 2nd matrix\n");
	fflush(stdout);
	for(i = 0; i < 2; ++i){
		for(j = 0; j < 2; ++j){
			printf("Enter b%d%d: ",(i+1),(j+1));
			fflush(stdout);fflush(stdin);
			scanf("%f",&m_b[i][j]);
		}
	}

	printf("Sum Of Matrix\n");
	fflush(stdout);
	for(i = 0; i < 2; ++i){
		for(j = 0; j < 2; ++j){
			printf("%.1f ",(m_a[i][j]+m_b[i][j]));
			fflush(stdout);
		}
		printf("\n");
		fflush(stdout);
	}




	return 0;
}

