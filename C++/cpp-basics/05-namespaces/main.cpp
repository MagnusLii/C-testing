#include <iostream>

namespace first{
    int x = 1;
}

namespace second{
    int x = 2;
}


int main(){

    // Namespace =  A solution for preventing name conflicts.
    //              A namespace allows for identically named entities as 
    //              long as the namespaces are different.

    int x = 0;

    std::cout << x << std::endl; // If not specified, the local version of 'x' is used first.
    std::cout << first::x << std::endl; // 'x' from namespace 'first' is used.
    std::cout << second::x << std::endl;

    using namespace first; // Using the namespace 'first' for the rest of the file.
    std::cout << x << std::endl; // No need to specify the namespace anymore.

    // using namespace std; // Using this allows for not having to specify the namespace for std functions.
                            // However, since std has thousands of namespaces it is not recommended to use this.
                            // due to the likelyhood of name conflicts.
    
    using std::cout; // Using this allows for shortening the cout function without importing the entire std namespace.
                     // It's a much safer alternative to using namespace std.
    
    using std::endl; // These can be chained.
    cout << "Hello World!" << endl;


    return 0;
}