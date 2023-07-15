#include <stdio.h>
#include <time.h>

int main()
{
    int choice, major, studentind;
    char firstname[20], lastname[20], studentnumber[20], date_string[20];

    time_t current_time = time(NULL);
    strftime(date_string, 20, "%Y%m%d", localtime(&current_time));

    FILE *pFile = fopen("db.txt", "r");

    start:

    printf("Student record management system\n\n\n"
            "Menu:\n"
            "1. Add new student\n"
            "2. Edit student\n"
            "3. Delete student\n"
            "4. Search student\n"
            "5. Exit\n\n"
            "Enter your choice: ");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter firstname: ");
        fgets(firstname, 20, stdin);
        
        printf("Enter lastname: ");
        fgets(lastname, 20, stdin);

        printf("Set student major\n"
                "1. Biomimicry\n"
                "2. Puppet Arts\n"
                "3. Bicycle Design"
                "4. EcoGastronomy"
                "Enter choice: ");
        scanf("%d", major);

        strcat(string_1,string_2);
        studentnumber = 
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