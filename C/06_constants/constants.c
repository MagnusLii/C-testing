#include <stdio.h>

int main(){

    // constant = fixed value that cannot be altered by the program during its execution.

    float pi = 3.14159;
    const float PI = 3.14159;  // 'const' makes the value a constant. Constant names are traditionally in all caps.

    pi = 420.69;
    //PI = 420.69;  // this throws an error.

    printf("%f", pi);
    printf("%f", PI);

    return 0;
}