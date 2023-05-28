#include <stdio.h>


int main()
{

    FILE *pFile = fopen("poem.txt", "r");
    char buffer[255];  // a buffer for storing the data read, the data will be read line by line.

    if (pFile != NULL)
    {
        while (fgets(buffer, 255, pFile) != NULL)  // while fgets is not null.
        {
            printf("%s", buffer);
        }
    }

    fclose(pFile);

    return 0; 
}