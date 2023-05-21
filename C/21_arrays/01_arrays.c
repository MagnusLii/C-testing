#include <stdio.h>

// array = a data structure that can store many balues of the **SAME** data type.

int main(){

    double prices[] /* '[]' make any variable an array. */ = {5.0, 10.0, 15, 251.73};  // array data is surrounded by '{}' and separated by a comma.
    double limited_prices[5] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // This array is limited to size 5, aka it can only hold 5 items max despite being initialized with 11 items.
    
    prices[4] = 300.0;  // appending a new item into index 4 of the 'prices' array.
    
    printf("limited price = %lf$\n\n", limited_prices[6]);  // Since the array is limited to 5 items there is no item '8' despite initializing the array with 10 items.
                                                            // Trying to access items past the array limit won't throw an error, but rather have unintended consequences.
                                                            // In this code after going past item 5 the code starts looping through the items in the 'price' array,
                                                            // aka 'limited_prices[6]' == 'prices[0]' == '5.0'.

    printf("price = %.2lf$", prices[4]);  // accessing item 4 in the array.
    return 0;
}
