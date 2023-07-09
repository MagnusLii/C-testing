#include <stdio.h>


int main()
{
    int num[5], sum;
    FILE *pFile = fopen("numbers.s", "r");
    fscanf(pFile, "%d %d %d %d", &num[0], &num[1], &num[2], &num[3]);
    for (int i = 0; i < 4; i++)
    {
        sum += num[i];
    }
    
    printf("Numbers found in the file numbers.s:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d", num[i]);
        if (i < 2) {
            printf(", ");
        }
        else
        {
            printf(" and %d", num[3]);
        }
    }

    printf("\nSum of the numbers: %d", sum);

    return 0; 
}