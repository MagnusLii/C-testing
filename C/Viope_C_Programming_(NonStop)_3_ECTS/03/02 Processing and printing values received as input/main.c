#include <stdio.h>

int main(){
    
    float userinput;
    float conversionratio = 5.94573;

    printf("Enter an amount in FIM:");
    scanf("%f", &userinput);
    
    printf("FIM converted to euro: %.2f", userinput / conversionratio);
    return 0;
}