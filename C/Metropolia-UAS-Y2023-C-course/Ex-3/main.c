#include <stdio.h>

int main()
{
    int students, studentNumber, grade;

    printf("How many students: ");
    scanf("%d", &students);

    int studentGrades[students];

    for (int i = 0; i < students; i++)
    {
        studentGrades[i] = -1;
    }

    while (1)
    {
        printf("Enter student number (1 - %d) or 0 to stop: ", students);
        scanf("%d", &studentNumber);

        if (studentNumber == 0)
        {
            break;
        }
        else if (studentNumber < 1 || studentNumber > students)
        {
            printf("Invalid student number!\n");
            continue;
        }
    rentergrade:
        printf("Enter grade (0 - 5) for student %d or -1 to cancel: ", studentNumber);
        scanf("%d", &grade);

        if (grade == -1)
        {
            continue;
        }
        else if (grade < 0 || grade > 5)
        {
            printf("Invalid grade!\n");
            goto rentergrade;
        }
        studentGrades[studentNumber - 1] = grade;
    }

    printf("Student Grade\n");

    for (int i = 0; i < students; i++)
    {
        if (studentGrades[i] != -1)
        {
            printf("%2d %2d\n", i + 1, studentGrades[i]);
        }
        else
        {
            printf("%2d %2s\n", i + 1, "N/A");
        }
    }

    return 0;
}