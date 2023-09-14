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
#define MAJORS {"Biomimicry", "PuppetArts", "BicycleDesign", "EcoGastronomy"}
#define NUM_MAJORS 4

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

// prototypes
bool get_DB_row_ind(int *pStudentind, int *pDB_rows);
bool improved_fgets(char *stringToStoreTo, const int maxLenghtOfString);
bool string_to_int_conv(const char *str, int *result);
bool string_to_double_conv(const char *inputStr, double *result);
void fgets_string_whileloop(const char *stringToPrint, const char *retryMessage, char *stringToStoreTo, const int maxLenghtOfString);
void fgets_string_whileloop_alphanumerical(const char *stringToPrint, const char *retryMessage, char *stringToStoreTo, const int maxLenghtOfString);
void dtime_string(char *string_to_store_to);
bool zero_to_cancel(const char *inputStr);
bool create_studentid(struct Student *student);
void add_new_student();

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
            add_new_student();
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

/*  Gets the current index for students and number of entries (rows) in DB.
    Returns false if unable to open DB file or read correct string.*/
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

/*  Normal fgets() function but replaces \n with \0.
    Does not accept empty strings.
    checks if userinput is longer than maxLenghtOfString.
    clears string and returns false incase of error.*/
bool improved_fgets(char *stringToStoreTo, const int maxLenghtOfString)
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
                printf("\nError: Input over max accepted lenght of %d characters.\n", maxLenghtOfString - 1);
                stringToStoreTo[0] = '\0'; // Clearing string.
                return false;
            }
            i++;
        }
    }

    return true;
}

/*  Converts string to l int and returns true if successful, does not allow partial converions.
    Checks that input is within range and is possible to convert.
    Does not allow partial conversions Eg "3.6" -> "3" */
bool string_to_int_conv(const char *str, int *result)
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

/*  Converts string to double and returns true if successful.
    checks that input is within range and that conversion was possible.*/
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
void fgets_string_whileloop(const char *stringToPrint, const char *retryMessage, char *stringToStoreTo, const int maxLenghtOfString)
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

/*  Template for fgets while loop, only allows alphanumerical characters.
    Shows user where the error is incase of inputerror.*/
void fgets_string_whileloop_alphanumerical(const char *stringToPrint, const char *retryMessage, char *stringToStoreTo, const int maxLenghtOfString)
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
                printf("^\n");
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
void dtime_string(char *string_to_store_to)
{
    time_t current_time = time(NULL);
    strftime(string_to_store_to, 20, "%Y%m", localtime(&current_time));
}

/*  Checks if input is 'exit' and returns true if so.
    Doesn't edit inputStr. */
