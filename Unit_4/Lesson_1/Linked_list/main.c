/*
 * main.c
 *
 *  Created on: 5 Oct 2022
 *      Author: Ahmed
 */
#include "linked_list.h"



int main(){

	char temp_text[40];
	int flag = 1;
	int length = 0;
	int index = 0;

	while(flag){
		DPRINTF("\n======================================");
		DPRINTF("\n\t Choose on of the following Options \n");
		DPRINTF("\n 1: AddStudent ");
		DPRINTF("\n 2: Delete_Student ");
		DPRINTF("\n 3: view_students ");
		DPRINTF("\n 4: DeleteAll ");
		DPRINTF("\n 5: Get Student from the beginning of the list ");
		DPRINTF("\n 6: Get Students length ");
		DPRINTF("\n 7: Get Student from the end of the list ");
		DPRINTF("\n 8: Get Student from the middle of the list ");
		DPRINTF("\n 9: Quit ");
		DPRINTF("\n Enter Option Number: ");
		gets (temp_text);
		DPRINTF("======================================\n");

		switch (atoi (temp_text)){
		case 1:
			Add_Student();
			break;
		case 2:
			Delete_Student();
			break;
		case 3:
			View_Students();
			break;
		case 4:
			Delete_All();
			break;
		case 5:
			DPRINTF("\nEnter Index to get Student at beginning of the list (staring from 0): ");
			index = atoi(gets(temp_text));
			struct S_Student* student = GetNth(index);
			if(student){
				DPRINTF("\n\tStudent Name: %s\t Student ID: %d\t Student Height: %f\n",student->student.name,
						student->student.ID,student->student.height);
			}
			break;
		case 6:
			length = Get_length();
			DPRINTF("\nThe length of the list is: %d\n",length);
			break;
		case 7:
			DPRINTF("\nEnter Index to get Student at end of the list (staring from 1): ");
			index = atoi(gets(temp_text));
			Get_index_from_last(index);
			break;
		case 8:
			Get_middle();
			break;
		case 9:
			flag = 0;
			break;
		default:
			DPRINTF("\n wrong option ");
			break;
		}
	}

	return 0;
}
