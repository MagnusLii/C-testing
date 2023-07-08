#include <stdio.h>

int main()
{
    int arithmetic_operation;
    int input1, input2;
    printf("1: subtraction\n"
            "2: addition\n"
            "3: multiplication\n"
            "Select function:");
    scanf("%d", &arithmetic_operation);
    printf("Enter the first number:");
    scanf("%d", &input1);
    printf("Enter the second number:");
    scanf("%d", &input2);

    if (arithmetic_operation == 1)
    {
        printf("%d-%d=%d", input1, input2, input1 - input2);
    }
    else if (arithmetic_operation == 2)
    {
        printf("%d+%d=%d", input1, input2, input1 + input2);
    }
    else if (arithmetic_operation == 3)
    {
        printf("%d*%d=%d", input1, input2, input1 * input2);
    }
    
    
    return 0;
}