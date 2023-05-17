#include <stdio.h>
#include <math.h>  // Includes a lot of useful math related functions.

int main(){



    double A = sqrt(9);  // Square root of 9
    double B = pow(2, 4);  // 2 to the power of 4, 2^4
    int C = round(3.14);  // Rounds to nearest int
    int D = ceil(3.14);  // Rounds up
    int E = floor(3.99);  // Rounds down
    double F = fabs(-100);  // Gives absolute value. Aka how far a number is from 0
    double G = log(3);  // Log of 3
    double H = sin(45);  // Sin of 45 (degrees not radians)
    double I = cos(45);
    double J = tan(45);

    printf("\n%.0lf", A);
    printf("\n%.0lf", B);
    printf("\n%d", C);
    printf("\n%d", D);
    printf("\n%d",E);
    printf("\n%lf", F);
    printf("\n%lf", G);
    printf("\n%lf", H);
    printf("\n%lf", I);
    printf("\n%lf", J);



    return 0;

}