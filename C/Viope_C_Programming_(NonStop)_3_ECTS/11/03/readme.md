Write a program for removing a specific person's data from the directory. The program asks for a first name followed by a last name. The program checks if the person's data can be found. If the person is in the directory, the data is removed. Otherwise print an error message.

Hint:
You should carefully design the program before writing any actual code. The use of structures may make the task easier. It is most obvious that when you save an updated list, the existing data in the file phonedir.txt is overwritten.

You can compare name information using the C language function strcmp() in the library file string.h. You can find information about using the function in the C manual.

Example output:
```c
Enter first name:Tim
Enter last name:Franklin
Data removed from the directory.
```

The verification of program output does not account for whitespace characters like "\n", "\t" and " "