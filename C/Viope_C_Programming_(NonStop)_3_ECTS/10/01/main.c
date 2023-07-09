#include <stdio.h>

int main()
{
    char firstname[255], secondname[255], filename[255];
    printf("The program saves your first and last name into a file.\n"
            "Enter your first name:");
    scanf("%s", &firstname);
    printf("Enter your last name:");
    scanf("%s", &secondname);
    printf("File where you want to save your name:");
    scanf("%s", &filename);
    
    FILE *pFile = fopen(filename, "w");
    fprintf(pFile, "%s %s", firstname, secondname);
    fclose(pFile);

    printf("Successfully saved the data!");
    return 0;
}