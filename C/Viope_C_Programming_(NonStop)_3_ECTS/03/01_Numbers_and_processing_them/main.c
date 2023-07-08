#include <stdio.h>

int main(){
    int intg;
    float dec;
    printf("Enter an integer: ");
    scanf("%d", &intg);
    printf("Enter a decimal number:");
    scanf("%f", &dec);

    printf("You entered the integer: %d", intg);
    printf("You entered the decimal number, rounded to two decimal places: %.2f", dec);
    return 0;
}