bool exit_to_cancel(const char *inputStr)
{
    // Convert to lowercase
    char inputStrLower[defaultStringLenght];
    int i = 0;
    for (i; i < strlen(inputStr); i++)
    {
        inputStrLower[i] = tolower(inputStr[i]);
    }
    inputStrLower[i] = '\0';

    if (strcmp(inputStrLower, "exit") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Creates student id and stores it in Student struct.
    Also stores student index and DB row in struct.*/
bool create_studentid(struct Student *student)
{
    // Student id == date (yyyy+mm) + student number (6 digits)
    char date_string[defaultStringLenght];

    // Fetching and adding datetime to studentid string.
    dtime_string(date_string);
    strcat(student->studentid, date_string);

    // Fetching/updating student index and DB rows.

    if (get_DB_row_ind(&student->studentind, &student->db_entry_row) == false)
    {
        // Error messages are done within get_DB_row_ind().
        return false;
    }
    student->studentind++;
    student->db_entry_row++;

    // Adding student index to studentid string.
    char modifiedStudentIndStr[defaultStringLenght];
    sprintf(modifiedStudentIndStr, "%06d", student->studentind);
    strcat(student->studentid, modifiedStudentIndStr);

    return true;
}

/*  Asks user to choose a major and stores it in intToStoreTo.
    Returns false if user cancels midway.
    Does error checking for if input is non int or out of range.*/
bool choose_major(char *stringToStoreTo)
{
    char userinput[inputbufferlenght];
    int userinput_int;

    char majors[NUM_MAJORS][defaultStringLenght] = MAJORS;
    char loopMsg[longStringLenght] = "Choose major\n1. Biomimicry\n2. Puppet Arts\n3. Bicycle Design\n4. EcoGastronomy\n";
    char errorMsg[longStringLenght] = "Please enter a valid choice. [Single integer number]\n";

    bool input_valid = false;
    while (input_valid == false)
    {
        fgets_string_whileloop_alphanumerical(loopMsg, errorMsg, userinput, inputbufferlenght);

        // Checking for cancellation.
        if (exit_to_cancel(userinput) == true)
        {
            printf("Cancelling...\n");
            return false;
        }
        // Validate input
        input_valid = string_to_int_conv(userinput, &userinput_int);
        if (input_valid == false)
        {
            printf("%s", errorMsg);
        }
        // validate range.
        else if (userinput_int < 1 || userinput_int > 4)
        {
            printf("\nError: Enter a number between 1 an 4\n");
            input_valid = false;
        }
    }

    strcpy(stringToStoreTo, majors[userinput_int - 1]);

    return true;
}

// Converts string to all lowercase.
void convert_to_lowercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
}

// TODO: Need to finish these later.
bool final_DBentry_checks(struct Student *student)
{
    int errors_found = 0;
    char errorcodes[defaultStringLenght];
    
    // checking for non alphanumerical characters.
    for (int i = 0; i < strlen(student->firstname); i++)
    {
        if (isalnum(student->firstname[i]) == false)
        {
            errorcodes[errors_found] = '1'; // Non alphanumerical character found in firstname.
            errors_found++;
            break;
        }
    }

    for (int i = 0; i < strlen(student->lastname); i++)
    {
        if (isalnum(student->lastname[i]) == false)
        {
            errorcodes[errors_found] = '2'; // Non alphanumerical character found in lastname.
            errors_found++;
            break;
        }
    }

    // Checking len of strings.
    if (strlen(student->firstname) > nameLenght - 1)
    {
        errorcodes[errors_found] = '3'; // Firstname too long.
        errors_found++;
    }
    if (strlen(student->lastname) > nameLenght - 1)
    {
        errorcodes[errors_found] = '4'; // Lastname too long.
        errors_found++;
    }

    
}

void add_new_student()
{
    // Gathering new student information.
    // Creating firstname.
    struct Student newStudent;
    char inputstr[longStringLenght];
    sprintf(inputstr, "Enter firstname (max %d alphanumerical characters only!)\n", nameLenght - 1);

    char errorMsg[longStringLenght] = "Please enter a valid firstname.\n";

    printf("%s", separator);
    fgets_string_whileloop_alphanumerical(inputstr, errorMsg, newStudent.firstname, nameLenght);
    if (exit_to_cancel(newStudent.firstname) == true)
    {
        printf("Cancelling...\n");
        return;
    }

    // Creating lastname.
    sprintf(inputstr, "Enter lastname (max %d alphanumerical characters only!)\n", nameLenght - 1);

    char errorMsg2[longStringLenght] = "Please enter a valid lastname.\n";

    printf("%s", separator);
    fgets_string_whileloop_alphanumerical(inputstr, errorMsg2, newStudent.lastname, nameLenght);
    if (exit_to_cancel(newStudent.lastname) == true)
    {
        printf("Cancelling...\n");
        return;
    }

    // Creating studentid.
    // Student id == date (yyyy+mm) + student number (6 digits)
    create_studentid(&newStudent);

    // Choosing major.
    printf("%s", separator);
    choose_major(newStudent.major);

    // Confirming student record.
    printf("%s", separator);

    printf("Student will be added with the following information\n"
           "Firstname: %s\n"
           "Lastname: %s\n"
           "Studentid: %s\n"
           "Major: %s\n",
           newStudent.firstname, newStudent.lastname, newStudent.studentid, newStudent.major);

    char userinput[defaultStringLenght] = "\0";
    printf("Is this correct? [yes/no]\n");
    printf("Input: ");
    improved_fgets(userinput, defaultStringLenght);
    convert_to_lowercase(userinput);
    while (stricmp(userinput, "yes") != 0 && stricmp(userinput, "no") != 0 && stricmp(userinput, "y") != 0 && stricmp(userinput, "n") != 0)
    {
        printf("Error: Please enter \"yes\" or \"no\".\n");
        printf("Input: ");
        improved_fgets(userinput, defaultStringLenght);
        convert_to_lowercase(userinput);
    }
    if (stricmp(userinput, "no") == 0 || stricmp(userinput, "n") == 0)
    {
        printf("Cancelling...\n");
        return;
    }

    // Adding student to DB and final suite of tests before adding student to DB.
    printf("Adding student to DB.\n");
    FILE *tmpFile = fopen(TEMP, "w");
    FILE *pFile = fopen(DB, "r");

    // Copying existing data to temp file.
    int rowCount = 0;
    char buffer[inputbufferlenght];
    while (fgets(buffer, inputbufferlenght, pFile) != NULL)
    {
        rowCount++;
        if (rowCount == 1)
        {
            fprintf(tmpFile, "%d %d\n", newStudent.studentind, newStudent.db_entry_row);
        }
        else
        {
            fprintf(tmpFile, "%s", buffer);
        }
    }

    // Adding new entry to temp file.
    fprintf(tmpFile, "%s %s %s %s\n", newStudent.firstname, newStudent.lastname, newStudent.studentid, newStudent.major);

    fclose(pFile);
    fclose(tmpFile);

    // Updating database.
    remove(DB);
    rename(TEMP, DB);
    printf("New student added to DB.\n");
}
