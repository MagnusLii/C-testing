#include <stdio.h>
#include <math.h>

int main(){
    printf("Enter 1 to calculate circumference with diameter.\n"
            "Enter 2 to calculate circumference with radius.\n");
    
    char input[10];
    fgets(input, sizeof(input), stdin);
    int choice = atoi(input);  // converting string to int.
    //printf("%d\n", choice);  // troubleshooting.

    if (choice == 1)
    {
        printf("Enter the diameter of the circle in cm: ");
        fgets(input, sizeof(input), stdin);
        int diameter = atoi(input);
        double circumference = M_PI * diameter;

        printf("The circumference of the cirle is %.2lfcm", circumference);
    }
    
    else if (choice == 2)
    {
        printf("Enter the radius of the circle in cm: ");
        fgets(input, sizeof(input), stdin);
        int radius = atoi(input);
        double circumference = 2 * M_PI * radius;

        printf("The circumference of the cirle is %.2lfcm", circumference);
    } 
    
    else
    {
        printf("Please enter valid input.");
    }


    return 0;
}