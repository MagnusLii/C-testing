#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <ctype.h>

int main()
{
    char str[100] = "Hello World";

    sprintf(str, "%s", "test test");

    printf("%s\n", str);
    return 0;
}

void changeStudentAttribute(char *inputstr, char *attribute, int maxLength)
{
    sprintf(inputstr, "Enter firstname (max %d alphanumerical characters only!)\n", NAME_LENGHT - 1);
    fgetsStringWhileLoopAlphanumerical(inputstr, "Please enter a valid firstname.\n", userinput, NAME_LENGHT);
    if (exit_to_cancel(userinput) == true)
    {
        return;
    }
    for (int i = 0; i < strlen(userinput); i++)
    {
        student.attribute[i] = userinput[i];
    }
}