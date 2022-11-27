//
// Created by Ahmed on 26/11/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StudentsList.h"
#include "FIFO.h"

Student_Data_t students[Students_number];

Return_Status add_students_from_file(char *fileName){
    FILE* file = fopen(fileName,"r");
    uint8_t read_buffer[50];
    char ch;
    Student_Data_t temp_student;
    int string_number = 0,course = 0,index = 0;
    if (file == NULL) {
        printf("file can't be opened \n");
        return ERROR;
    }

    while (!feof(file)) {
        ch = fgetc(file);

        if (ch == ' '){
            read_buffer[index] = '\0';
            switch (string_number) {
                case 0:
                    temp_student.roll_number = atoi(read_buffer);
                    break;
                case 1:
                    strcpy(temp_student.first_name ,read_buffer);
                    break;
                case 2:
                    strcpy(temp_student.last_name ,read_buffer);
                    break;
                case 3:
                    temp_student.GPA  = atof(read_buffer);
                    break;
                default:
                    if(course < Courses_number){
                        temp_student.course_ID[course] = atoi(read_buffer);
                        course++;
                    } else{
                        printf("Courses reached limit\n");
                    }
            }
            for (int i = 0; i < index; ++i) {
                read_buffer[i] = 0;
            }
            index = 0;
            string_number++;
            continue;
        } else if(ch == '\n'){
            temp_student.course_ID[course] = atoi(read_buffer);
            if (!FIFO_FindId(&Queue,&temp_student,temp_student.roll_number)){
                if (FIFO_enqueue(&Queue,temp_student) == FIFO_no_error){
                    display_student(&temp_student);
                    printf("Student Successfully added\n");
                } else{
                    printf("error\n");
                }
            } else{
                printf("Student with the same ID FOUND!!!\n");
            }

            course = 0;
            index = 0;
            string_number = 0;
            continue;
        }
    read_buffer[index++] = ch;
    }


    fclose(file);

    return NO_ERROR;
}

Return_Status add_students_manually(){
    Student_Data_t temp_student;
    char text[20];
    int ID = -1;

    do {
        if(ID != -1)
            printf("ID already taken enter another ID\n");
        printf("Enter Student ID  : ");
        ID = atoi(gets(text));
    } while (FIFO_FindId(&Queue, &temp_student, ID));

    temp_student.roll_number = ID;
    printf("Enter First Name  : ");
    gets(temp_student.first_name);

    printf("Enter Last  Name  : ");
    gets(temp_student.last_name);

    printf("Enter Student GPA : ");
    gets(text);
    temp_student.GPA = (float)atof(text);


    printf("Enter Courses ID  :\n");
    for (int i = 0; i < Courses_number; i++){
        printf("%d-",i+1);
        temp_student.course_ID[i] = atoi(gets(text));
    }



    if (FIFO_enqueue(&Queue, temp_student) == FIFO_no_error){
        printf("[Done]--> Student Added: \n");
        display_student(&temp_student);
        return NO_ERROR;
    }else
    {
        printf("[ERORR]-->Error Adding Student\n");
        return ERROR;
    }
}

Return_Status find_student_W_rollNumber(uint32_t ID){
    Student_Data_t temp;

    if (!FIFO_FindId(&Queue, &temp, ID)){
        printf("[ERORR]--> Student is not found!!!!\n");
        return ERROR;
    }
    else{
        display_student(&temp);
        return NO_ERROR;
    }
}

Return_Status find_student_W_firstName(uint8_t * Fname){
    FIFO_status stat = FIFO_length_status(&Queue);
    Student_Data_t temp;
    int flag = 0;
    if(stat == FIFO_null){
        return stat;
    } else if (stat == FIFO_empty){
        return 0;
    }

    Element_type* read_temp = Queue.tail;

    for (int i = 0; i < Queue.count; i++){

        if (strcmp(read_temp->first_name,Fname) == 0){
            printf("\n%d-Student",flag+1);
            temp = *(read_temp);
            display_student(&temp);
            flag++;
        }

        if(read_temp == Queue.base + (Queue.length * sizeof(Element_type))){
            read_temp = Queue.base;
        }else{
            read_temp++;
        }
    }

    if(flag){
        printf("Displayed all Students with first Name: %s", Fname);
        return NO_ERROR;
    } else{
        printf("No students found with first Name: %s", Fname);
        return ERROR;
    }

}

