#include <stdio.h>

int main(){

    int userinput;

    printf("Enter an integer: ");
    scanf("%d", &userinput);

    //userinput = userinput * userinput;

    printf("The square of the number you entered is %d\n", userinput * userinput);

    return 0;
}