#include <stdio.h>
#include <string.h>

int main(){
    // To accept user input for c in visualstudio go to file> prefrences> settings> in search bar search for "code runner" and tick "run in terminal".

    // Useful guide to userinput pitfalls with scanf() and fgets(): http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html

    int age;
    char name[25];  // The number is the max size of array, going over this will cause a buffer overflow.

    printf("How old are you?: ");
    scanf("%d", &age);  // 'scanf' takes user input from terminal, in order to accept input define the format specifier '%d' and the variable 'age',
                        // the variable needs to be preceded by the & symbol.
    
    fgets(name, 25, stdin);  // This is here because the previous 'scanf()' function leaves a '\n' in the buffer which is immidiately read by any following
                             // 'fgets()' functions. Thus resulting in an empty variable. This 'fgets()' will read the '\n' from the buffer and get rid of it
                             // allowing us to accept user input in with the next 'fgets()'. This is a simply workaround.

    printf("What is your full name?: ");
    fgets(name, 25, stdin);  // 'fgets' works basically like 'scanf' however it can read whitespaces (spacebar) unlike 'scanf'.
                             // The arguments are name of the variable, input size, and stdin aka standard input.
                             // 'fgets' function includes a newline character at the end.

    name[strlen(name)-1] = '\0';  // This is string editing to replace the newline character from our string.
                                  // We first select the last character in the string with 'strlen(name)-1' aka the newline char.
                                  // Then we replace it with '\0' aka a null character.


    printf("Your name is %s.\n", name);
    printf("You are %d years old.", age);
    
    return 0;
}