#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(0));  // using current time as seed for num generation. Without a seed the number generated will always be the same.

    int number1 = rand();  // generates a random number between 0-32767.
    int number2 = (rand() % 6) + 1;  // generates a random number between 1-6.

    printf("%d\n", number1);
    printf("%d\n", number2);

    return 0;
}