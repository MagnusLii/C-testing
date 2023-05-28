#include <stdio.h>

int main(){

    FILE *pFile = fopen("test.txt", "w");  // w = write, a = append, r = read. If using path use \\  as that's the escape sequence for \.

    fprintf(pFile, "Spongebob Squarepants.");

    fclose(pFile);

    if(remove("test.txt") == 0){
        printf("File removal success.");
    }
    else{
        printf("Error!");
    }

    return 0;
}