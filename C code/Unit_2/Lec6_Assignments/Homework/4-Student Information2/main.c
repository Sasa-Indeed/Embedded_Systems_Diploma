/*
 * main.c
 *
 *  Created on: 23 Jul 2022
 *      Author: Ahmed
 */
#include <stdio.h>
#include <stdlib.h>

struct Sstudent{
	char m_name [50];
	int m_roll;
	float m_marks;
};

int main(){
	struct Sstudent students [10];
	int i;
	printf("Enter information of students\n\n");
	fflush(stdout);

	for(i = 0; i < 10;++i){
		printf("For roll number %d\n",i+1);
		students[i].m_roll = i+1;
		printf("Enter name: ");
		fflush(stdout);fflush(stdin);
		gets(students[i].m_name);
		printf("Enter marks: ");
		fflush(stdout);fflush(stdin);
		scanf("%f",&students[i].m_marks);
		printf("\n");
		fflush(stdout);
	}


	printf("Displaying Information\n");
	fflush(stdout);
	for(i = 0; i < 10 ; ++i){
		printf("Information for roll number %d:\n",students[i].m_roll);
		fflush(stdout);
		printf("Name: %s\n",students[i].m_name);
		fflush(stdout);
		printf("Marks: %.2f\n\n",students[i].m_marks);
		fflush(stdout);
	}

	return 0;
}


