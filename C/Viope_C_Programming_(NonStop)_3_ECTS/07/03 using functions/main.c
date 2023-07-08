#include <stdio.h>




int main()
{
    int userinput;
    int list[3];

    for (int i = 1; i <= 3; i++)
    {
        printf("Enter the %d. number:", i);
        scanf("%d", &userinput);
        list[i-1] = userinput;
    }

    printf("Among the numbers you entered,\n");
    largest(list);
    smallest(list);
    
    
    return 0;
}

void largest(int arr[]){
    int length = sizeof(arr)/sizeof(arr[0]);
    int max = arr[0];
    for (int i = 0; i <= length; i++) 
    {      
       if(arr[i] > max)    
           max = arr[i];    
    }  

    printf("the largest was %d", max);
}

void smallest(int arr[]){
    int length = sizeof(arr)/sizeof(arr[0]);
    int min = arr[0];

    for (int i = 0; i <= length; i++) 
    {      
       if(arr[i] < min)    
           min = arr[i];    
    }            
    printf(" and the smallest was %d.", min);
}