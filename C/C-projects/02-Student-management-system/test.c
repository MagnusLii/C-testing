#include <stdio.h>
#include <string.h>

struct Student
{
    int studentind;
    char firstname[20], lastname[20], studentid[13], major[20];
};

typedef struct Student Struct;

Struct fetch_student_data(int studentind)
{
    Struct student;
    int tokencount = 0, linecount = 0;
    char *token, buffer[255];
    FILE *pFile2 = fopen("db.txt", "r");

    while ((fgets(buffer, 255, pFile2)) != NULL)
    {
        linecount++;
        if (linecount == studentind + 2)
        {
            token = strtok(buffer, ", ");
            while (token != NULL)
            {
                switch (tokencount)
                {
                case 0:
                    student.studentind = atoi(token);
                    break;
                case 1:
                    strncpy(student.firstname, token, sizeof(student.firstname) - 1);
                    student.firstname[sizeof(student.firstname) - 1] = '\0';
                    break;
                case 2:
                    strncpy(student.lastname, token, sizeof(student.lastname) - 1);
                    student.lastname[sizeof(student.lastname) - 1] = '\0';
                    break;
                case 3:
                    strncpy(student.studentid, token, sizeof(student.studentid) - 1);
                    student.studentid[sizeof(student.studentid) - 1] = '\0';
                    break;
                case 4:
                    strncpy(student.major, token, sizeof(student.major) - 1);
                    student.major[sizeof(student.major) - 1] = '\0';
                    break;
                }

                token = strtok(NULL, ", ");
                tokencount++;
            }
        }
    }
    return student;
}

int main()
{

    struct Student playerone = fetch_student_data(2);

    printf("%d, %s, %s, %s, %s\n", playerone.studentind, playerone.firstname, playerone.lastname, playerone.studentid, playerone.major);

    return 0;
}