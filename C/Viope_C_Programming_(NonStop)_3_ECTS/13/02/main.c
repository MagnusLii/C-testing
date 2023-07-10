#include <stdio.h> 
#include <stdlib.h>

void calculate_and_print(int *, int);

int main(int argc, char *argv[])
{
  int x, sum=0, size=5, array[5];
  if(argc == 6){ 
  /* Program name and command line parameters */
    for(x=0;x<argc-1;x++){
     array[x] = atoi(argv[x+1]);
    }
    calculate_and_print(array, size);
  }else{
    printf("Incorrect number of command line arguments\n");
  }
  return 0;
} 

void calculate_and_print(int *numbers, int size){
    int sum;
    printf("Elements of the array:");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", numbers[i]);
        sum += numbers[i];
    }

    printf("\nSum = %d", sum);
    
}