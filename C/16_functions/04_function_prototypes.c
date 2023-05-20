#include <stdio.h>

// function prototype

// WHAT IS IT?
// Function declaration, w/o a body, before main()
// Ensures that calls to a function are made with the correct arguments

// IMPORTANT NOTES
// Many C compilers do not check for parameter matching
// Missing arguments will result in unexpected behavior
// A function prototype causes the compiler to flag an error if arguments are missing


void hello(char[], int);  // function prototype


int main(){

    char name[] = "asd";
    int age = 210;

    hello(name, age);

    hello2(name);  // This function still works despite not having all required arguments. However it has unintended results.


    return 0;
}


void hello(char name[], int age)
{
    printf("\n\nHello %s", name);
    printf("\nYou are %d years old", age);
}

void hello2(char name[], int age)
{
    printf("\n\nHello %s", name);
    printf("\nYou are %d years old", age);
}