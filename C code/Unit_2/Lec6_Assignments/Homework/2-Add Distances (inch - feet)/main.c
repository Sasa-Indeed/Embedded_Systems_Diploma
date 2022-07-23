/*
 * main.c
 *
 *  Created on: 23 Jul 2022
 *      Author: Ahmed
 */
#include <stdio.h>
#include <stdlib.h>

struct Sdistance{
	int m_feet;
	float m_inches;
};

struct Sdistance addDistances(struct Sdistance a,struct Sdistance b);



int main(){
	struct Sdistance numbers[2],sum;
	int i;

	for(i = 0; i < 2; ++i){
		printf("For information of distance #%d\n",i+1);
		fflush(stdout);
		printf("Enter feet: ");
		fflush(stdout); fflush(stdin);
		scanf("%d",&numbers[i].m_feet);
		printf("Enter inches: ");
		fflush(stdout); fflush(stdin);
		scanf("%f",&numbers[i].m_inches);
		printf("\n");
		fflush(stdout); fflush(stdin);
	}

	sum = addDistances(numbers[0],numbers[1]);

	printf("\nSum of distances = %d\'-%.1f\"", sum.m_feet, sum.m_inches);


	return 0;
}

struct Sdistance addDistances(struct Sdistance a,struct Sdistance b){
	struct Sdistance sum;

	sum.m_feet = a.m_feet + b.m_feet;
	sum.m_inches = a.m_inches + b.m_inches;

	while(sum.m_inches >= 12.0){
		sum.m_inches -= 12.0;
		++sum.m_feet;
	}

	return sum;
}


