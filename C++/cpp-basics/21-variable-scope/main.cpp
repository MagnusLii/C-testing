#include <iostream>

int myNum2 = 3; //global
void printNum();


int main()
{
    int myNum = 1; //local
    printNum();
    std::cout << "main: " << myNum << '\n'; //local
    
    std::cout << ::myNum2 << '\n'; //global

    return 0;
}

void printNum(){
    int myNum = 2; //local
    std::cout << "printNum: "<< myNum << '\n'; //local
    std::cout << ::myNum2 << '\n'; //global
}