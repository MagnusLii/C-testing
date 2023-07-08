#include <stdio.h>

int main(){

    int userinput;
    printf("Enter an integer: ");
    scanf("%d", &userinput);

    if (userinput % 2 == 0)
    {
        printf("Number %d is even.", userinput);
    }

    else
    {
        printf("Number %d is odd.", userinput);
    }

    return 0;
}