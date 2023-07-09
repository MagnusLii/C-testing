#include <stdio.h>

int main()
{
    char buffer[255];

    FILE *pFile = fopen("phonedir.txt", "r");
    int counter = 1;
    while ((fgets(buffer, 255, pFile)) != NULL)
    {
        if (counter != 1)
        {
                    printf("%s", buffer); 
        }
        counter++;
    }

    return 0;
}