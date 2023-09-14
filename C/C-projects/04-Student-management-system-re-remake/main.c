#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>

// #defines
#define DB "db.txt"
#define TEMP "temp.tmp"
#define nameLenght 21
#define inputbufferlenght 256
#define longStringLenght 256
#define studentidLenght 13
#define defaultStringLenght 21
#define separator "\n\n----------------------------------------\n\n"

// prototypes
bool get_DB_row_ind(int *pStudentind, int *pDB_rows);
bool improved_fgets(char stringToStoreTo[], const int maxLenghtOfString);
bool string_to_int_conv(const char str[], int *result);
bool string_to_double_conv(const char *inputStr, double *result);
void fgets_string_whileloop(const char stringToPrint[], const char retryMessage[], char *stringToStoreTo, const int maxLenghtOfString);
void fgets_string_whileloop_alphanumerical(const char stringToPrint[], const char retryMessage[], char *stringToStoreTo, const int maxLenghtOfString);
void dtime_string(char string_to_store_to[defaultStringLenght]);
bool zero_to_cancel(const char inputStr[]);
bool create_studentid(char pointerStudentIDlocation[]);
void add_student();

// structs
struct Student
{
    int studentind, db_entry_row;
    char firstname[nameLenght];
    char lastname[nameLenght];
    char studentid[studentidLenght];
    char major[defaultStringLenght];
};

typedef struct Student Struct;

int main()
{
    int switch_choice;
    char choice_str[defaultStringLenght];

    bool exit = false;

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

        improved_fgets(choice_str, defaultStringLenght);
        string_to_int_conv(choice_str, &switch_choice);

        switch (switch_choice)
        {
        case 1:
            add_student();
            // add_student(pStudentind, pDB_rows);
            //  printf("case 1");
            //   Add new student function here
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
bool get_DB_row_ind(int *pStudentind, int *pDB_rows)
{
    FILE *pFile = fopen(DB, "r");
    if (pFile == NULL)
    {
        printf("Error: Unable to open the file '%s'\n", DB);
        return false;
    }

    int readCount = fscanf(pFile, "%d %d", pStudentind, pDB_rows);
    if (readCount != 2)
    {
        printf("Error: Failed to read data from the file '%s'\n", DB);
        return false;
    }

    fclose(pFile);
    return true;
}

// Normal fgets() function but replaces \n with \0 and does error checking.
bool improved_fgets(char stringToStoreTo[], const int maxLenghtOfString)
{
    bool newline_found = false;
    int i = 0;

    if (fgets(stringToStoreTo, inputbufferlenght, stdin) != NULL)
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
                printf("Error: Input over max accepted lenght of %d characters.\n", maxLenghtOfString - 1);
                stringToStoreTo[0] = '\0'; // Clearing string.
                return false;
            }
            i++;
        }
    }

    return true;
}

// Converts string to int and returns true if successful, does not allow partial converions.
bool string_to_int_conv(const char str[], int *result)
{
    char *endptr;
    errno = 0;
    long int num = strtol(str, &endptr, 10);

    if (errno == ERANGE)
    {
        printf("Error: could not complete conversion to integer, number out of range.\n"
               "Enter a number between %d and %d.\n",
               LONG_MIN, LONG_MAX);
        return false;
    }
    else if (*endptr != '\0')
    {

        for (char *p = endptr; *p != '\0'; p++)
        {
            if (!isdigit((unsigned char)*p))
            {
                printf("Error: could not complete conversion to integer, you entered a non integer.\n");
                return false;
            }
        }
        printf("Error: could not read an integer.\n");
        return false;
    }

    *result = num;
    return true;
}

// Converts string to double and returns true if successful.
bool string_to_double_conv(const char *inputStr, double *result)
{
    char *endptr;
    errno = 0;
    double num = strtod(inputStr, &endptr);

    if (errno == ERANGE)
    {
        printf("Error: could not complete conversion to double, number out of range.\n"
               "Enter a number between %f and %f.\n",
               DBL_MIN, DBL_MAX);
        return false;
    }
    else if (*endptr != '\0')
    {
        printf("Error: could not complete conversion to double\n");
        return false;
    }

    *result = num;
    return true;
}

// Template for fgets while loop.
void fgets_string_whileloop(const char stringToPrint[], const char retryMessage[], char *stringToStoreTo, const int maxLenghtOfString)
{
    bool input_valid = false;

    while (input_valid == false)
    {
        printf("%s", stringToPrint);
        printf("Or input 'Exit' to cancel.\n"
               "Your input: ");
        input_valid = improved_fgets(stringToStoreTo, maxLenghtOfString);
        if (input_valid == false)
        {
            printf("%s", retryMessage); // Error handling is done within improved_fgets(), used for prompting user to try again.
        }
    }
}