Return_Status find_students_IN_Course(uint32_t courseID){
    FIFO_status stat = FIFO_length_status(&Queue);
    Student_Data_t temp;
    int flag = 0;
    if(stat == FIFO_null){
        return stat;
    } else if (stat == FIFO_empty){
        return 0;
    }

    Element_type* read_temp = Queue.tail;

    for (int i = 0; i < Queue.count; i++){

        for (int j = 0; j < Courses_number; ++j) {
            if (read_temp->course_ID[j] == courseID){
                printf("\n%d-Student",++flag);
                temp = *(read_temp);
                display_student(&temp);
                break;
            }
        }

        if(read_temp == Queue.base + (Queue.length * sizeof(Element_type))){
            read_temp = Queue.base;
        }else{
            read_temp++;
        }
    }

    if(flag){
        printf("Displayed all Students in the course with ID: %d", courseID);
        return NO_ERROR;
    } else{
        printf("No students found in course with ID: %d", courseID);
        return ERROR;
    }
}

uint32_t student_count(){
    return Queue.count;
}

Return_Status delete_student(uint32_t ID){
    FIFO_status stat = FIFO_length_status(&Queue);
    Student_Data_t temp;
    if(stat == FIFO_null){
        return stat;
    } else if (stat == FIFO_empty){
        return 0;
    }
    Element_type* read_temp = Queue.tail;
    if (FIFO_FindId(&Queue, &temp, ID)) {
        for (int i = 0; i < Queue.count; i++) {

            FIFO_dequeue(&Queue, &temp);

            if (temp.roll_number == ID) {
                printf("Student Deleted\n");
                display_student(&temp);
                return NO_ERROR;
            } else {
                FIFO_enqueue(&Queue, temp);
            }

            if (read_temp == Queue.base + (Queue.length * sizeof(Element_type))) {
                read_temp = Queue.base;
            } else {
                read_temp++;
            }
        }
    } else{
        printf("No Student found with ID: ", ID);
    }
}

Return_Status update_student(uint32_t ID){
    Student_Data_t temp;
    char choice[10];

    if(FIFO_FindId(&Queue,&temp,ID)){
        Element_type* read_temp = Queue.tail;
        for (int i = 0; i < Queue.count; i++){

            if (read_temp->roll_number == ID){
                break;
            }

            if(read_temp == Queue.base + (Queue.length * sizeof(Element_type))){
                read_temp = Queue.base;
            }else{
                read_temp++;
            }
        }
        printf("\nChoose the element to be updated: ");
        printf("\n1: first name");
        printf("\n2: last name");
        printf("\n3: roll number");
        printf("\n4: GPA");
        printf("\n5: courses");
        printf("\nYour Choice: ");
        gets(choice);
        switch (atoi(choice)){
            case 1:
                printf("\nEnter the new first name: ");
                gets(read_temp->first_name);

                break;
            case 2:
                printf("\nEnter the new last name: ");
                gets(read_temp->last_name);

                break;
            case 3:
                printf("\nEnter the new roll number: ");
                gets(choice);
                int new_roll = atoi(choice);
                if (find_student_W_rollNumber(new_roll) != ERROR){
                    printf("\nRoll %d Number is already taken\n", new_roll);
                    break;
                }
                read_temp->roll_number = new_roll;
                break;
            case 4:
                printf("\nEnter the new GPA: ");
                gets(choice);
                read_temp->GPA = atof(choice);
                break;
            case 5:
                printf("\nEnter the new courses: ");
                for (int i = 0; i < Courses_number; i++){
                    printf("\nEnter the Course %d ID", i + 1);
                    gets(choice);
                    read_temp->course_ID[i] = atoi(choice);
                }
                break;

            default:
                break;
        }

    }
}

void display_student(const Student_Data_t * student_info){
    printf("=====================================================\n");
    printf("\tName    : %s %s\n", student_info->first_name, student_info->last_name);
    printf("\tID      : %d \n", student_info->roll_number);
    printf("\tGPA     : %.2f \n", student_info->GPA);
    printf("\tCourses : %d", student_info->course_ID[0]);
    for (int i = 1; i < Courses_number; i++)
    {
        printf(" , %d", student_info->course_ID[i]);
    }
    printf("\n=====================================================\n");
}

void display_all_students(){
    FIFO_status stat = FIFO_length_status(&Queue);
    Student_Data_t temp;
    if(stat == FIFO_null){
        printf("Queue is NULL\n");
        return;
    } else if (stat == FIFO_empty){
        printf("Queue is empty\n");
        return;
    }
    Element_type* read_temp = Queue.tail;


    for (int i = 0; i < Queue.count; i++){
        temp = *read_temp;
        printf("\n%d-Student",i+1);
        display_student(&temp);

        if(read_temp == Queue.base + (Queue.length * sizeof(Element_type))){
            read_temp = Queue.base;
        }else{
            read_temp++;
        }
    }


}