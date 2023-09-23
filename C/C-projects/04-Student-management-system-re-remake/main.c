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
#define STUDENT_ID_LENGHT 13
#define DEFAULT_STRING_LENGHT 21
#define INPUT_BUFFER_LENGHT 256 // Used for any array that is expected to store userinput.
#define LONG_STRING_LENGHT 256  // Used for any array that is expected to store long strings but not nessecarily userinput.
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
    char firstname[INPUT_BUFFER_LENGHT];
    char lastname[INPUT_BUFFER_LENGHT];
    char studentid[INPUT_BUFFER_LENGHT];
    char major[LONG_STRING_LENGHT];
    int fetchFailure;
};

typedef struct Student Struct;

// prototypes
bool getDBRowInd(int *pStudentind, int *pDB_rows);
bool improvedFgets(char *stringToStoreTo, const int maxLenghtOfString);
bool stringToIntConv(const char *str, int *result);
bool stringToDoubleConv(const char *inputStr, double *result);
void fgetsStringWhileLoopAlphanumerical(const char *stringToPrint, const char *retryMessage, char *stringToStoreTo, const int maxLenghtOfString);
void dtimeString(char *stringToStoreTo);
bool zeroToCancel(const char *inputStr);
bool createStudentId(struct Student *student);
void addNewStudent();
int getIndNum(const char *buffer);
void editStudentEntry();
void addNewEntryToDB(struct Student studentStruct);
FILE *openFileWithRetry(const char *fileName, const char *mode, int maxRetries);
void deleteStudentEntry();
void lookupOrBrowse();
bool stringIsYesOrNo(const char *str);
void browseStudentList();
void lookupStudent();

/*  Fetches student data from DB and returns it as a Struct.
    Requires studentind to find correct data.*/
Struct fetch_student_data(const int studentind)
{
    Struct student = {0};
    int tokencount = 0, linecount = 0;
    char *token, buffer[LONG_STRING_LENGHT] = "\0";

    FILE *dbFile = openFileWithRetry(DB, "r", 3);
    if (dbFile == NULL)
    {
        printf("Unable to open file %s", DB);
        printf("Cancelling...");
        student.fetchFailure = 1; // Incase of failure.
        return student;
    }

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
    int switch_choice = 0;
    char choice_str[INPUT_BUFFER_LENGHT] = "\0";

    bool exit = false;

    while (exit == false)
    {

        while (switch_choice < 1 || switch_choice > 5)
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
        }

        switch (switch_choice)
        {
        case 1:
            addNewStudent();
            break;
        case 2:
            editStudentEntry();
            break;
        case 3:
            deleteStudentEntry();
            break;
        case 4:
            lookupOrBrowse();
            break;
        case 5:
            printf("Terminating program...\n");
            exit = true;
            break;
        default:
            printf("How'd you get in here?\nThis is probably an endless loop.\n");
            break;
        }
    }

    return 0;
}

/*  Gets the current index for students and number of entries (rows) in DB.
    Returns false if unable to open DB file or read correct string.*/
