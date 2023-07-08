#include <stdio.h>

int main()
{
    int userinput;
    int sum = 1;
    printf("Enter an integer: ");
    scanf("%d", &userinput);

    for (int i = 1; i <= userinput; i++)
    {
        sum = sum * i;
    }

    printf("The factorial of %d is %d", userinput, sum);
    
    
    return 0;
}