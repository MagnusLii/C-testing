#include <stdio.h>

int main(){

    int x;       // declaration.
    x = 123;     //initialization.
    int y = 321; // declaration + initialization.

    int age = 20;       // int.
    float gpa = 2.05;   // float.
    char grade = "C";   // single character.
    char name[] = "bruh";   // array of characters.

    // using variables in print statements.
    printf("You are %d years old.\n", age);  /*   To print variables a 'format specifier' is placed in the quote instead of the variable as a placeholder.
                                                The format specifier must match the type of data in the variable eg %d or %i for int data.
                                                
                                                List of format specifiers: https://www.tutorialspoint.com/format-specifiers-in-c
                                                
                                                Then the variable to be used is specified outside the quote after the comma.
                                           */
    
    printf("Hello %s\n", name);
    printf("Your grade is %c\n", grade);
    printf("Your gpa is %f\n", gpa);

    return 0;
}