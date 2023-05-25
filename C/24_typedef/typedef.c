#include <stdio.h>
#include <string.h>

// typedef = reserved keyword that gives an existing datatype a nickname.

// typedefs
typedef char user[25];  // defining  chararray of size 25 as 'user'.

// typedef in struct.
typedef struct
{
    char name[20];
    char password[24];
    int id;
} Userid;  // nickname at the end.


int main(){


    char user1[25] = "Asd";  // creating a chararray size 25 without typedef nicknames.
    user user2 = "Das";  // Same thing using the 'user' nickname.

    printf("%s, %s\n", user1, user2);

    Userid user3 = {"Sda", "Hunter12", 1};
    Userid user4 = {"Sad", "Hunter12", 2};

    printf("%s, %s, %d", user3.name, user3.password, user3.id);

    return 0;
}