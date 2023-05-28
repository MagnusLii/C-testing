#include <stdio.h>

    // memory = an array of bytes within RAM.
    // memory block = a single unit (byte) within memory, used to hold some value.
    // memory address = the address of where a memory block is located.

int main()
{

    double a = 'X';  // 'a' = the memory address, 'X' = memory block.
    float b = 'Y';
    char c = 'Z';

    printf("%d, bytes\n", sizeof(a));  // bitsize of the variable.
    printf("%d, bytes\n", sizeof(b));
    printf("%d, bytes\n", sizeof(c));

    printf("%p\n", &a);  // address of variable.
    printf("%p\n", &b);
    printf("%p\n", &c);


    return 0;
}