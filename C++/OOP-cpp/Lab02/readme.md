Write a program that asks user to enter a line that contains integers or “stop” to stop the program. If user enters a string that starts with “stop” the program stops. Otherwise, the program creates a string stream from the user input and reads integers from the stream. Program keeps reading and summing integer until the stream ends or reading an integer fails because text or other non- numerical character is encountered. When the reading stops the sum and count are printed and program asks user to enter another string.

For example:
```
Enter a line with numbers or “stop”: 1 6 34 78 4 6
Total of 6 numbers is 129
Enter a line with numbers or “stop”: 4 99 zip 44 6
Total of 2 numbers is 103
Enter a line with numbers or “stop”: stop
```
File system

Std::filesystem abstracts path handling and directory crea=on. The library provides func=onality to resolve rela=ve path to absolute path and operators for easy building of paths in a plaHorm independent way.

Std::filesystem::path has overloaded operators for crea=ng a path by concatena=ng paths or strings. The resul=ng path can be used to open files or for example, to create mul=ple directories.

Implement a program that asks user to enter directory names or enter a blank line to stop entry. The read names are stored in a vector of strings. When user has stopped entering directory names the program forms a rela=ve path from the entered directory names. For example, if user entered “this”, “is”, and “test” the path is “this/is/test” (assuming posix opera=ng system, on windows the result ). To form a path use concatena=on operator defined for std::filesystem::path.

Then program creates the path using create_directories (see: hMps://en.cppreference.com/w/cpp/filesystem/create_directory ). AOer crea=ng the directory, the program opens a text file “result.txt” for wri=ng in the created directory and outputs the following thing both to screen and the file:

    Absolute path to the file (there is a func=on to get that)
    Content of the string vector one per line
    Rela=ve path to the file

Note that since C++17 ofstream (and fstream in general) constructor can take filesystem::path as parameter