#include <stdio.h>


int main()
{
    int matrixA[10][10], matrixB[10][10], summatrix[10][10];

    FILE *pFile = fopen("mata.txt", "r");
    FILE *bFile = fopen("matb.txt", "r");
    FILE *wFile = fopen("sum.usr", "w");

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
    {
        fscanf(pFile, "%d ", &matrixA[i][j]);
        fscanf(bFile, "%d ", &matrixB[i][j]);
        fprintf(wFile, "%d ", matrixA[i][j] + matrixB[i][j]);
    }
    if (i != 9)
    {
        fprintf(wFile,"\n");
    }
    }
    

    fclose(pFile);
    fclose(bFile);
    fclose(wFile);

    printf("The sum of the matrices has been calculated into the file sum.usr.");

    return 0; 
}