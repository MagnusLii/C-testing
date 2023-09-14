#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <ctype.h>

bool stringToIntConv(const char *str, int *result);
int getIndNum(const char *buffer);

int main()
{
    char buffer[256] = "36, Avery, Phillips, 202307000036, PuppetArts";
    int num = getIndNum(buffer);
    printf("%d\n", num);

    return 0;
}


int getIndNum(const char *buffer)
{
    char index_number[8];
    int numberlength = 0;
    for (int i = 0; i < strlen(buffer); i++)
    {
        if (buffer[i] == ',')
        {
            break;
        }
        index_number[numberlength] = buffer[i];
        numberlength++;
    }
    
    int converted_number = 0;
    stringToIntConv(index_number, &converted_number);

    return converted_number;
}

bool stringToIntConv(const char *str, int *result)
{
    char *endptr;
    errno = 0;
    long int num = strtol(str, &endptr, 10);

    if (errno == ERANGE)
    {
        printf("Error: could not complete conversion to integer, number out of range.\n"
               "Enter a number between %d and %d.\n",
               LONG_MIN, LONG_MAX);
        return false;
    }
    else if (*endptr != '\0')
    {

        for (char *p = endptr; *p != '\0'; p++)
        {
            if (!isdigit((unsigned char)*p))
            {
                printf("Error: could not complete conversion to integer, you entered a non integer.\n");
                return false;
            }
        }
        printf("Error: could not read an integer.\n");
        return false;
    }

    *result = num;
    return true;
}