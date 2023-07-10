#include <stdio.h>

int main()
{
    int x[10];

    change_number(*x);
    
    return 0;
}

void change_number(int *x[]){
    *x[0] += 3;
    printf("In the subroutine: x = %d", *x[0]);
}