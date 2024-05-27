#include <iostream>
#include <vector>

    // typedef = reserved keyword used to create an additional name for another data type.
    //           New identifier for an existing type.

    // typedef has been superseded by 'using' keyword as they work better with templates.


typedef std::vector<std::pair<std::string, int>> pairlist_t; // Creates typedef 'pairlist_t' for 'std::vector<std::pair<std::string, int>>'.
                                                             // typedef names end with '_t' by convention

using text_t = std::string; // Same as above but using 'using' keyword instead of 'typedef'.

int main(){


    std::vector<std::pair<std::string, int>> pairlist; // Instead of this.
    pairlist_t pairlist2; // We can use this.

    std::string firstname = "John"; 
    text_t lastname = "Smith";

    std::cout << firstname << " " << lastname << std::endl;

    return 0;
}