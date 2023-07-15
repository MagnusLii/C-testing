#include <stdio.h>
#include <time.h>
#include <string.h>


void add_student(int *studentind, char **date_string);

int main()
{
    int choice, studentind;
    char date_string[20], buffer[20];
    char* pDate_string = &date_string;
    int* pStudentind = &studentind;

    // read number of students from first line of file.
    FILE *pFile = fopen("db.txt", "r");
    fscanf(pFile, "%d", &studentind);
    fclose(pFile);

    time_t current_time = time(NULL);
    strftime(date_string, 20, "%Y%m", localtime(&current_time));

    start:

    printf("Student record management system\n\n"
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
        add_student(pStudentind, &pDate_string);
        break;

    case 2:
        printf("Edit student\n");
        break;

    case 3:
        printf("Delete student\n");
        break;

    case 4:
        printf("Search student\n");
        break;

    case 5:
        printf("Exit\n");
        goto end;
        break;

    default: goto fail;
    }

    fail:
        printf("Error");
        goto end;
    end:
        fclose(pFile);
        return 0;
}


void add_student(int *studentind, char **date_string)
{

    int major;
    char firstname[20], lastname[20], buffer[20];
    char studentid[30] = "\0";
    char majors[4][20] = {"Biomimicry", "Puppet Arts", "Bicycle Design", "EcoGastronomy"};
    
    FILE *pFile = fopen("db.txt", "a");

    char student_number[7];
    (*studentind)++;
    
    sprintf(student_number, "%06d", *studentind);

    printf("\n\nCreating new student\n");

    printf("Enter firstname: ");
    fgets(firstname, 20, stdin);
    firstname[strlen(firstname)-1] = '\0';
    
    printf("Enter lastname: ");
    fgets(lastname, 20, stdin);
    lastname[strlen(lastname)-1] = '\0';

    choose_major:
    printf("\n\nSet student major\n"
            "1. Biomimicry\n"
            "2. Puppet Arts\n"
            "3. Bicycle Design\n"
            "4. EcoGastronomy\n"
            "Enter choice: ");
    scanf("%d", &major);

    strcat(studentid, *date_string);
    strcat(studentid, student_number);


    switch (major)
    {
    case 1:
        fprintf(pFile, "\n%s %s %s %s", firstname, lastname, studentid, majors[major]);
        break;
    case 2:
        fprintf(pFile, "\n%s %s %s %s", firstname, lastname, studentid, majors[major]);
        break;
    case 3:
        fprintf(pFile, "\n%s %s %s %s", firstname, lastname, studentid, majors[major]);
        break;
    case 4:
        fprintf(pFile, "\n%s %s %s %s", firstname, lastname, studentid, majors[major]);
        break;
    
    default: 
        printf("Enter a valid choice\n");
        goto choose_major;
    }

    fclose(pFile);
    // TODO Update studentind to db file.
}