// Template for fgets while loop, only allows alphanumerical characters.
void fgets_string_whileloop_alphanumerical(const char stringToPrint[], const char retryMessage[], char *stringToStoreTo, const int maxLenghtOfString)
{
    bool input_valid = false;

    while (input_valid == false)
    {
        printf("%s", stringToPrint);
        printf("Or input 'Exit' to cancel.\n"
               "Your input: ");
        input_valid = improved_fgets(stringToStoreTo, maxLenghtOfString);

        // Alphanumerical test.
        int i = 0;
        while (input_valid == true && stringToStoreTo[i] != '\0')
        {
            if (isalnum(stringToStoreTo[i]) == false)
            {
                // Showing user where the error occured.
                printf("\nNon alphanumerical character detected at character %d (%c)\n"
                       "Your input: %s\n"
                       "Error loc:  ",
                       i + 1, stringToStoreTo[i], stringToStoreTo);

                for (int j = 0; j < i; j++)
                {
                    printf(" ");
                }
                printf("^\n\n");
                input_valid = false;
            }
            i++;
        }

        if (input_valid == false)
        {
            printf("%s", retryMessage); // Prompting user to try again.
        }
    }
}

// Gets current datetime and stores it in string_to_store_to.
void dtime_string(char string_to_store_to[defaultStringLenght])
{
    time_t current_time = time(NULL);
    strftime(string_to_store_to, 20, "%Y%m", localtime(&current_time));
}

// Checks if input is 'Exit' and returns true if so.
bool Exit_to_cancel(const char inputStr[])
{
    if (strcmp(inputStr, "Exit") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Creates student id and stores it in pointerStudentIDlocation.
bool create_studentid(char pointerStudentIDlocation[])
{
    // Student id == date (yyyy+mm) + student number (6 digits)
    char date_string[defaultStringLenght];

    // Fetching and adding datetime to studentid string.
    dtime_string(date_string);
    strcat(pointerStudentIDlocation, date_string);

    // Fetching/updating student index and DB rows.
    int currentstudentind, currentdbrows;
    currentstudentind++;
    currentdbrows++;

    if (get_DB_row_ind(&currentstudentind, &currentdbrows) == false)
    {
        // Error messages are done within get_DB_row_ind().
        return false;
    }

    // Adding student index to studentid string.
    char currentstudentind_str[defaultStringLenght];
    sprintf(currentstudentind_str, "%06d", currentstudentind);
    strcat(pointerStudentIDlocation, currentstudentind_str);

    return true;
}

// Asks user to choose a major and stores it in intToStoreTo.
bool choose_major(char intToStoreTo[])
{
    char userinput[inputbufferlenght];
    int userinput_int;

    char loopMsg[longStringLenght] = "Choose major\n1. Biomimicry\n2. Puppet Arts\n 3. Bicycle Design\n 4. EcoGastronomy\n";
    char errorMsg[longStringLenght] = "Please enter a valid choice. [Single integer number]\n";

    bool input_valid = false;
    while (input_valid == false)
    {
        fgets_string_whileloop_alphanumerical(loopMsg, errorMsg, userinput, inputbufferlenght);

        // Checking for cancellation.
        if (Exit_to_cancel(userinput) == true)
        {
            printf("Cancelling...\n");
            return false;
        }
        input_valid = string_to_int_conv(userinput, &userinput_int);
        if (input_valid == false)
        {
            printf("%s", errorMsg);
        }

        else if (userinput_int < 1 || userinput_int > 4)
        {
            printf("Enter a number betwee 1 an 4\n");
            printf("%s", errorMsg);
            input_valid = false;
        }
    }

    return true;
}

void add_student()
{
    FILE *tmpFile = fopen(TEMP, "w");
    FILE *pFile = fopen(DB, "r");

    // Gathering new student information.
    char firstname[nameLenght];
    char inputstr[longStringLenght];
    sprintf(inputstr, "Enter firstname (max %d alphanumerical characters only!)\n", nameLenght - 1);

    char errorMsg[longStringLenght] = "Please enter a valid firstname.\n";

    printf("%s", separator);
    fgets_string_whileloop_alphanumerical(inputstr, errorMsg, firstname, nameLenght);
    if (Exit_to_cancel(firstname) == true)
    {
        printf("Cancelling...\n");
        return;
    }

    char lastname[nameLenght];
    sprintf(inputstr, "Enter lastname (max %d alphanumerical characters only!)\n", nameLenght - 1);

    char errorMsg2[longStringLenght] = "Please enter a valid lastname.\n";

    printf("%s", separator);
    fgets_string_whileloop_alphanumerical(inputstr, errorMsg2, lastname, nameLenght);
    if (Exit_to_cancel(lastname) == true)
    {
        printf("Cancelling...\n");
        return;
    }

    // Student id == date (yyyy+mm) + student number (6 digits)
    char studentid[studentidLenght];
    create_studentid(studentid);

    printf("student record: %s %s %s\n", firstname, lastname, studentid);
}
