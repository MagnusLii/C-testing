#include <stdio.h>

// ternary operator = shortcut to if/else when assigning/returning a value
// formula == (condition) ? value if true : value if false


int main()
{
    int max = findMax(3, 4);
    int max = ternaryFindMax(3, 4);

    printf("%d", max);

    return 0;
}

// findmax function with if statements.
int findMax(int x, int y){
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
    
}

// findmax function with ternary operator.
int ternaryFindMax(int x, int y)
{
    return (x > y) ? x : y;  // returns 'x' if x>y and 'y' if x<y.
}
