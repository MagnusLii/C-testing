#include <stdio.h>

    // pointer = a "variable-like" reference that holds a memory address to another variable, array, etc.
    //           some tasks are performed more easily with pointers
    //           * = indirection operator (value at address)


void printAge(int *pAge);


int main()
{

    int age = 200;
    int *pAge = &age;  // pointer. Datatype needs to be consistent with what it's pointing to.

    printAge(pAge);

    printf("address of age: %p\n", &age);
    printf("value of pAge: %p\n\n", pAge);

    printf("size of age: %d bytes\n", sizeof(age));
    printf("size of pAge: %d bytes\n\n", sizeof(pAge));

    printf("value of age: %d\n", age);
    printf("value at stored address: %d\n", *pAge); //dereferencing

    return 0;
}

void printAge(int *pAge)
{
    printf("You are %d years old\n\n", *pAge);  //dereference
}