#include <stdio.h>  // The system will find the file named "stdio.h" and read its entire contents in, replacing this statement.
                    // This particular file is composed of several standard #defines to define some of the standard I/O operations. 
                    // It's called an header file.


// Anything within here is the main program.
int main(){
    printf("Hello World!");
    printf("Followup line.");  // There's no newline by default.

    printf("\nHello World!\n");
    printf("Followup line.");

    return 0; // returns exit status of program, 0 if no errors occur. Only an errorchecking measure.
}