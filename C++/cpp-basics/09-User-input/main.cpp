#include <iostream>

// cout << (insertion operator)
// cin >> (extraction operator)

int main(){

    std::string name;
    int age;

    std::cout << "Enter your age: ";
    std::cin >> age;                        // cin stops reading at the first whitespace and doesn't read the newline character
    std::cin.ignore(INT64_MAX, '\n');       // ignore any characters in the input buffer until we find a newline
    std::cin.ignore(INT64_MAX);             // Ignore everything until EOF.

    std::cout << "Enter your name: ";
    std::getline(std::cin, name); // getline reads the entire line. (">> std::ws" reads) 



    std::cout << "Hello " << name << std::endl;
    
    return 0;
}