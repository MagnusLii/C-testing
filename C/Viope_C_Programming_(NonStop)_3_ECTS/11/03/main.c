#include <stdio.h>
#include <string.h>

int main()
{
    char firstname[50] = "", lastname[50] = "";
    printf("Enter first name:");
    fgets(firstname, 50, stdin);
    firstname[strlen(firstname)-1] = '\0';
    printf("Enter last name:");
    fgets(lastname, 50, stdin);
    lastname[strlen(lastname)-1] = '\0';
    printf("Data removed from the directory.");

    char name[100];
    strcpy(name, firstname);
    strcat(name, " ");
    strcat(name, lastname);

    char buffer[255];

    FILE *pFile = fopen("phonedir.txt", "r");
    int counter = 1;
    while ((fgets(buffer, 255, pFile)) != NULL)
    {
        if (counter != 1 && strncmp(buffer, name, strlen(name) != 0))
        {
                    //printf("%s \n", buffer); 
        }
        counter++;
    }

    return 0;
}