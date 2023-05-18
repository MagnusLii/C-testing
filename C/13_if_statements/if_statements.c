#include <stdio.h>

int main(){
    char input[10];
    
    printf("Enter your age: ");
    fgets(input, sizeof(input), stdin);
    int age = atoi(input);  // Convert char to int.

    if (age >= 18)
    {
        printf("You are now signed up!");
    }
    else if(age < 0)
    {
        printf("You haven't been born yet.");
    }
    
    else
    {
        printf("You are too young to sign up.");
    }


    return 0;
}