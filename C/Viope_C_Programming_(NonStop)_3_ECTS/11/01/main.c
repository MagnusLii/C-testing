#include <stdio.h>
#include <stdlib.h>

int main()
{
    char firstname[255], lastname[255], phonenumber[255];
    int num_of_entries, max_entries = 50, max_len = 21;
    char buffer[255];
    int line = 1;

    
    FILE *pFile = fopen("phonedir.txt", "r");
    fscanf(pFile, "%d", &num_of_entries);
    fclose(pFile);

    if (num_of_entries >= max_entries)
    {
        printf("FULLL");
        return 1;
    }
    
    printf("Enter first name:");
    scanf("%s", &firstname);
    printf("Enter last name:");
    scanf("%s", &lastname);
    printf("Enter telephone number:");
    scanf("%s", &phonenumber);

    FILE *bFile = fopen("phonedir.txt", "a");
    fprintf(bFile, "\n%s %s %s", firstname, lastname, phonenumber);
    num_of_entries++;
    fclose(bFile);

    num_of_entries = 5;

    FILE *fPtr  = fopen("phonedir.txt", "r");
    FILE *fTemp = fopen("replace.tmp", "w");     

    int count = 0;
    while ((fgets(buffer, 255, fPtr)) != NULL)
    {
        count++;
        if (count == line)
            fprintf(fTemp, "%d\n", num_of_entries);
        else
            fprintf(fTemp, "%s", buffer);
    }

    fclose(fPtr);
    fclose(fTemp);

    remove("phonedir.txt");
    rename("replace.tmp", "phonedir.txt");

    printf("Successfully saved the data.");


    return 0;
}