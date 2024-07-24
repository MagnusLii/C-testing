#include <iostream>
#include <vector>
#include <map>

void getUserInput(std::string &userInputRefrence, const char* promptString);
void getUserInput(int &userInputRefrence, const char* promptString);


int main(){
    std::string nameInput;
    int numInput;
    bool quitProgram = false;
    std::map<std::string, int> dictionary;

    while (quitProgram == false){
        getUserInput(nameInput, "Enter name or 'stop' or 'print': ");
        if (nameInput == "stop"){
            quitProgram = true;
        }
        else if (nameInput == "print"){
                for (const auto& [key, value] : dictionary){
                    std::cout << key << " : " << value << std::endl;
                }
        }
        else {
            getUserInput(numInput, "Enter integer: ");
            dictionary[nameInput] = numInput;
        }
    }

    return 0;
}


void getUserInput(std::string &userInputRefrence, const char* promptString){
    std::cout << promptString;
    std::getline(std::cin, userInputRefrence);
    return;
}

void getUserInput(int &userInputRefrence, const char* promptString){
    std::cout << promptString;
    std::cin >> userInputRefrence;
    std::cin.ignore(INT64_MAX, '\n');   
    return;
}