bool getDBRowInd(int *pStudentind, int *pDB_rows)
{
    FILE *pFile = openFileWithRetry(DB, "r", 3);

    if (pFile == NULL)
    {
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

        // Checking for empty input.
        if (stringToStoreTo[0] == '\n' || stringToStoreTo[0] == '\0')
        {
            printf("Error: Empty input.\n");
            return false;
        }

        // Replacing \n with \0.
        while (newline_found == false)
        {
            if (stringToStoreTo[i] == '\n')
            {
                newline_found = true;
                stringToStoreTo[i] = '\0';
            }

            // Checking if input is over maxLenghtOfString.
            if (i >= maxLenghtOfString - 1)
            {
                printf("\nError: Input over max accepted lenght of %d characters.\n", maxLenghtOfString - 1);
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

    // Checking if input is beyond range of long int.
    if (errno == ERANGE)
    {
        printf("Error: could not complete conversion to integer, number out of range.\n"
               "Enter a number between %d and %d.\n",
               LONG_MIN, LONG_MAX);
        return false;
    }

    // Checking if input contained anything other than numbers.
    else if (*endptr != '\0')
    {

        // Checking if input is non numerical.
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

    // Checking if input is beyond range of double.
    if (errno == ERANGE)
    {
        printf("Error: could not complete conversion to double, number out of range.\n"
               "Enter a number between %f and %f.\n",
               DBL_MIN, DBL_MAX);
        return false;
    }

    // Checking if input contained anything other than numbers.
    else if (*endptr != '\0')
    {
        printf("Error: could not complete conversion to double\n");
        return false;
    }

    *result = num;
    return true;
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
void dtimeString(char *stringToStoreTo)
{
    time_t current_time = time(NULL);
    strftime(stringToStoreTo, 20, "%Y%m", localtime(&current_time));
}

/*  Checks if input is 'exit' and returns true if so.
    Doesn't edit inputStr. */
bool exit_to_cancel(const char *inputStr)
{
    // Convert to lowercase
    char inputStrLower[INPUT_BUFFER_LENGHT];
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
    char date_string[INPUT_BUFFER_LENGHT] = "\0";

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
    char modifiedStudentIndStr[INPUT_BUFFER_LENGHT] = "\0";
    sprintf(modifiedStudentIndStr, "%06d", student->studentind);
    strcat(student->studentid, modifiedStudentIndStr);

    return true;
}

/*  Asks user to choose a major and stores it in intToStoreTo.
    Returns false if user cancels midway.
    Does error checking for if input is non int or out of range.*/
bool chooseMajor(char *stringToStoreTo)
{
    char userinput[INPUT_BUFFER_LENGHT] = "\0";
    int userinput_int;

    char majors[NUM_MAJORS][LONG_STRING_LENGHT] = MAJORS;
    char loopMsg[LONG_STRING_LENGHT] = "Choose major\n1. Biomimicry\n2. Puppet Arts\n3. Bicycle Design\n4. EcoGastronomy\n";
    char errorMsg[LONG_STRING_LENGHT] = "Please enter a valid choice. [Single integer number]\n";

    bool input_valid = false;
    while (input_valid == false)
    {
        fgetsStringWhileLoopAlphanumerical(loopMsg, errorMsg, userinput, DEFAULT_STRING_LENGHT);

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
void convertToLowercase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
}

// TODO: Finish later.
bool final_DBentry_checks(struct Student *student)
{
    int errors_found = 0;
    char errorcodes[INPUT_BUFFER_LENGHT] = "\0";

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

void addNewEntryToDB(struct Student studentStruct)
{
    FILE *tmpFile = openFileWithRetry(TEMP, "w", 3);
    if (tmpFile == NULL)
    {
        printf("Error: Unable to open the file '%s'\n", TEMP);
        return;
    }

    FILE *pFile = openFileWithRetry(DB, "r", 3);
    if (pFile == NULL)
    {
        printf("Error: Unable to open the file '%s'\n", DB);
        return;
    }

    // Copying existing data to temp file.
    int rowCount = 0;
    char buffer[INPUT_BUFFER_LENGHT] = "\0";
    while (fgets(buffer, INPUT_BUFFER_LENGHT, pFile) != NULL)
    {
        rowCount++;
        if (rowCount == 1)
        {
            fprintf(tmpFile, "%d %d\n", studentStruct.studentind, studentStruct.db_entry_row);
        }
        else
        {
            fprintf(tmpFile, "%s", buffer);
        }
    }

    // Adding new entry to temp file.
    fprintf(tmpFile, "\n%d, %s, %s, %s, %s", studentStruct.studentind, studentStruct.firstname, studentStruct.lastname, studentStruct.studentid, studentStruct.major);

    fclose(pFile);
    fclose(tmpFile);

    // Updating database.
    remove(DB);
    rename(TEMP, DB);
}

/*  Modifies existing entry in DB.
    Uses entryrow stored in struct.db_entry_row to locate entry.
    Returns True/False is entry is found/not found. */
bool modifyEntryToDB(struct Student studentStruct)
{
    printf("modifying data.\n");
    FILE *tmpFile = openFileWithRetry(TEMP, "w", 3);
    if (tmpFile == NULL)
    {
        printf("Error: Unable to open the file '%s'\n", TEMP);
        return false;
    }

    FILE *pFile = openFileWithRetry(DB, "r", 3);
    if (pFile == NULL)
    {
        printf("Error: Unable to open the file '%s'\n", DB);
        return false;
    }

    // Copying existing data to temp file and replacing entry with new data.
    int rowCount = 0;
    char buffer[INPUT_BUFFER_LENGHT] = "\0";
    bool entry_found = false;
    while ((fgets(buffer, INPUT_BUFFER_LENGHT, pFile)) != NULL)
    {
        // Replacing specified entry with new data.
        rowCount++;
        if (rowCount == studentStruct.db_entry_row)
        {
            fprintf(tmpFile, "%d, %s, %s, %s, %s", studentStruct.studentind, studentStruct.firstname, studentStruct.lastname, studentStruct.studentid, studentStruct.major);
            entry_found = true;
        }

        // Copying existing data to temp file.
        else
        {
            fprintf(tmpFile, "%s", buffer);
        }
    }

    fclose(pFile);
    fclose(tmpFile);

    // Updating database.
    remove(DB);
    rename(TEMP, DB);
    return entry_found;
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
    if (chooseMajor(newStudent.major) == false)
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

    char userinput[INPUT_BUFFER_LENGHT] = "\0";
    printf("Is this correct? [yes/no]\n");
    printf("Input: ");
    improvedFgets(userinput, DEFAULT_STRING_LENGHT);
    convertToLowercase(userinput);

    while ((stringIsYesOrNo(userinput) == false))
    {
        printf("Error: Please enter \"yes\" or \"no\".\n");
        printf("Input: ");
        improvedFgets(userinput, DEFAULT_STRING_LENGHT);
        convertToLowercase(userinput);
    }

    if (stricmp(userinput, "no") == 0 || stricmp(userinput, "n") == 0)
    {
        printf("Cancelling...\n");
        return;
    }

    // Adding student to DB and final suite of tests before adding student to DB.
    printf("Adding new student to DB...\n");
    addNewEntryToDB(newStudent);
    printf("New student added to DB.\n");
}

// Gets the index number from DB entry.
int getIndNum(const char *buffer)
{
    char index_number[INPUT_BUFFER_LENGHT];
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

    /*  Converting string to int.
        This has the potential to fail if the characters before the first "," are not numbers.
        However errorchecks in other functions should prevent any incorrectly formatted DB entries.*/
    return strtol(index_number, NULL, 10); // I'm going to assume that this DB is never going to have more than 999 999 999 entries so a len of 10 is fine.
}

void editStudentEntry()
{
    // Asking for ind of student to edit.
    char userinput[INPUT_BUFFER_LENGHT] = "\0";
    int studentind = 0;

    char promptMsg[LONG_STRING_LENGHT] = "\nEnter student index number (Leftmost column in DB).\n";
    char errorMsg[LONG_STRING_LENGHT] = "Please enter a valid student index number.\n";

    printf("%s", SEPARATOR);
    do
    {
        fgetsStringWhileLoopAlphanumerical(promptMsg, errorMsg, userinput, DEFAULT_STRING_LENGHT);
        if (strcmp(userinput, "exit") == 0)
        {
            printf("Cancelling...\n");
            return;
        }
    } while (stringToIntConv(userinput, &studentind) == false);

    // Fetching current student data into struct.
    struct Student student = fetch_student_data(studentind);
    if (student.fetchFailure == 1)
    {
        printf("Failed to read DB.\n"
               "Cancelling...\n");
        return;
    }

    // Confirming what information to edit.
    printf("%s", SEPARATOR);
    char promptMsg2[LONG_STRING_LENGHT] = "\n1. Firstname\n2. Lastname\n3. major\nChoose data to change.\n";
    char errorMsg2[LONG_STRING_LENGHT] = "Enter a valid integer between range 1-4.\n";
    int choice = 0;
    bool input_valid = false;
    while (input_valid == false)
    {
        fgetsStringWhileLoopAlphanumerical(promptMsg2, errorMsg2, userinput, DEFAULT_STRING_LENGHT);
        if (strcmp(userinput, "exit") == 0)
        {
            printf("Cancelling...\n");
            return;
        }
        input_valid = stringToIntConv(userinput, &choice);
        if (choice < 1 || choice > 3)
        {
            printf("Error: Enter a valid integer between range 1-4.\n");
            input_valid = false;
        }
    }

    printf("%s", SEPARATOR);
    char inputstr[INPUT_BUFFER_LENGHT] = "\0";
    input_valid = false;
    switch (choice)
    {
        // Changing firstname.
    case 1:
        sprintf(inputstr, "Enter firstname (max %d alphanumerical characters only!)\n", NAME_LENGHT - 1);
        fgetsStringWhileLoopAlphanumerical(inputstr, "Please enter a valid firstname.\n", student.firstname, NAME_LENGHT);
        if (exit_to_cancel(userinput) == true)
        {
            printf("Cancelling...\n");
            return;
        }
        break;

        for (int i = 0; i < strlen(userinput); i++)
        {
            student.firstname[i] = userinput[i];
        }

        // Changing lastname.
    case 2:
        sprintf(inputstr, "Enter lastname (max %d alphanumerical characters only!)\n", NAME_LENGHT - 1);
        fgetsStringWhileLoopAlphanumerical(inputstr, "Please enter a valid lastname.\n", student.lastname, NAME_LENGHT);
        if (exit_to_cancel(userinput) == true)
        {
            printf("Cancelling...\n");
            return;
        }
        break;

        for (int i = 0; i < strlen(userinput); i++)
        {
            student.lastname[i] = userinput[i];
        }

        // Swapping major.
    case 3:
        char majors[NUM_MAJORS][LONG_STRING_LENGHT] = MAJORS;

        printf("Current major: %s\n", student.major);
        printf("Choose new major\n");
        for (int i = 0; i < NUM_MAJORS; i++)
        {
            printf("%d. %s\n", i + 1, majors[i]);
        }

        sprintf(inputstr, "Enter a number between 1 and %d.\n", NUM_MAJORS);
        char errorMsg3[LONG_STRING_LENGHT] = "\0";
        sprintf(errorMsg3, "Please enter a valid integer between range 1-%d.\n", NUM_MAJORS);
        fgetsStringWhileLoopAlphanumerical(inputstr, errorMsg3, userinput, DEFAULT_STRING_LENGHT);
        if (exit_to_cancel(userinput) == true)
        {
            printf("Cancelling...\n");
            return;
        }

        int userinput_int = 0;
        while (input_valid == false)
        {
            stringToIntConv(userinput, &userinput_int);
            if (userinput_int >= 1 && userinput_int <= NUM_MAJORS)
            {
                input_valid = true;
            }
        }
        strcpy(student.major, majors[userinput_int - 1]);

        break;
    }

    // Confirming student record.
    printf("%s", SEPARATOR);
    printf("Student record will be modified with following information\n"
           "Firstname: %s\n"
           "Lastname: %s\n"
           "Studentid: %s\n"
           "Major: %s\n",
           student.firstname, student.lastname, student.studentid, student.major);
    userinput[0] = '\0';
    printf("Is this correct? [yes/no]\n");
    printf("Input: ");
    improvedFgets(userinput, DEFAULT_STRING_LENGHT);
    convertToLowercase(userinput);
    while (stringIsYesOrNo(userinput) == false)
    {
        {
            printf("Error: Please enter \"yes\" or \"no\".\n");
            printf("Input: ");
            improvedFgets(userinput, DEFAULT_STRING_LENGHT);
            convertToLowercase(userinput);
        }
        if (stricmp(userinput, "no") == 0 || stricmp(userinput, "n") == 0)
        {
            printf("Cancelling...\n");
            return;
        }
    }

    // Modifying student entry in DB.
    printf("Modifying student entry in DB...\n");
    if (modifyEntryToDB(student) == false)
    {
        printf("Error: Failed to modify entry with studentind \"%d\".\n", studentind);
        printf("Exiting...\n");
        return;
    }
    printf("Student entry modified.\n");

    return;
}

void deleteStudentEntry()
{
    // Gathering information on entry to remove.
    printf("%s", SEPARATOR);
    char userinput[INPUT_BUFFER_LENGHT] = "\0";
    bool entry_found = false;
    int studentind = 0;

    while (entry_found == false)
    {
        fgetsStringWhileLoopAlphanumerical("Enter index number of student entry to remove. (Leftmost column in DB).\n",
                                           "Please enter a valid student index number.\n", userinput, DEFAULT_STRING_LENGHT);
        if (exit_to_cancel(userinput) == true)
        {
            printf("Cancelling...\n");
            return;
        }

        entry_found = stringToIntConv(userinput, &studentind);
    }

    struct Student student = fetch_student_data(studentind); // student.db_entry_row is used to locate entry in DB.
    if (student.fetchFailure == 1)
    {
        printf("Failed to read DB.\n"
               "Cancelling...\n");
        return;
    }

    FILE *pFile = openFileWithRetry(DB, "r", 3);
    if (pFile == NULL)
    {
        printf("Error: Unable to open the file '%s'\n", DB);
        return;
    }

    FILE *tmpFile = openFileWithRetry(TEMP, "w", 3);
    if (tmpFile == NULL)
    {
        printf("Error: Unable to open the file '%s'\n", TEMP);
        return;
    }

    // Copying existing data to temp file without copying entry to remove and updating  DB row count.
    int current_index = 0, db_rows = 0;
    fscanf(pFile, "%d %d", &current_index, &db_rows);
    fprintf(tmpFile, "%d %d", current_index, db_rows - 1);

    entry_found = false;
    char buffer[LONG_STRING_LENGHT] = "\0";
    while (fgets(buffer, LONG_STRING_LENGHT, pFile) != NULL)
    {
        if (getIndNum(buffer) != studentind)
        {
            fprintf(tmpFile, "%s", buffer);
        }
        if (getIndNum(buffer) == studentind)
        {
            entry_found = true;
        }
    }

    if (entry_found == false)
    {
        printf("Error: Student record with index %d not found.\n", studentind);
        printf("Cancelling...\n");

        fclose(pFile);
        fclose(tmpFile);
        remove(TEMP);
        return;
    }

    fclose(pFile);
    fclose(tmpFile);

    // Updating database.
    remove(DB);
    rename(TEMP, DB);
    printf("Student entry removed.\n");

    return;
}

/*  Attempts to open specified file.
    Returns NULL incase of failure
    returns pointer to file otherwise.  */
FILE *openFileWithRetry(const char *fileName, const char *mode, const int maxRetries)
{
    FILE *file = NULL;
    int retryCount = 0;

    while (retryCount < maxRetries)
    {
        file = fopen(fileName, mode);
        if (file != NULL)
        {
            return file;
        }

        retryCount++;
    }

    printf("Error: Unable to open the file \"%s\".\n", fileName);
    return NULL;
}

void lookupOrBrowse()
{
    char userinput[INPUT_BUFFER_LENGHT] = "\0";
    int userinput_int = 0;
    bool input_valid = false;

    printf("%s", SEPARATOR);
    while (input_valid == false)
    {
        fgetsStringWhileLoopAlphanumerical("1. Lookup student\n2. Browse students\nChoose an option.\n",
                                           "Enter a valid integer between range 1-2.\n",
                                           userinput, DEFAULT_STRING_LENGHT);
        if (exit_to_cancel(userinput) == true)
        {
            printf("Cancelling...\n");
            return;
        }

        stringToIntConv(userinput, &userinput_int);
        if (userinput_int >= 1 && userinput_int <= 2)
        {
            input_valid = true;
        }
    }

    switch (userinput_int)
    {
    case 1:
        lookupStudent();
        break;
    case 2:
        browseStudentList();
        break;
    }

    return;
}

void browseStudentList()
{
    char userinput[INPUT_BUFFER_LENGHT] = "\0";
    int numOfRowsToPrint = 0;
    bool input_valid = false;

    printf("%s", SEPARATOR);
    do
    {
        // Getting user input
        fgetsStringWhileLoopAlphanumerical("\nHow many rows to show at a time?\nEnter an integer.\n",
                                           "Enter a valid integer.\n",
                                           userinput, DEFAULT_STRING_LENGHT);

        // Checking if user wants to cancel.
        if (exit_to_cancel(userinput) == true)
        {
            printf("Cancelling...\n");
            return;
        }

        // Checking for input validity.
        input_valid = stringToIntConv(userinput, &numOfRowsToPrint);
        if (input_valid == false)
        {
            printf("Error: Enter a valid integer.\n");
        }
    } while (input_valid == false);

    // Opening DB.
    FILE *pFile = openFileWithRetry(DB, "r", 3);
    if (pFile == NULL)
    {
        printf("Error: Unable to open the file '%s'\n", DB);
        return;
    }

    // Fetching number of rows in DB.
    int studentind = 0, DBrows = 0;
    fscanf(pFile, "%d %d", &studentind, &DBrows);

    // Storing column names from DB and skipping them.
    char columnNames[LONG_STRING_LENGHT] = "\0";
    fgets(columnNames, LONG_STRING_LENGHT, pFile);
    fgets(columnNames, LONG_STRING_LENGHT, pFile);

    int rowCount = 1;
    char buffer[LONG_STRING_LENGHT] = "\0";
    userinput[0] = '\0';
    while (rowCount <= DBrows)
    {
        printf("%s", SEPARATOR);
        printf("Entries %d - %d of %d\n", rowCount, rowCount + numOfRowsToPrint - 1, DBrows);
        printf("Studentind, Firstname, Lastname, Studentid, Major\n");

        for (int i = 0; i < numOfRowsToPrint; i++)
        {
            fgets(buffer, LONG_STRING_LENGHT, pFile);
            printf("%s", buffer);
            rowCount++;
            if (rowCount == DBrows + 1)
            {
                break;
            }
        }

        // Prompting user to continue or exit.
        printf("Continue? [yes/no]\nInput: ");
        improvedFgets(userinput, DEFAULT_STRING_LENGHT);
        convertToLowercase(userinput);
        while (stringIsYesOrNo(userinput) == false)
        {
            printf("Error: Please enter \"yes\" or \"no\".\nInput: ");
            improvedFgets(userinput, DEFAULT_STRING_LENGHT);
            convertToLowercase(userinput);
        }
        if (stricmp(userinput, "no") == 0 || stricmp(userinput, "n") == 0)
        {
            printf("Cancelling...\n");
            return;
        }
    }
}

void lookupStudent()
{
    char userinput[INPUT_BUFFER_LENGHT] = "\0";
    int studentind = 0;
    bool input_valid = false;

    printf("%s", SEPARATOR);
    while (input_valid == false)
    {
        fgetsStringWhileLoopAlphanumerical("Enter student index number (Leftmost column in DB).\n",
                                           "Please enter a valid student index number.\n", userinput, DEFAULT_STRING_LENGHT);
        if (exit_to_cancel(userinput) == true)
        {
            printf("Cancelling...\n");
            return;
        }

        input_valid = stringToIntConv(userinput, &studentind);
    }

    struct Student student = fetch_student_data(studentind);
    if (student.fetchFailure == 1)
    {
        printf("Failed to read DB.\n"
               "Cancelling...\n");
        return;
    }

    printf("%s", SEPARATOR);
    printf("Student information\n"
           "Firstname: %s\n"
           "Lastname: %s\n"
           "Studentid: %s\n"
           "Major: %s\n",
           student.firstname, student.lastname, student.studentid, student.major);

    return;
}

// Tests if string is "yes" or "no" or "y" or "n".
bool stringIsYesOrNo(const char *str)
{
    if (stricmp(str, "yes") == 0 || stricmp(str, "no") == 0 || stricmp(str, "y") == 0 || stricmp(str, "n") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}