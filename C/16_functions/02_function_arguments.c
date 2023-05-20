#include <stdio.h>

int main()
{
   char name[] = "Timmy";
   int age = 20;

   birthday(name, age);

   return 0;
}


void birthday(char arg_name[], int arg_age)
{
   printf("\nHappy birthday dear %s!", arg_name);
   printf("\nYou are %d years old!", arg_age);
}
