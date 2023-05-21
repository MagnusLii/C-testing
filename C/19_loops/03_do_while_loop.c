#include <stdio.h>

    // while loop = checks a condition, THEN executes a block of code if condition is true
    // do while loop = always executes a block of code once, THEN checks a condition



int main(){

    int number = 0;
    int sum = 0;

    do{  // start of do while loop.

        printf("Enter a number above 0: ");
        scanf("%d", &number);

        if(number > 0)
        {
            sum += number;
        }

   }while(number > 0);  // condition check for loop continuation.

   

   printf("sum: %d", sum);


    return 0;
}