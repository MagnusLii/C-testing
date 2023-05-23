#include <stdio.h>
#include <string.h>

// struct = collection of related members ("variables") 
//          they can be of different data types
//          listed under one name in a block of memory
//          VERY SIMILAR to classes in other languages (but no methods)

struct Player  // defining a struct. Must be defined before main().
{
    char name[24];
    int score;

};


int main(){

    struct Player player1;  // creating a struct.
    struct Player player2;

    strcpy(player1.name, "asd");  // adding values.
    player1.score = 4;

    strcpy(player2.name, "dsa");
    player2.score = 5;

    printf("%s's score is %d\n", player1.name, player1.score);
    printf("%s's score is %d\n", player2.name, player2.score);

    return 0;
}



