#include <stdio.h>
#include <time.h>
#include <string.h>

void add_student(int *studentind, char **date_string);
void edit_student();

int main()
{
    int choice, studentind;
    char date_string[20], buffer[20];
    char *pDate_string = &date_string;
    int *pStudentind = &studentind;

    FILE *pFile = fopen("db.txt", "r");
    fscanf(pFile, "%d", &studentind);
    fclose(pFile);

    time_t current_time = time(NULL);
    strftime(date_string, 20, "%Y%m", localtime(&current_time));

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
        add_student(pStudentind, &pDate_string);
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
    fclose(pFile);
    return 0;
}

void add_student(int *studentind, char **date_string)
{

    int major;
    char firstname[20], lastname[20], buffer[255], student_number[7];
    char studentid[30] = "\0";
    char majors[4][20] = {"Biomimicry", "Puppet Arts", "Bicycle Design", "EcoGastronomy"};

    FILE *tmpFile = fopen("temp.tmp", "w");
    FILE *pFile = fopen("db.txt", "r");

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
    remove("db.txt");
    rename("temp.tmp", "db.txt");

    printf("Data updated.");
}

void edit_student()
{
    int studentind, revisionInd, major;
    char firstname[20], lastname[20], buffer[255], studentid[13], current_major[20];
    char majors[4][20] = {"Biomimicry", "Puppet Arts", "BicycleDesign", "EcoGastronomy"};
    char *token;

    FILE *tmpFile = fopen("temp.tmp", "w");
    FILE *pFile = fopen("db.txt", "r");
    FILE *pFile2 = fopen("db.txt", "r");

    // Gathering current student information.
    printf("\n\n----------------------------------------\n\n"
           "Enter student index number: ");
    scanf("%d", &studentind);

    int tokencount = 0, linecount = 0;
    while ((fgets(buffer, 255, pFile2)) != NULL)
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
                    studentind = atoi(token);
                    break;
                case 1:
                    strncpy(firstname, token, sizeof(firstname) - 1);
                    firstname[sizeof(firstname) - 1] = '\0';
                    break;
                case 2:
                    strncpy(lastname, token, sizeof(lastname) - 1);
                    lastname[sizeof(lastname) - 1] = '\0';
                    break;
                case 3:
                    strncpy(studentid, token, sizeof(studentid) - 1);
                    studentid[sizeof(studentid) - 1] = '\0';
                    break;
                case 4:
                    strncpy(current_major, token, sizeof(current_major) - 1);
                    current_major[sizeof(current_major) - 1] = '\0';
                    break;
                }

                token = strtok(NULL, ", ");
                tokencount++;
            }
        }
    }

choose_revision:
    printf("\n\n----------------------------------------\n\n"
           "1. Firstname\n"
           "2. Lastname\n"
           "3. major\n"
           "4. Exit\n"
           "Choose data to change: ");
    scanf("%d", &revisionInd);
    fgets(buffer, 255, stdin);

    switch (revisionInd)
    {
    case 1:
        printf("Enter new firstname: ");
        fgets(firstname, 20, stdin);
        firstname[strlen(firstname) - 1] = '\0';
        break;
    case 2:
        printf("Enter new lastname: ");
        fgets(lastname, 20, stdin);
        lastname[strlen(lastname) - 1] = '\0';
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
            strcpy(current_major, majors[major - 1]);
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
            fprintf(tmpFile, "%d, %s, %s, %s, %s\n", studentind, firstname, lastname, studentid, current_major);
        }
        else
        {
            fprintf(tmpFile, "%s", buffer);
        }
    }

    fclose(pFile);
    fclose(tmpFile);
    fclose(pFile2);

    // Updating database.
    remove("db.txt");
    rename("temp.tmp", "db.txt");

    printf("Data updated.");
exit:
}

void tempname()
{
    
}