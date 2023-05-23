#include <stdio.h>


void sort(int[], int);
void printArray(int[], int);


int main(){
    int array[] = {0, 3, 7, 1, 6, 2, 9};
    int size_of_array = sizeof(array) / sizeof(array[0]);  // total size of array (in bytes) / size of single item (bytes).

    sort(array, size_of_array);
    printArray(array, size_of_array);

    return 0;
}


void sort(int array[], int size){  // bubble sort algorithm.
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            
        }
        
    }
    
}


void printArray(int array[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    
}