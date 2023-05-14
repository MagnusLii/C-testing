#include <stdio.h>



int main(){

    // arithmetic operators

    // + (addition)
    // - (subtraction)
    // * (multiplication)
    // / (division)
    // % (modulus)  Remainder of division.
    // ++ increment
    // -- decrement


    int x = 5;
    int y = 2;


    int a = x + y;
    int b = x - y;
    int c = x * y;
    int d2 = x / y;  // 5 / 2 = 2 because we are storing the result in an int thus cutting off the decimal portion.
    float d = (float) x / y;  // Division by only intigers will always result in the decimal portion being cut off even if sotored in a float or other datatype with decimal values.
                              // Converting either the dividend or divisor to a float/double will fix this problem.
    int e = x % y;
    x++;
    y--;

    printf("x + y = %d\n", a);
    printf("x - y = %d\n", b);
    printf("x * y = %d\n", c);
    printf("x / y = %d\n", d2);
    printf("(float) x / y = %.1f\n", d);
    printf("x %% y = %d\n", e);
    printf("x++ = %d\n", x);
    printf("y-- = %d\n", y);


    return 0;

}