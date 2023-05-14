#include <stdio.h>

int main(){

    // format specifier % = defines and formats a type of data to be displayed.
    // https://www.tutorialspoint.com/format-specifiers-in-c

    // %c = character
    // %s = string (array of characters)
    // %f = float
    // %lf = double
    // %d / %i = integer

    // %.1 = decimal precision
    // %1 = minimum field width
    // %- = left align

    float item1 = 5.57;
    float item2 = 10.00;
    float item3 = 100.99;

    printf("item1: $%f\n", item1);
    printf("item1: $%.2f\n", item1);  // var limited to 2 decimal point accuracy.
    printf("item2: $%8.2f\n", item2);  // 8 min field lenght.
    printf("item3: $%-8.2f\n", item3);  // left aligned
}