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
#define NAME_LENGHT 21
#define INPUT_BUFFER_LENGHT 256
#define LONG_STRING_LENGHT 256
#define STUDENT_ID_LENGHT 13
#define DEFAULT_STRING_LENGHT 21
#define SEPARATOR "\n\n----------------------------------------\n\n"
#define MAJORS                                                       \
    {                                                                \
        "Biomimicry", "PuppetArts", "BicycleDesign", "EcoGastronomy" \
    }
#define NUM_MAJORS 4

// structs
struct Student
{
    int studentind, db_entry_row;
    char firstname[NAME_LENGHT];
    char lastname[NAME_LENGHT];
    char studentid[STUDENT_ID_LENGHT];
    char major[DEFAULT_STRING_LENGHT];
};

typedef struct Student Struct;

// prototypes
bool getDBRowInd(int *pStudentind, int *pDB_rows);
bool improvedFgets(char *stringToStoreTo, const int maxLenghtOfString);
bool stringToIntConv(const char *str, int *result);
bool stringToDoubleConv(const char *inputStr, double *result);
void fgetsStringWhileLoop(const char *stringToPrint, const char *retryMessage, char *stringToStoreTo, const int maxLenghtOfString);
void fgetsStringWhileLoopAlphanumerical(const char *stringToPrint, const char *retryMessage, char *stringToStoreTo, const int maxLenghtOfString);
void dtimeString(char *string_to_store_to);
bool zeroToCancel(const char *inputStr);
bool createStudentId(struct Student *student);
void addNewStudent();
int getIndNum(const char *buffer);
void editStudentEntry();

/*  Fetches student data from DB and returns it as a Struct.
    Requires studentind to find correct data.*/
Struct fetch_student_data(int studentind)
{
    Struct student;
    int tokencount = 0, linecount = 0;
    char *token, buffer[LONG_STRING_LENGHT];
    FILE *dbFile = fopen(DB, "r");
    bool entry_found = false;

    while ((fgets(buffer, LONG_STRING_LENGHT, dbFile)) != NULL && entry_found == false)
    {
        linecount++;
        if (getIndNum(buffer) == studentind)
        {
            token = strtok(buffer, ", ");
            while (token != NULL)
            {
                switch (tokencount)
                {
                case 0:
                    stringToIntConv(token, &student.studentind);
                    break;
                case 1:
                    strncpy(student.firstname, token, sizeof(student.firstname) - 1);
                    student.firstname[sizeof(student.firstname) - 1] = '\0';
                    break;
                case 2:
                    strncpy(student.lastname, token, sizeof(student.lastname) - 1);
                    student.lastname[sizeof(student.lastname) - 1] = '\0';
                    break;
                case 3:
                    strncpy(student.studentid, token, sizeof(student.studentid) - 1);
                    student.studentid[sizeof(student.studentid) - 1] = '\0';
                    break;
                case 4:
                    strncpy(student.major, token, sizeof(student.major) - 1);
                    student.major[sizeof(student.major) - 1] = '\0';
                    break;
                }

                token = strtok(NULL, ", ");
                tokencount++;
            }
            student.db_entry_row = linecount;
            entry_found = true;
        }
    }

    if (entry_found == false)
    {
        printf("Error: Student record with index %d not found.\n", studentind);
    }

    fclose(dbFile);
    return student;
}

