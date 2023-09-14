#include <stdio.h>
#include <string.h>

int main()
{
    int getfrom = 13;
    char saveto[7];

sprintf(saveto, "%06d", getfrom);
    
    printf("%s", saveto);
    return 0;
}