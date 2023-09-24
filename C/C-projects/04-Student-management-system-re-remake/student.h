#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

#define INPUT_BUFFER_LENGTH 128
#define LONG_STRING_LENGTH 256

struct Student
{
    int studentind, db_entry_row;
    char firstname[INPUT_BUFFER_LENGTH];
    char lastname[INPUT_BUFFER_LENGTH];
    char studentid[INPUT_BUFFER_LENGTH];
    char major[LONG_STRING_LENGTH];
    int fetchFailure;
};

typedef struct Student Student;

#endif
