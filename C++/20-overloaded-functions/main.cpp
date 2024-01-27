#include <iostream>

void bakePizza();
void bakePizza(std::string topping1);
void bakePizza(std::string topping1, std::string topping2);
void bakePizza(std::string topping, int slices);


int main(){

    // The compiler will select the best fitting function based on the arguments provided.
    bakePizza();
    bakePizza("pepperoni");
    bakePizza("pepperoni", "mushroom");
    bakePizza("pepperoni", 8);

    return 0;
}


void bakePizza(){
    std::cout << "Here is your pizza!\n";
}
void bakePizza(std::string topping1){ // Functions can share a name as long as they have different parameters (number and type).
    std::cout << "Here is your " << topping1 << " pizza!\n";
}
void bakePizza(std::string topping, int slices){
    std::cout << "Here are your " << slices << " slices of " << topping << " pizza!\n";
} 
void bakePizza(std::string topping1, std::string topping2){
    std::cout << "Here is your " << topping1 << " and " << topping2 << " pizza!\n";
}