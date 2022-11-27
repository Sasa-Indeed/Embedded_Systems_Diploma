//
// Created by Ahmed on 26/11/2022.
//

#ifndef STUDENT_MANAGMENT_STUDENTSLIST_H
#define STUDENT_MANAGMENT_STUDENTSLIST_H

#include <stdint.h>

/*USER Configuration:================================================
select the element type (int8_t, uint8_t, int16_t, uint16_t,...)*/
#define Name_Length 20
#define Courses_number 6
#define Students_number 10
//===================================================================


//Data Type
typedef struct{
    uint8_t first_name[Name_Length];
    uint8_t last_name[Name_Length];
    uint32_t roll_number;
    uint32_t course_ID[Courses_number];
    float GPA;
}Student_Data_t;

extern  Student_Data_t students[Students_number];

typedef enum {
    ERROR,
    NO_ERROR
}Return_Status;


//APIs
//Add student for a certain file
Return_Status add_students_from_file(char *fileName);

//Add student from user
Return_Status add_students_manually();

//Finds a student with roll number
Return_Status find_student_W_rollNumber(uint32_t ID);

//Finds a student with the first name
Return_Status find_student_W_firstName(uint8_t * Fname);

//Finds all students registered in the course
Return_Status find_students_IN_Course(uint32_t courseID);

//Fet the number of students int the Queue
uint32_t student_count();

//Deletes student given their ID
Return_Status delete_student(uint32_t ID);

//Updates student information
Return_Status update_student(uint32_t ID);

//Displays the Student information
void display_student(const Student_Data_t * student_info);

//display all students in the queue
void display_all_students();

#endif //STUDENT_MANAGMENT_STUDENTSLIST_H
