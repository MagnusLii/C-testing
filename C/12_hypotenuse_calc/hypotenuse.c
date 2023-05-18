#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    char lenght[10];
    char *ptr;

    printf("Give lenght of \"short\" side in cm: ");
    fgets(lenght, sizeof(lenght), stdin);
    double short_side = strtod(lenght, &ptr);  // Convert char to double.

    printf("Give lenght of \"long\" side in cm: ");
    fgets(lenght, sizeof(lenght), stdin);
    double long_side = strtod(lenght, &ptr);

    double hypotenuse = sqrt(pow(long_side, 2) + pow(short_side, 2));
    printf("The hypotenuse is %.3lfcm long.", hypotenuse);

    return 0;
}