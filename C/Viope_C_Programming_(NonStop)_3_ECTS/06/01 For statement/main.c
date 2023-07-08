#include <stdio.h>

int main()
{
    int userinput;
    printf("Enter an integer: ");
    scanf("%d", &userinput);
    
    for (int i = 1; i <= userinput; i++)
    {
        printf("%d\n", i);
    }
    

    return 0;
}