#include <stdio.h>

int main(){
    int userinput1, userinput2;
    printf("Enter the first number:");
    scanf("%d", &userinput1);
    printf("Enter the second number:");
    scanf("%d", &userinput2);

    printf("%d+%d=%d", userinput1, userinput2, userinput1 + userinput2);
    printf("%d-%d=%d", userinput1, userinput2, userinput1 - userinput2);
    printf("%d*%d=%d", userinput1, userinput2, userinput1 * userinput2);


    return 0;
}