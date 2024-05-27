#include <iostream>
#include <vector>

int main(){
    std::vector<int> numArray;
    int numOfNumbers = 0;
    int number = 0;

    std::cout << "How many numbers do you want enter?: ";
    std::cin >> numOfNumbers;

    for (int i = 0; i < numOfNumbers; i++){
        std::cout << "Enter nr[" << i << "]: ";
        std::cin >> number;
        numArray.push_back(number);
    }

    std::cout << "You entered: ";
    for (int i = 0; i < numOfNumbers; i++){
        std::cout << numArray[i];
        if (i < numOfNumbers - 1){
            std::cout << ", ";
        }
    }

    return 0;
}