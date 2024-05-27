#include <iostream>

int main(){
    // const specifies that a variable's value cannot be changed
    // It tells the compiler to prevent the programmer from modifying the variable
    // effectively read-only.

    double pi = 3.14159;
    double radius = 5.0;

    pi = 3;

    double circumference = 2 * pi * radius;

    const double PI = 3.14159; // Const variable names conventionally start with a capital letter.
    const double Radius = 5.0;
    const double Circumference = 2 * PI * Radius;

    std::cout << "circumference is: " << circumference << "cm" << std::endl; 
    std::cout << "Circumference is: " << Circumference << "cm" << std::endl;

    return 0;
}