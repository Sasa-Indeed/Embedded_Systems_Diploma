#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StudentsList.h"
#include "FIFO.h"

int main( ){
    char text[20];
    if(FIFO_init(&Queue,students,Students_number) == FIFO_no_error){
        while(1){
            printf("\nChose the task that you want perform :");
            printf("\n1:Add The Student Details From Text File");
            printf("\n2:Add The Student Details Manually");
            printf("\n3:Find The Student Details With ID");
            printf("\n4:Find The Student Details With First Name");
            printf("\n5:Find The Number of Students Registered in a Course");
            printf("\n6:Find The Total Number of student");
            printf("\n7:Delete The Student Details");
            printf("\n8:Update The Student Details");
            printf("\n9:Show All Students Information");
            printf("\n10:Exit");
            printf("\n==================================================================");
            printf(" \n Enter Your Choice: ");
            gets(text);
            switch (atoi(text))
            {
                case 1:
                    printf("Enter file Name with extension: ");
                    text[0] = '\0';
                    gets(text);
                    add_students_from_file(text);
                    break;
                case 2:
                    add_students_manually();
                    break;
                case 3:
                    printf("\nEnter The Roll Number of the Student: ");
                    text[0] = '\0';
                    gets(text);
                    find_student_W_rollNumber((uint32_t)atoi(text));
                    break;
                case 4:
                    printf("\nEnter The First Name of the Student: ");
                    text[0] = '\0';
                    gets(text);
                    find_student_W_firstName(text);
                    break;
                case 5:
                    printf("\nEnter Course ID to find all of the Students: ");
                    text[0] = '\0';
                    gets(text);
                    find_students_IN_Course((uint32_t)atoi(text));
                    break;
                case 6:
                    printf("The Number of students is: %d",student_count());
                    break;
                case 7:
                    printf("\nEnter The Roll Number of the Student to DELETE: ");
                    text[0] = '\0';
                    gets(text);
                    delete_student((uint32_t)atoi(text));
                    break;
                case 8:
                    printf("\nEnter The Roll Number of the Student to Update: ");
                    text[0] = '\0';
                    gets(text);
                    update_student((uint32_t)atoi(text));
                    break;
                case 9:
                    display_all_students();
                    break;
                case 10:
                    exit(1);
                    break;
                default:
                    printf("\nERROR: Unknown Option");
                    break;
            }
        }
    } else{
        printf("\nUNABLE TO INITIALIZE THE QUEUE!!!!\n");
    }


    return 0;
}
