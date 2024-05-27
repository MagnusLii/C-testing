#include <iostream>

int main()

{
    // C++ oder of operations
    // 1. Parenthesis
    // 2. Exponents
    // 3. Multiplication and Division
    // 4. Addition and Subtraction

    int students = 20;

    // addition
    // ------------------
    students = students + 1;
    students += 1;
    students++;

    std::cout << students << std::endl;

    // subtraction
    // ------------------
    students = students - 1;
    students -= 1;
    students--;

    std::cout << students << std::endl;

    // multiplication
    // ------------------
    students = students * 2;
    students *= 2;

    std::cout << students << std::endl;

    // division
    // ------------------
    students = students / 2;
    students /= 2;

    std::cout << students << std::endl;

    // modulus
    // ------------------
    int remainder = students % 3;

    std::cout << remainder << std::endl;

    return 0;
}