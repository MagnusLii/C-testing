#include <iostream>

// Type conversion =    conversion of a value of one data type to another.
//                      Implicit conversion = performed automatically by the compiler.
//                      Explicit conversion = performed by the programmer (int).

int main(){

    double x = 7.14;
    std::cout << x << std::endl;

    // implicit conversion
    int y = x;
    std::cout << y << std::endl;

    // explicit conversion
    int z = (int)x;
    std::cout << z << std::endl;

}