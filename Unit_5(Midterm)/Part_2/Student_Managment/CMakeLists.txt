cmake_minimum_required(VERSION 3.23)
project (Student_Managment C)

set(CMAKE_C_STANDARD 99)

add_executable(Student_Managment main.c StudentsList.h FIFO.h FIFO.c StudentsList.c)
