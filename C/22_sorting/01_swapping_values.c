#include <stdio.h>
#include <string.h>


int main(){
    char x = 'X';
    char y = 'Y';
    char temp;

    temp = x;
    x = y;
    y = temp;

    printf("x = %c\n", x);
    printf("y = %c\n\n", y);


    char x1[] = "water";
    char y1[] = "soda";
    char temp1[15];

    strcpy(temp1, x1);
    strcpy(x1, y1);  // copying produces problems if the 2nd string is shorter than the first one.
    strcpy(y1, temp1);

    printf("x = %s\n", x1);
    printf("y = %s\n\n", y1);


    char x2[15] = "water";
    char y2[15] = "soda";
    char temp2[15];

    strcpy(temp2, x2);
    strcpy(x2, y2);
    strcpy(y2, temp2);


    printf("x = %s\n", x2);
    printf("y = %s\n\n", y2);

    return 0; 
}
