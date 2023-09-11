#include <stdio.h>
#include <string.h>

int main()
{
    char input[10];
    printf("start");
    fgets(input, 9, stdin);
    if (strlen(input) - 1 != '\n')
    {
        printf("Error: could not complete conversion to integer\n");
        printf("strlen(input) - 1 = %c\n", input[strlen(input) - 1]);
        printf("%s", input);
    }
    
    
    return 0;
}