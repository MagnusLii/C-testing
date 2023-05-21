#include <stdio.h>

// continue = skips rest of code and forces the next iteration of the loop.
// break = exit the loop/switch entirely.

int main(){

    for(int i = 1; i <= 100; i++)
    {
        if (i == 13)
        {
            continue;  // if 'i' == 13 skip printing it.
        }
        else if (i == 69)
        {
            break;  // break out of loop if 'i' == 69.
        }
        printf("%d\n", i);
    }

    return 0;
}