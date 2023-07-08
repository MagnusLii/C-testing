#include <stdio.h>

int main()
{
    char userdrink;
    int num_of_drinks;

    printf("Do you drink coffee or tea (c/t)?");
    scanf("%c", &userdrink);
    printf("How many cups do you drink daily:");
    scanf("%d", &num_of_drinks);

    if (userdrink == 'c')
    {
        if (num_of_drinks >= 0 && num_of_drinks <= 2)
        {
            printf("You don't drink a lot of coffee, do you?");
        }
        else if (num_of_drinks >= 3 && num_of_drinks <= 20)
        {
            printf("You drink a lot of coffee!");
        }
        
    }
    else if (userdrink == 't')
    {
        if (num_of_drinks >= 0 && num_of_drinks <= 2)
        {
            printf("You do not drink a lot of tea.");
        }
        else if (num_of_drinks >= 3 && num_of_drinks <= 20)
        {
            printf("You drink a lot of tea!");
        }
        
    }
    else
    {
        printf("An error occurred in the program!");
    }
    
    
    return 0;
}