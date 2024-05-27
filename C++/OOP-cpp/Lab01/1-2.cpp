#include <string>
#include <iostream>

void charReplacer(std::string &string, const std::string charToReplace);

int main(){
    std::string userString;
    std::string charToReplace;

    std::cout << "Enter a string: ";
    getline(std::cin, userString);
    std::cout << "Enter character to replace or 'stop': ";
    getline(std::cin, charToReplace);

    while (charToReplace != "stop"){
        charReplacer(userString, charToReplace);
        std::cout << "Result: " << userString << std::endl << std::endl;
        std::cout << "Enter a string: ";
        getline(std::cin, userString);
        std::cout << "Enter character to replace or 'stop': ";
        getline(std::cin, charToReplace);
    }

    return 0;
}

void charReplacer(std::string &string, const std::string charToReplace){
    int charPosition;
    int lenOfReplacementString = charToReplace.length();

    std::string replacementString;
    for (int i = 0; i < lenOfReplacementString; i++){
        replacementString.append("_");
    }

    while ((charPosition = string.find(charToReplace)) != std::string::npos){
        string.replace(charPosition, lenOfReplacementString, replacementString);
    }
    return;
}