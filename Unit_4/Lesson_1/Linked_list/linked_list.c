/*
 * linked_list.c
 *
 *  Created on: 5 Oct 2022
 *      Author: Ahmed
 */
#include "linked_list.h"

//head of the linked list to point the first student
struct S_Student* GP_Student_list = NULL;

void Fill_data (struct S_Student* new_student){
	char text [40];

	DPRINTF("\nEnter Student Id: ");
	gets(text);
	new_student->student.ID = atoi(text);

	DPRINTF("\nEnter Student Full Name: ");
	gets(new_student->student.name);

	DPRINTF("\nEnter Student height: ");
	gets(text);
	new_student->student.height = atof(text);
}

void Add_Student(){
	struct S_Student* last_student;
	struct S_Student* new_student;

	if (GP_Student_list == NULL)
	{
		//Creating dynamic data for the student
		new_student = (struct S_Student*) malloc(sizeof(struct S_Student));
		//Assigning head of the list to the new student
		GP_Student_list = new_student;
	}else{
		//Navigating thought the list to find the last student
		last_student = GP_Student_list;
		while (last_student->P_next_student){
			last_student = last_student->P_next_student;
		}

		////Creating dynamic data for the student
		new_student = (struct S_Student*) malloc(sizeof(struct S_Student));
		//Assigning the previous last student to the new last student
		last_student->P_next_student = new_student;
	}

	//Filling the data of the student
	Fill_data(new_student);
	//Assigning the last student to point to null
	new_student->P_next_student = NULL;
}

int Delete_Student(){
	struct S_Student* previous_student = NULL;
	struct S_Student* current_student = GP_Student_list;
	char text[40];
	int ID = 0;

	DPRINTF("\nEnter student ID: ");
	ID = atoi(gets(text));

	//Enters the loop if their is a list
	while (current_student){

		if (current_student->student.ID == ID){
			//If the student match the ID and it is not the first element
			if (previous_student){
				previous_student->P_next_student = current_student->P_next_student;
			}else{//If the student match the ID and it is the first element
				GP_Student_list = current_student->P_next_student;
			}
			free(current_student);//after changing the pointers deletes the student
			return 1;
		}
		//going to the next student if it does not match the ID
		previous_student = current_student;
		current_student = current_student->P_next_student;
	}

	//if there is no match for the ID
	DPRINTF("\nCannot find student with ID: %d!!!",ID);
	return 0;
}

void View_Students(){
	struct S_Student* current_student = GP_Student_list;
	int count = 1;

	//checking if the list is empty
	if(current_student){
		DPRINTF("\n================Displaying all Students================\n");
		while (current_student)
		{
			DPRINTF("\t%d-Student Name: %s\t Student ID: %d\t Student Height: %f\n",count,current_student->student.name,
					current_student->student.ID,current_student->student.height);
			count++;
			current_student = current_student->P_next_student;
		}
		DPRINTF("=======================================================\n");
	}else{
		DPRINTF("\nThe list is Empty\n");
	}
}

void Delete_All(){
	struct S_Student* current_student = GP_Student_list;
	struct S_Student* temp = NULL;

	//checking if the list is empty
	if(current_student){
		while (current_student)
		{
			temp = current_student->P_next_student;
			free(current_student);
			current_student = temp;
		}
		GP_Student_list = NULL;
	}else{
		DPRINTF("\nThe list is Empty\n");
	}

}

struct S_Student* GetNth(int index){
	struct S_Student* current_student = GP_Student_list;
	int count = 0;
	if(current_student){
		while (current_student){
			if(count == index){
				return current_student;
			}
			current_student = current_student->P_next_student;
			count++;
		}
		DPRINTF("Index %d OUT OF BOUNDS!!!",index);
		return NULL;
	}else{
		DPRINTF("List is Empty!!!");
		return NULL;
	}

}

int Get_length(void){
	struct S_Student* current_student = GP_Student_list;
	int count = 0;

	if(current_student){
		while (current_student){
			count++;
			current_student = current_student->P_next_student;
		}

		return count;
	}else{
		return 0;
	}
}

void Get_index_from_last(int index){

	if(GP_Student_list){
		int len = Get_length();
		int node = len - index;
		struct S_Student* student = GetNth(node);
		if(student){
			DPRINTF("\n\tStudent Name: %s\t Student ID: %d\t Student Height: %f\n",student->student.name,
					student->student.ID,student->student.height);
		}
	}else{
		DPRINTF("List is Empty!!!")
	}
}

void Get_middle(void){
    int length = Get_length();
    int index = 0;

    if (length){
        index = (int)(length/2) + 1;
        struct S_Student* student = GetNth(index-1);
		if(student){
			DPRINTF("\n\tStudent Name: %s\t Student ID: %d\t Student Height: %f\n",student->student.name,
					student->student.ID,student->student.height);
		}
    }else{
        DPRINTF("List is Empty!!!");
    }

}

