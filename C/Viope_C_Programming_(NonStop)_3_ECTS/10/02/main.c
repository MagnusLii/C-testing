#include <stdio.h>

int main()
{
    char word[255];
    char vowels[20] = {'a', 'e', 'i', 'o', 'u', 'y'};
    int sum;
    printf("The program calculates the number of vowels.\n"
            "Enter a word:");
    fgets(word, 255, stdin);

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (word[i] == vowels[j])
            {
                sum++;
            }
        }
    }

    printf("The word contains %d vowels.", sum);
    
    return 0;
}