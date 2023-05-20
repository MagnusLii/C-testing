#include <stdio.h>
#include <string.h>

int main(){

    char name[25];

    printf("\nWhat's your name?: ");
    fgets(name, 25, stdin);
    name[strlen(name) - 1] = '\0';

    while(strlen(name) == 0)
    {
        printf("\nYou did not enter your name!");
        printf("\nWhat's your name?: ");
        fgets(name, 25, stdin);
        name[strlen(name) - 1] = '\0';  // removes newline from the end of the string.
    }

    printf("Hello %s", name);


    return 0;
}