#include <stdio.h>

int main(){
    // switch = A more efficient alternative to using many 'else if' statements
    //          allows a value to be tested for equality against many cases.

    char grade[1];

    printf("Enter a letter grade: ");
    fgets(grade, 2, stdin);

    switch (grade[0]) // 'grade[0]' so the switch only checks the first character of the array.
    {
    case 'A':  // if 'grade' == 'A'.
        printf("Perfect.");
        break;  // breaks are a must to exit out of the switch, otherwise the switch will loop through all the options.
    case 'B':
        printf("You did good.");
        break;
    case 'C':
        printf("You did ok.");
        break;
    case 'D':
        printf("Not an F.");
        break;
    case 'F':
        printf("You failed.");
        break;
    
    default:  // default is the equivalent of an 'else' statement, it'll execute if none of the other conditions are met.
        printf("Please enter only valid grades");
        break;
    }
}