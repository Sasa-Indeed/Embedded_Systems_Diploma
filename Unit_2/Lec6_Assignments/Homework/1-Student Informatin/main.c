/*
 * main.c
 *
 *  Created on: 22 Jul 2022
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
	struct Sstudent student;
	printf("Enter information of students\n\n");
	fflush(stdout);

	printf("Enter name: ");
	fflush(stdout);fflush(stdin);
	gets(student.m_name);
	printf("Enter roll: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&student.m_roll);
	printf("Enter marks: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&student.m_marks);

	printf("\n");
	fflush(stdout);
	printf("Displaying Information\n");
	fflush(stdout);
	printf("Name: %s\n",student.m_name);
	fflush(stdout);
	printf("Roll: %d\n",student.m_roll);
	fflush(stdout);
	printf("Marks: %f",student.m_marks);
	fflush(stdout);

	return 0;
}


