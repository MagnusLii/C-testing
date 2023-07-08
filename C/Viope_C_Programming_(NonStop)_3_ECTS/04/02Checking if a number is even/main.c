#include <stdio.h>


int main(){
    int userinput;
    printf("Enter an integer: ");
    scanf("%d", &userinput);

    printf("The number is %d", userinput % 2);

    return 0;
}