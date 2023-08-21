#include <stdio.h>

int main(void)
{
    float salaries[12] = {}, taxedMoney[12] = {}, taxRate, incomeLimit, greaterTaxRate;

    printf("Enter tax rate: ");
    scanf("%f", &taxRate);

    printf("Enter income limit: ");
    scanf("%f", &incomeLimit);

    printf("Enter tax rate for income over the limit: ");
    scanf("%f", &greaterTaxRate);

    for (int i = 0; i < 12; i++)
    {
        printf("Enter income for month %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    printf("%4s %10s %10s\n", "month", "income", "tax");

    for (int i = 0; i < 12; i++)
    {
        if (salaries[i] > incomeLimit)
        {
            // Calculates combined tax for salaries under and over incomelimit.
            // taxedMoney = (SalaryUpToLimit * taxRate) + (SalaryOverLimit * greaterTaxRate)
            taxedMoney[i] = incomeLimit * (taxRate / 100) + (salaries[i] - incomeLimit) * (greaterTaxRate / 100);
        }
        else
        {
            taxedMoney[i] = salaries[i] * (taxRate / 100);
        }
        printf("%4d %10.2f %10.2f\n", i + 1, salaries[i], taxedMoney[i]);
    }

    return 0;
}