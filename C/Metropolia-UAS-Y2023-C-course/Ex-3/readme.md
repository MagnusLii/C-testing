Ex 3.
That asks number of students and creates an array of that many integers.
Program then initializes the array elements to -1.
Then the program asks user to enter student number in range 1 – nr of students or zero to stop. If
valid non zero number is given the program asks user to enter grade in the range 0-5 or -1 to not
enter a grade for the student.
When user stops by entering 0 then program prints student numbers followed by grade or N/A if
grade is -1.
For example:

```
How many students: 4
Enter student number (1 – 4) or 0 to stop: 1
Enter grade (0 – 5) for student 1 or -1 to cancel: 2
Enter student number (1 – 4) or 0 to stop: 6
Invalid student number!
Enter student number (1 – 4) or 0 to stop: 3
Enter grade (0 – 5) for student 3 or -1 to cancel: 7
Invalid grade!
Enter grade (0 – 5) for student 3 or -1 to cancel: 5
Enter student number (1 – 4) or 0 to stop: 2
Enter grade (0 – 5) for student 2 or -1 to cancel: -1
Enter student number (1 – 4) or 0 to stop: 0
Student Grade
1 2
2 N/A
3 5
4 N/A```