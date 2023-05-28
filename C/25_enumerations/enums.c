#include <stdio.h>

// enums = a user defined type of named integer identifiers, helps to make a program more readable.

enum Day{Mon = 1, Tue, Wed, Thu, Fri, Sat, Sun};  // Enums are constants, can be defined in or outside of main().
                                                  // By default enum id's start from 0, these can be defined by using '='.
                                                  // When assigning a value manually the following values will automcatically rise by 1.

int main(){

    enum Day today = Mon;

    printf("%d", today);  // enums are not strings, can be treated as int.

    if(today == Sun || today == Sat)  // alternative to if(today == 6 || today == 7)
    {
        printf("\nIt's the weekend! Party time!");
    }

    else
    {
        printf("\nI have to work today :(");
    }


    return 0;
}