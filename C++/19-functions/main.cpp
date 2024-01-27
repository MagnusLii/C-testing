#include <iostream>

void happyBirthday(std::string name, int age); // Function prototype

int main(){

    std::string name = "Asd";
    int age = 5;

    happyBirthday(name, age);

    return 0;
}

// Function definition.
void happyBirthday(std::string name, int age){ // Arguments require a type.
    std::cout << "Happy Birthday to " << name << '\n';
    std::cout << "Happy Birthday to " << name << '\n';
    std::cout << "Happy Birthday dear " << name << '\n';
    std::cout << "Happy Birthday to " << name << '\n';
    std::cout << "You are " << age << " years old!\n";
}