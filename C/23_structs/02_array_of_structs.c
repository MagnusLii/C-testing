#include <stdio.h>
#include <string.h>

struct Student
{
    char name[20];
    float gpa;
};


int main(){

    struct Student student1 = {"St1", 3.78};
    struct Student student2 = {"St2", 4.123};
    struct Student student3 = {"St3", 1.423};
    struct Student student4 = {"St4", 2.0};

    struct Student students[] = {student1, student2, student3, student4};

    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++)
    {
        printf("Name: %s, GPA: %.2f\n\n", students[i].name, students[i].gpa);
    }
    

    return 0;
}