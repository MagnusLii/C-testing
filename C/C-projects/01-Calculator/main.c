#include <stdio.h>
#include <math.h>

int main()
{
    float firstnum, secondnum, result;
    char operator;

    printf("Enter calculation: ");
    scanf("%f %c %f", &firstnum, &operator, &secondnum);

    switch (operator)
    {
        case '+':
            result = firstnum + secondnum;
            break;
        case '-':
            result = firstnum - secondnum;
            break;
        case '*':
            result = firstnum * secondnum;
            break;
        case '/':
            result = firstnum / secondnum;
            break;
        case '^':
            result = pow(firstnum, secondnum);
            break;
        default: goto error;
    }

    printf("%.2f %c %.2f = %.2f", firstnum, operator, secondnum, result);
    goto end;

    error:
        printf("\nInvalid input!");
        return 1;

    end:
        return 0;
}