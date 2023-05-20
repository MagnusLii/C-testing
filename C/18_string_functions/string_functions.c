#include <stdio.h>
#include <string.h>  // Contains many useful string functions.


int main(){

    char string1[] = "Undevised";
    char string2[] = "Asynchronousity";
    int n = 3;

    //strlwr(string1);  // converts string to lowercase.
    //strupr(string1);  // converts a string to uppercase.
    //strcat(string1, string2);  // concatenates (appends) 'string2' to end of 'string1'.
    //strncat(string1, string2, n);  // appends n characters from 'string2' to 'string1'.
    //strcpy(string1, string2);  // copies 'string2' to 'string1'.
    //strncpy(string1, string2, n);      // copies n characters of 'string2' to 'string1'.

    //strset(string1, '?');  // sets all characters of a string to a given character.
    //strnset(string1, 'x', 1);  // sets first n characters of a string to a given character.
    //strrev(string1);  // reverses a string.

    //int result = strlen(string1);  // returns string length as int.
    //int result = strcmp(string1, string2);  // compares characters in strings and returns number of differing characters.
    //int result = strncmp(string1, string2, n);  // string compare n characters.
    //int result = strcmpi(string1, string1);  // string compare all (ignore case).
    //int result = strnicmp(string1, string1, 1);  // string compare n characters (ignore case).

    printf("%s", string1);

    return 0;
}