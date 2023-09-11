#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// #defines
#define DB "db.txt"
#define TEMP "temp.tmp"
#define nameLenght 21
#define bufferlenght 256
#define studentidLenght 13
#define defultStringLenght 21
#define separator "\n\n----------------------------------------\n\n"

// prototypes
void get_DB_row_ind(int *pStudentind, int *pDB_rows);
bool improved_fgets(char *stringToStoreTo, const int maxLenghtOfString);
bool string_to_int_conv(const char *str, int *result);
bool string_to_double_conv(const char *inputStr, double *result);
void add_student(int *studentindPointer, int *db_rowsPointer, const char (*date_string)[20]);
void fgets_string_whileloop_template(const char stringToPrint[], const char errorMsg[], char *stringToStoreTo, const int maxLenghtOfString);

// structs
struct Student
{
    int studentind, db_entry_row;
    char firstname[nameLenght];
    char lastname[nameLenght];
    char studentid[studentidLenght];
    char major[defultStringLenght];
};

typedef struct Student Struct;

int main()
{
    int switch_choice, studentind, DB_rows;
    char choice_str[defultStringLenght];
    int *pStudentind = &studentind, *pDB_rows = &DB_rows;

    char date_string[defultStringLenght];
    char(*pDate_string)[defultStringLenght] = &date_string;

    bool exit = false;

    time_t current_time = time(NULL);
    strftime(date_string, 20, "%Y%m", localtime(&current_time));

    get_DB_row_ind(pStudentind, pDB_rows);

    while (exit == false)
    {
        switch_choice = 0;

        printf("%s"
               "Student record management system\n\n"
               "Menu:\n"
               "1. Add new student\n"
               "2. Edit student\n"
               "3. Delete student\n"
               "4. Search student\n"
               "5. Exit\n"
               "Enter your choice: ",
               separator);

        improved_fgets(choice_str, defultStringLenght);
        string_to_int_conv(choice_str, &switch_choice);

        switch (switch_choice)
        {
        case 1:
            add_student(pStudentind, pDB_rows);
            // printf("case 1");
            //  Add new student function here
            break;
        case 2:
            printf("case 2");
            // Edit student function here
            break;
        case 3:
            printf("case 3");
            // Delete student function here
            break;
        case 4:
            printf("case 4");
            // Search students function here
            break;
        case 5:
            printf("case 5");
            exit = true;
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}

// ##############################################################################
// ##############################################################################
// ######################### functions ##########################################
// ##############################################################################
// ##############################################################################

// Gets the current index for students and number of entries (rows) in DB.
void get_DB_row_ind(int *pStudentind, int *pDB_rows)
{
    FILE *pFile = fopen(DB, "r");
    fscanf(pFile, "%d %d", pStudentind, pDB_rows); // First int is current index for students always incremented by one. Second int is number of current entries in DB.
    fclose(pFile);
}

// Normal fgets() function but replaces \n with \0 and does error checking.
bool improved_fgets(char *stringToStoreTo, const int maxLenghtOfString)
{
    int num_of_0 = 0; // For testing input lenght.

    if (fgets(stringToStoreTo, maxLenghtOfString, stdin) != NULL)
    {
        size_t input_length = strlen(stringToStoreTo);
        if (input_length > 0 && stringToStoreTo[input_length - 1] == '\n')
        {
            stringToStoreTo[input_length - 1] = '\0';
        }
    }
    else
    {
        return false;
    }

    /*
    // If there's only one \0 then the user attempted to enter a string longer than maxLenghtOfString - 2.
    for (int i = 0; i < maxLenghtOfString; i++)
    {
        if (stringToStoreTo[i] == '\0')
        {
            num_of_0++;
        }
    }

    if (num_of_0 == 1)
    {
        printf("Error: input can only be up to %d characters long.\n", maxLenghtOfString - 2);
        fflush(stdin);  // May not work.
        return false;
    }
    */

    if (stringToStoreTo[0] == '\0')
    {
        printf("Error: Empty input.\n");
        return false;
    }

    return true; // Input read successfully
}

// Converts string to int and returns true if successful, does not allow partial converions.
bool string_to_int_conv(const char *str, int *result)
{
    char *endptr;

    long int num = strtol(str, &endptr, 10);

    if (*endptr != '\0')
    {

        for (char *p = endptr; *p != '\0'; p++)
        {
            if (!isdigit((unsigned char)*p))
            {
                printf("Error: could not complete conversion to integer, you entered a non integer.\n");
                return false;
            }
        }
        printf("Error: could not complete conversion to integer\n");
        return false;
    }

    *result = (int)num;
    return true;
}

// Converts string to double and returns true if successful.
bool string_to_double_conv(const char *inputStr, double *result)
{
    char *endptr;

    double num = strtod(inputStr, &endptr);

    if (*endptr != '\0')
    {
        printf("Error: could not complete conversion to double\n");
        return false;
    }
    else
    {
        *result = (int)num;
        return true;
    }
}

// Template for fgets while loop.
void fgets_string_whileloop_template(const char stringToPrint[], const char errorMsg[], char *stringToStoreTo, const int maxLenghtOfString)
{
    bool input_valid = false;

    while (input_valid == false)
    {
        printf("%s", stringToPrint);
        input_valid = improved_fgets(stringToStoreTo, maxLenghtOfString);
        if (input_valid == false)
        {
            printf("%s", errorMsg);
        }
    }
}

void add_student(int *studentindPointer, int *db_rowsPointer, const char (*date_string)[20])
{
    char firstname[nameLenght], lastname[nameLenght], buffer[bufferlenght], student_number[7], major_str[defultStringLenght];
    char studentid[13] = '\0';
    bool input_valid = false;
    char majors[4][20] = {"Biomimicry", "PuppetArts", "BicycleDesign", "EcoGastronomy"};
    char choice_str[defultStringLenght] = '\0';
    int choice = 0;

    FILE *tmpFile = fopen(TEMP, "w");
    FILE *pFile = fopen(DB, "r");

    (*studentindPointer)++;
    (*db_rowsPointer)++;

    sprintf(student_number, "%06d", *studentindPointer); // forms part of the final student ID.

    printf("%s", separator);

    // Gathering new student information.
    fgets_whileloop_template("Enter firstname: ",
                             "Error: Inputerror\n Please enter a valid firstname. Max 20 characters.\n",
                             firstname, nameLenght);
    printf("%s", firstname);

    fgets_whileloop_template("Enter lastname: ",
                             "Error: Inputerror\n Please enter a valid lastname. Max 20 characters.\n",
                             lastname, nameLenght);

    while (input_valid == false)
    {
        printf("\n\n"
               "Set student major\n"
               "1. Biomimicry\n"
               "2. Puppet Arts\n"
               "3. Bicycle Design\n"
               "4. EcoGastronomy\n"
               "Enter choice: ");

        improved_fgets(choice_str, defultStringLenght);
        string_to_int_conv(choice_str, choice);
        if (choice > 0 && choice < 5)
        {
            strcpy(major_str, majors[choice - 1]);
            input_valid = true;
        }
        else
        {
            printf("Error: Invalid choice\n");
        }
    }

    sprintf(student_number, "%06d", *studentindPointer); // forms part of the final student ID.
    strcat(studentid, *date_string);
    strcat(studentid, student_number);

    // Filling temporary file to store updated data.
    int count = 0;
    while ((fgets(buffer, 255, pFile)) != NULL)
    {
        count++;
        if (count == 1)
            fprintf(tmpFile, "%d %d\n", *studentindPointer, *db_rowsPointer);
        else
            fprintf(tmpFile, "%s", buffer);
    }

    // Creating new student entry.
    if (choice > 0 && choice < 5)
    {
        fprintf(tmpFile, "\n%d, %s, %s, %s, %s", *studentindPointer, firstname, lastname, studentid, majors[major - 1]);
    }
    else
    {
        printf("Enter a valid choice\n");

    }
}