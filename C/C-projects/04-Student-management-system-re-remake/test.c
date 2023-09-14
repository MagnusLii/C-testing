#include <stdio.h>
#include <string.h>

#define STRING_LIST_SIZE 4  // Define the number of strings in the list

// Define the list of strings
#define STRING_LIST { \
    "String 1", \
    "String 2", \
    "String 3", \
    "String 4" \
}

// Calculate the number of strings in the list
#define NUM_STRINGS (sizeof(STRING_LIST) / sizeof(STRING_LIST[0]))


int main()
{
    printf("Number of strings: %d\n", NUM_STRINGS);

    return 0;
}