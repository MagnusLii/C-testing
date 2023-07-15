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
        goto start;
        break;

    case 2:
        printf("Edit student\n");
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
    char firstname[20], lastname[20], buffer[20], student_number[7];
    char studentid[30] = "\0";
    char majors[4][20] = {"Biomimicry", "Puppet Arts", "Bicycle Design", "EcoGastronomy"};
    
    FILE *tmpFile = fopen("temp.tmp", "w");
    FILE *pFile = fopen("db.txt", "r");

    (*studentind)++;
    
    sprintf(student_number, "%06d", *studentind);

    // Gathering new student information.
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

    // Creating temporary file to store data.
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
        fprintf(tmpFile, "\n%06d - %s %s %s %s", *studentind, firstname, lastname, studentid, majors[major - 1]);
    }
    else
    {
        printf("Enter a valid choice\n");
        goto choose_major;
    }

    fclose(pFile);
    fclose(tmpFile);

    remove("db.txt");
    rename("temp.tmp", "db.txt");

    printf("Data updated.");
}