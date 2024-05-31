#include <iostream>
#include <string>
#include <vector>

void getUserInput(std::string &userInputRefrence, const char* promptString);
bool sumNumbers(const std::string userinput);

int main(){

    std::string userinput;
    int sum = 0;
    int convertedInt = 0;
    bool continueLoop = true;

    do {
        getUserInput(userinput, "Enter a line with numbers or 'stop': ");
        continueLoop = sumNumbers(userinput);
    } while(continueLoop == true);
    std::cout << "Leaving already...? :(";

    return 0;
}

void getUserInput(std::string &userInputRefrence, const char* promptString){
    std::cout << promptString;
    std::getline(std::cin, userInputRefrence);
    return;
}

bool sumNumbers(const std::string userinput){
    int sum = 0;
    std::vector <int>spaces = {0};
    std::string substring;
    int numbers = 0;

    for (int i = 0; i < userinput.length(); i++){
        if (userinput[i] == ' '){
            spaces.push_back(i);
        }
    }
    spaces.push_back(userinput.length());

    if (userinput.substr(spaces[0], spaces[1]) == "stop"){
        return false;
    }

    for (int i = 0; i < spaces.size() -1; i++){
        try {
            substring = userinput.substr(spaces[i], (spaces[i+1] - spaces[i]));
            sum += std::stoi(substring);
            numbers++;
        }
        catch(...){
            std::cout << "Total of " << numbers << " numbers is " << sum << std::endl;
            return true;
        }
    }

    std::cout << "Total of " << numbers << " numbers is " << sum << std::endl;
    return true;
}