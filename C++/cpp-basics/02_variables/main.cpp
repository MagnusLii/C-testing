#include <iostream>


int main(){
    int x;  // Declaration.
    x = 5;  // Assignment.

    int y = 10;  // Declaration + assignment.

    int z = 3.7;  // When assigning a float to an int var the decimal points get trunkated.

    std::cout << x << "\n" << y;

    std::cout << "\n" << z;

    return 0;
}