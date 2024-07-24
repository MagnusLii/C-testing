#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>

void getUserInput(std::string &userInputRefrence, const char* promptString);

int main(){
    std::vector <std::string>path;
    std::string userinput;
    std::filesystem::path filepath; // = std::filesystem::current_path();

    do {
        getUserInput(userinput, "Enter directory name: ");
        path.push_back(userinput);
    } while(userinput.length() != 0);

    for (int i = 0; i < path.size() - 1; i++){
        filepath /= path[i];
        std::filesystem::create_directory(filepath);
    }
    std::ofstream txtFile (filepath /= "result.txt");

    std::cout << "Absolutepath: " << std::filesystem::current_path() << filepath << std::endl;
    txtFile << "Absolutepath: " << std::filesystem::current_path() << filepath << std::endl;

    for (int i = 0; i < path.size() - 1; i++){
        std::cout << i <<": " << path[i] <<std::endl;
        txtFile << i <<": " << path[i] <<std::endl;
    }

    std::cout << "Relativepath: " << filepath << std::endl;
    txtFile << "Relativepath: " << filepath << std::endl;

    txtFile.close();

    return 0;
}

void getUserInput(std::string &userInputRefrence, const char* promptString){
    std::cout << promptString;
    std::getline(std::cin, userInputRefrence);
    return;
}