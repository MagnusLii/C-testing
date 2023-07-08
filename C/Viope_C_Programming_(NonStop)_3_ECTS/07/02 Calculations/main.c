#include <stdio.h>

void sum(int, int);
void diff(int, int);
void product(int, int);

int main()
{
    int choice, input1, input2, status = 1;

    while (status == 1)
    {
        printf("1: sum of two numbers\n"
        "2: difference of two numbers\n"
        "3: product of two numbers\n"
        "<0: terminate the program\n"
        "Select calculation:");
        scanf("%d", &choice);
        if (choice == -1)
        {
            printf("Terminating the program...");
            break;
        }
        

        printf("Enter the first number:");
        scanf("%d", &input1);
        printf("Enter the second number:");
        scanf("%d", &input2);

        if (choice == 1)
        {
            sum(input1, input2);
        }
        else if (choice == 2)
        {
            diff(input1, input2);
        }
        else if (choice == 3)
        {
            product(input1, input2);
        }
        
    }
    
    
    return 0;
}

void sum(int1, int2){
    printf("%d + %d = %d", int1, int2, int1 + int2);
}
void diff(int1, int2){
    printf("%d - %d = %d", int1, int2, int1 - int2);
}
void product(int1, int2){
    printf("%d * %d = %d", int1, int2, int1 * int2);
}