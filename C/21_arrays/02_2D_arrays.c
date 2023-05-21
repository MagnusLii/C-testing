#include <stdio.h>

    // 2D array = an array, where each element is an entire array


int main(){

    int numbers[][3] = {{1, 2, 3},  // A 2D array needs to have the maximum len of each array defined in the 2nd '[]' box,
                       {4, 5, 6}};  // defining the max number of arrays is optional.


    int numbers2[2][3];  // The first brackets represent rows, the second bracket columns,
                         // so this 2D array has a max of 2 rows and 3 columns.


    numbers[0][1] = 7;  // This changes the item in row 1 column 2 into a '7'.

    int rows = sizeof(numbers) / sizeof(numbers[0]);  // size of entire array / size of one of the rows == num of rows.
    int columns = sizeof(numbers[0]) / sizeof(numbers[0][1]);  // size of row 0 / size of any element in row 0 == num of columns.

    printf("%d\n", rows);
    printf("%d\n", columns);


    // printing all the items in the array.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}
