int *address_of_smallest_value(int *numbers, int size){
    int lowest;
    for (int i = 0; i < size; i++)
    {
        if (numbers[i] < numbers[lowest])
        {
            lowest = i;
        }
        
    }
    int *smallest = &numbers[lowest];
    return smallest;
}