#include <stdio.h>
#include <string.h>


int main()

{
    char cars[][10] = {"Mustang","Corvette","Camaro"};

    //cars[0] = "Tesla";  // An array of strings cannot be edited like this.

    strcpy(cars[0], "Tesla");  // We use strcpy() to copy a new string into the array.


    // printing the strings in the array.
    for(int i = 0; i < sizeof(cars)/sizeof(cars[0]); i++)
    {
        printf("%s\n", cars[i]);
    }

    return 0;
}
