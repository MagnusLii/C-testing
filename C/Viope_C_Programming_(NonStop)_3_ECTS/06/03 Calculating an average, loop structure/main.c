#include <stdio.h>

int main()
{
    int userinput, numberof = 0, status = 1;
    float sum;
    printf("The program calculates the average of scores you enter.\n"
            "End with a negative integer.\n");
    while (status == 1)
    {
        printf("Enter score (4-10):");
        scanf("%d", &userinput);
        if (userinput != -1)
        {
            sum += userinput;
            numberof++;
        }
        else
        {
            status = 2;
        }
    }
    printf("You entered %d scores.\n", numberof);
    printf("Average score: %.2f\n", sum / numberof);
    
    return 0;
}