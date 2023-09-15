#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <ctype.h>

#define NAME_LENGHT 21
#define INPUT_BUFFER_LENGHT 256
#define LONG_STRING_LENGHT 256
#define STUDENT_ID_LENGHT 13
#define DEFAULT_STRING_LENGHT 21



struct Student
{
    int studentind, db_entry_row;
    char firstname[NAME_LENGHT];
    char lastname[NAME_LENGHT];
    char studentid[STUDENT_ID_LENGHT];
    char major[DEFAULT_STRING_LENGHT];
};
typedef struct Student Struct;

int main()
{
    struct Student student;
    student.studentind = 1;
    student.db_entry_row = 2;
    strcpy(student.firstname, "John");
    strcpy(student.lastname, "Doe");
    strcpy(student.studentid, "1234567890123");
    strcpy(student.major, "Computer Science");

    bool test = false;

    while (test == false)
    {
        printf("Enter student firstname: ");
        test = improvedFgets(student.firstname, NAME_LENGHT);
    }
    
    return 0;
}

bool improvedFgets(char *stringToStoreTo, const int maxLenghtOfString)
{
    bool newline_found = false;
    int i = 0;

    if (fgets(stringToStoreTo, INPUT_BUFFER_LENGHT, stdin) != NULL)
    {

        if (stringToStoreTo[0] == '\n' || stringToStoreTo[0] == '\0')
        {
            printf("Error: Empty input.\n");
            stringToStoreTo[0] = '\0'; // Clearing string.
            return false;
        }

        while (newline_found == false)
        {
            if (stringToStoreTo[i] == '\n')
            {
                newline_found = true;
                stringToStoreTo[i] = '\0';
            }
            if (i >= maxLenghtOfString - 1)
            {
                printf("\nError: Input over max accepted lenght of %d characters.\n", maxLenghtOfString - 1);
                stringToStoreTo[0] = '\0'; // Clearing string.
                return false;
            }
            i++;
        }
    }

    return true;
}