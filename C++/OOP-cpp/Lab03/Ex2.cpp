#include <iostream>
#include <deque>


class RunningAverage{
    public:

    RunningAverage(int numOfValues){
        assignedNumOfValues = numOfValues;
    }

    void add_value(int value){
        queue.push_front(value);
    }

    double get_average(){
        double average = 0;
        for (int i = 0; i < numToIterate(); i++){
            average += queue[i];
        }
        return average / assignedNumOfValues;
    }

    int numToIterate(){
        int size = queue.size();
        if (assignedNumOfValues > size) return queue.size();
        else return assignedNumOfValues;
    }

    private:
    int assignedNumOfValues;
    std::deque<int> queue;
};


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


int main(){
    int userInput = 0;
    bool stopProgram = false;
    
    getUserInput(userInput, "Enter number of values for running average: ");
    RunningAverage queue(userInput);

    while(stopProgram == false) {
        getUserInput(userInput, "Enter integer to add or '0' to calc average: ");
        if (userInput != 0) queue.add_value(userInput);
        else stopProgram = true;
    }

    std::cout << queue.get_average();

    return 0;
}