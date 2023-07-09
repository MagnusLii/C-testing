#include <stdio.h>

int main()
{
    int work_days;
    float hours[30];
    float sum;
    printf("The program calculates the total hours worked during\n"
            "a specific period and the average length of a day.\n"
            "How many days:");
    scanf("%d", &work_days);

    for (int i = 1; i <= work_days; i++)
    {
        printf("Enter the working hours for day %d:", i);
        scanf("%f", &hours[i - 1]);
        sum += hours[i - 1];
    }

    printf("\n\nTotal hours worked: %.1f\n", sum);
    printf("Average length of day: %.1f\n", sum / work_days);
    printf("Hours entered: ");

    for (int i = 0; i < work_days; i++)
    {
        printf("%.1f ", hours[i]);
    }

    
    return 0;
}