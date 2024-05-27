// Code compiler setup instructions: https://code.visualstudio.com/docs/cpp/config-mingw

#include <iostream>  // header file that includes input and output operations.


int main(){

    // Basic print command.
    std::cout << "Hello ";  // std == standard, c == character, out == output, "<<" == output, also work as leftshift operator when used with numbers.
    std::cout << "World!";  // There's no automatic linebreak.

    std::cout << "\n";  // \n = newline char.
    std::cout << "Hello" << std::endl;  // endl == endline (linebreak), slower than \n but endline flushes the output buffer.
    std::cout << "World!";

    return 0;
}