#include <stdio.h>
#include <time.h>
#include <string.h>

void add_student(int *studentind, char **date_string);
void edit_student();

#define DB "db.txt"
#define TEMP "temp.tmp"

struct Student
{
    int studentind;
    char firstname[20], lastname[20], studentid[13], major[20];
};

typedef struct Student Struct;

Struct fetch_student_data(int studentind)
{
    Struct student;
    int tokencount = 0, linecount = 0;
    char *token, buffer[255];
    FILE *dbFile = fopen(DB, "r");

    while ((fgets(buffer, 255, dbFile)) != NULL)
    {
        linecount++;
        if (linecount == studentind + 2)
        {
            token = strtok(buffer, ", ");
            while (token != NULL)
            {
                switch (tokencount)
                {
                case 0:
                    student.studentind = atoi(token);
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
        }
    }
    fclose(dbFile);
    return student;
}

int main()
{
    int choice, studentind;
    char date_string[20], buffer[20];
    char *pDate_string = &date_string;
    int *pStudentind = &studentind;

start:

    printf("\n\n----------------------------------------\n\n"
           "Student record management system\n\n"
           "Menu:\n"
           "1. Add new student\n"
           "2. Edit student\n"
           "3. Delete student\n"
           "4. Search student\n"
           "5. Exit\n"
           "Enter your choice: ");

    scanf("%d", &choice);
    fgets(buffer, 20, stdin);

    switch (choice)
    {
    case 1:
        FILE *pFile = fopen(DB, "r");
        fscanf(pFile, "%d", &studentind);
        fclose(pFile);

        time_t current_time = time(NULL);
        strftime(date_string, 20, "%Y%m", localtime(&current_time));

        add_student(pStudentind, &pDate_string);
        fclose(pFile);
        goto start;
        break;

    case 2:
        edit_student();
        goto start;
        break;

    case 3:
        printf("Delete student\n");
        goto start;
        break;

    case 4:
        printf("Search student\n");
        goto start;
        break;

    case 5:
        printf("Exiting program\n");
        goto end;
        break;

    default:
        goto fail;
    }

fail:
    printf("Error");
    goto end;
end:
    return 0;
}

void add_student(int *studentind, char **date_string)
{

    int major;
    char firstname[20], lastname[20], buffer[255], student_number[7];
    char studentid[13] = "\0";
    char majors[4][20] = {"Biomimicry", "Puppet Arts", "Bicycle Design", "EcoGastronomy"};

    FILE *tmpFile = fopen(DB, "w");
    FILE *pFile = fopen(DB, "r");

    (*studentind)++;

    sprintf(student_number, "%06d", *studentind);

    // Gathering new student information.
    printf("\n\n----------------------------------------\n\n"
           "Creating new student\n");

    printf("Enter firstname: ");
    fgets(firstname, 20, stdin);
    firstname[strlen(firstname) - 1] = '\0';

    printf("Enter lastname: ");
    fgets(lastname, 20, stdin);
    lastname[strlen(lastname) - 1] = '\0';

choose_major:
    printf("\n\n----------------------------------------\n\n"
           "Set student major\n"
           "1. Biomimicry\n"
           "2. Puppet Arts\n"
           "3. Bicycle Design\n"
           "4. EcoGastronomy\n"
           "Enter choice: ");
    scanf("%d", &major);

    strcat(studentid, *date_string);
    strcat(studentid, student_number);

    // Filling temporary file to store updated data.
    int count = 0;
    while ((fgets(buffer, 255, pFile)) != NULL)
    {
        count++;
        if (count == 1)
            fprintf(tmpFile, "%d\n", *studentind);
        else
            fprintf(tmpFile, "%s", buffer);
    }

    // Creating new student entry.
    if (major > 0 && major < 5)
    {
        fprintf(tmpFile, "\n%d, %s, %s, %s, %s", *studentind, firstname, lastname, studentid, majors[major - 1]);
    }
    else
    {
        printf("Enter a valid choice\n");
        goto choose_major;
    }

    fclose(pFile);
    fclose(tmpFile);

    // Updating database.
    remove(DB);
    rename(DB, DB);

    printf("Data updated.");
}

void edit_student()
{
    int studentind, data_to_change, major;
    char firstname[20], lastname[20], buffer[255], studentid[13], current_major[20];
    char majors[4][20] = {"Biomimicry", "Puppet Arts", "BicycleDesign", "EcoGastronomy"};
    char *token;

    FILE *tmpFile = fopen(TEMP, "w");
    FILE *pFile = fopen(DB, "r");

    // Gathering current student information.
    printf("\n\n----------------------------------------\n\n"
           "Enter student index number: ");
    scanf("%d", &studentind);

    // Fetching student data is now done via struct.
    struct Student student_data = fetch_student_data(studentind);

choose_revision:
    printf("\n\n----------------------------------------\n\n"
           "1. Firstname\n"
           "2. Lastname\n"
           "3. major\n"
           "4. Exit\n"
           "Choose data to change: ");
    scanf("%d", &data_to_change);
    fgets(buffer, 255, stdin);

    switch (data_to_change)
    {
    case 1:
        printf("Enter new firstname: ");
        fgets(student_data.firstname, 20, stdin);
        student_data.firstname[strlen(student_data.firstname) - 1] = '\0';
        break;
    case 2:
        printf("Enter new lastname: ");
        fgets(student_data.lastname, 20, stdin);
        student_data.lastname[strlen(student_data.lastname) - 1] = '\0';
        break;
    case 3:
        printf(
            "\n\nSet student major\n"
            "1. Biomimicry\n"
            "2. Puppet Arts\n"
            "3. Bicycle Design\n"
            "4. EcoGastronomy\n"
            "Enter choice: ");
        scanf("%d", &major);
        if (major > 0 && major < 5)
        {
            strcpy(student_data.major, majors[major - 1]);
        }
        else
        {
            printf("Enter a valid choice\n");
            goto choose_revision;
        }
        break;
    case 4:
        goto exit;
        break;
    default:
        printf("Enter a valid choice\n");
        goto choose_revision;
    }

    // Filling temporary file to store updated data.
    int count = 0;
    while ((fgets(buffer, 255, pFile)) != NULL)
    {
        count++;
        if (count == studentind + 2)
        {
            fprintf(tmpFile, "%d, %s, %s, %s, %s", student_data.studentind, student_data.firstname, student_data.lastname, student_data.studentid, student_data.major);
        }
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

    printf("Data updated.");
exit:
}