int main()
{
    int switch_choice;
    char choice_str[DEFAULT_STRING_LENGHT] = "\0";

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
               SEPARATOR);

        improvedFgets(choice_str, DEFAULT_STRING_LENGHT);
        stringToIntConv(choice_str, &switch_choice);

        switch (switch_choice)
        {
        case 1:
            addNewStudent();
            break;
        case 2:
            printf("case 2");
            editStudentEntry();
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
bool getDBRowInd(int *pStudentind, int *pDB_rows)
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

/*  Converts string to l int and returns true if successful, does not allow partial converions.
    Checks that input is within range and is possible to convert.
    Does not allow partial conversions Eg "3.6" -> "3" */
bool stringToIntConv(const char *str, int *result)
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
bool stringToDoubleConv(const char *inputStr, double *result)
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
void fgetsStringWhileLoop(const char *stringToPrint, const char *retryMessage, char *stringToStoreTo, const int maxLenghtOfString)
{
    bool input_valid = false;

    while (input_valid == false)
    {
        printf("%s", stringToPrint);
        printf("Or input 'Exit' to cancel.\n"
               "Input: ");
        input_valid = improvedFgets(stringToStoreTo, maxLenghtOfString);
        if (input_valid == false)
        {
            printf("%s", retryMessage); // Error handling is done within improvedFgets(), used for prompting user to try again.
        }
    }
}

/*  Template for fgets while loop, only allows alphanumerical characters.
    Shows user where the error is incase of inputerror.*/
void fgetsStringWhileLoopAlphanumerical(const char *stringToPrint, const char *retryMessage, char *stringToStoreTo, const int maxLenghtOfString)
{
    bool input_valid = false;

    while (input_valid == false)
    {
        printf("%s", stringToPrint);
        printf("Or input 'Exit' to cancel.\n"
               "Your input: ");
        input_valid = improvedFgets(stringToStoreTo, maxLenghtOfString);

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
void dtimeString(char *string_to_store_to)
{
    time_t current_time = time(NULL);
    strftime(string_to_store_to, 20, "%Y%m", localtime(&current_time));
}

/*  Checks if input is 'exit' and returns true if so.
    Doesn't edit inputStr. */
bool exit_to_cancel(const char *inputStr)
{
    // Convert to lowercase
    char inputStrLower[DEFAULT_STRING_LENGHT];
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
bool createStudentId(struct Student *student)
{
    // Student id == date (yyyy+mm) + student number (6 digits)
    student->studentid[0] = '\0'; // Clearing string, 'cause for some black voodoo magic this particular string loves to pickup random garbage from userinput, but only if that userinput gets rejected??!?!?!?!!
    char date_string[DEFAULT_STRING_LENGHT] = "\0";

    // Fetching and adding datetime to studentid string.
    dtimeString(date_string);
    strcat(student->studentid, date_string);

    // Fetching/updating student index and DB rows.

    if (getDBRowInd(&student->studentind, &student->db_entry_row) == false)
    {
        // Error messages are done within getDBRowInd().
        return false;
    }
    student->studentind++;
    student->db_entry_row++;

    // Adding student index to studentid string.
    char modifiedStudentIndStr[DEFAULT_STRING_LENGHT] = "\0";
    sprintf(modifiedStudentIndStr, "%06d", student->studentind);
    strcat(student->studentid, modifiedStudentIndStr);

    return true;
}

/*  Asks user to choose a major and stores it in intToStoreTo.
    Returns false if user cancels midway.
    Does error checking for if input is non int or out of range.*/
bool choose_major(char *stringToStoreTo)
{
    char userinput[INPUT_BUFFER_LENGHT] = "\0";
    int userinput_int;

    char majors[NUM_MAJORS][DEFAULT_STRING_LENGHT] = MAJORS;
    char loopMsg[LONG_STRING_LENGHT] = "Choose major\n1. Biomimicry\n2. Puppet Arts\n3. Bicycle Design\n4. EcoGastronomy\n";
    char errorMsg[LONG_STRING_LENGHT] = "Please enter a valid choice. [Single integer number]\n";

    bool input_valid = false;
    while (input_valid == false)
    {
        fgetsStringWhileLoopAlphanumerical(loopMsg, errorMsg, userinput, INPUT_BUFFER_LENGHT);

        // Checking for cancellation.
        if (exit_to_cancel(userinput) == true)
        {
            printf("Cancelling...\n");
            return false;
        }
        // Validate input
        input_valid = stringToIntConv(userinput, &userinput_int);

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
    char errorcodes[DEFAULT_STRING_LENGHT] = "\0";

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
    if (strlen(student->firstname) > NAME_LENGHT - 1)
    {
        errorcodes[errors_found] = '3'; // Firstname too long.
        errors_found++;
    }
    if (strlen(student->lastname) > NAME_LENGHT - 1)
    {
        errorcodes[errors_found] = '4'; // Lastname too long.
        errors_found++;
    }
}

void addNewStudent()
{
    // Gathering new student information.
    // Creating firstname.
    struct Student newStudent;
    char inputstr[LONG_STRING_LENGHT] = "\0";
    sprintf(inputstr, "Enter firstname (max %d alphanumerical characters only!)\n", NAME_LENGHT - 1);

    char errorMsg[LONG_STRING_LENGHT] = "Please enter a valid firstname.\n";

    printf("%s", SEPARATOR);
    fgetsStringWhileLoopAlphanumerical(inputstr, errorMsg, newStudent.firstname, NAME_LENGHT);
    if (exit_to_cancel(newStudent.firstname) == true)
    {
        printf("Cancelling...\n");
        return;
    }

    // Creating lastname.
    sprintf(inputstr, "Enter lastname (max %d alphanumerical characters only!)\n", NAME_LENGHT - 1);

    char errorMsg2[LONG_STRING_LENGHT] = "Please enter a valid lastname.\n";

    printf("%s", SEPARATOR);
    fgetsStringWhileLoopAlphanumerical(inputstr, errorMsg2, newStudent.lastname, NAME_LENGHT);
    if (exit_to_cancel(newStudent.lastname) == true)
    {
        printf("Cancelling...\n");
        return;
    }

    // Creating studentid.
    // Student id == date (yyyy+mm) + student number (6 digits)
    createStudentId(&newStudent);

    // Choosing major.
    printf("%s", SEPARATOR);
    if (choose_major(newStudent.major) == false)
    {
        return;
    }

    // Confirming student record.
    printf("%s", SEPARATOR);

    printf("Student will be added with the following information\n"
           "Firstname: %s\n"
           "Lastname: %s\n"
           "Studentid: %s\n"
           "Major: %s\n",
           newStudent.firstname, newStudent.lastname, newStudent.studentid, newStudent.major);

    char userinput[DEFAULT_STRING_LENGHT] = "\0";
    printf("Is this correct? [yes/no]\n");
    printf("Input: ");
    improvedFgets(userinput, DEFAULT_STRING_LENGHT);
    convert_to_lowercase(userinput);
    while (stricmp(userinput, "yes") != 0 && stricmp(userinput, "no") != 0 && stricmp(userinput, "y") != 0 && stricmp(userinput, "n") != 0)
    {
        printf("Error: Please enter \"yes\" or \"no\".\n");
        printf("Input: ");
        improvedFgets(userinput, DEFAULT_STRING_LENGHT);
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
    char buffer[INPUT_BUFFER_LENGHT] = "\0";
    while (fgets(buffer, INPUT_BUFFER_LENGHT, pFile) != NULL)
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
    fprintf(tmpFile, "\n%d, %s, %s, %s, %s", newStudent.studentind, newStudent.firstname, newStudent.lastname, newStudent.studentid, newStudent.major);

    fclose(pFile);
    fclose(tmpFile);

    // Updating database.

    remove(DB);
    rename(TEMP, DB);

    printf("New student added to DB.\n");
}

// Gets the index number from DB entry.
int getIndNum(const char *buffer)
{
    char index_number[DEFAULT_STRING_LENGHT];
    int numberlength = 0;
    for (int i = 0; i < strlen(buffer); i++)
    {
        if (buffer[i] == ',')
        {
            break;
        }
        index_number[numberlength] = buffer[i];
        numberlength++;
    }

    return strtol(index_number, NULL, 10);
}

void editStudentEntry()
{
    // Asking for ind of student to edit.
    char userinput[DEFAULT_STRING_LENGHT] = "\0";
    int studentind = 0;

    char promptMsg[LONG_STRING_LENGHT] = "\nEnter student index number (Leftmost column in DB).\n";
    char errorMsg[LONG_STRING_LENGHT] = "Please enter a valid student index number.\n";

    printf("%s", SEPARATOR);
    do
    {
        fgetsStringWhileLoop(promptMsg, errorMsg, userinput, DEFAULT_STRING_LENGHT);
        if (strcmp(userinput, "exit") == 0)
        {
            printf("Cancelling...\n");
            return;
        }
    } while (stringToIntConv(userinput, &studentind) == false);

    // Fetching current student data into struct.
    struct Student student = fetch_student_data(studentind);

    // Confirming what information to edit.
    printf("%s", SEPARATOR);
    char promptMsg2[LONG_STRING_LENGHT] = "\n1. Firstname\n2. Lastname\n3. major\n4. Exit\nChoose data to change.\n";
    char errorMsg2[LONG_STRING_LENGHT] = "Enter a valid integer between range 1-4.\n";
    int choice = 0;
    bool input_valid = false;
    while (input_valid == false)
    {
        fgetsStringWhileLoop(promptMsg2, errorMsg2, userinput, DEFAULT_STRING_LENGHT);
        input_valid = stringToIntConv(userinput, &choice);
        if (choice < 1 || choice > 4)
        {
            printf("Error: Enter a valid integer between range 1-4.\n");
            input_valid = false;
        }
        if (strcmp(userinput, "exit") == 0)
        {
            printf("Cancelling...\n");
            return;
        }
    }


}