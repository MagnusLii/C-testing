#include <stdio.h>

int main(){

    FILE *pFile = fopen("hello.usr", "w");  // w = write, a = append, r = read. If using path use \\  as that's the escape sequence for \.

    printf("Writing to the file was successful.\n");

    fprintf(pFile, "Hello world!\n");

    printf("Closing the program.\n");

    fclose(pFile);

    return 0;
}