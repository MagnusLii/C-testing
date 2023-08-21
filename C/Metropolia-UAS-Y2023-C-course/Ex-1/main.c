#include <stdio.h>

int main(void)
{
    float busTicketPrice, taxiTripPrice, money;
    int selection;

    printf("Enter price of bus ticket: ");
    scanf("%f", &busTicketPrice);

    printf("Enter price of taxi: ");
    scanf("%f", &taxiTripPrice);

    printf("How much money you have: ");
    scanf("%f", &money);

    while (money >= busTicketPrice || money >= taxiTripPrice)
    {
        printf("\n\n--------------------------------\n");
        printf("You have %.2f euros left.\n", money);
        printf("Do you want to take\n");
        printf("1) bus (%.2f euros)\n", busTicketPrice);
        printf("2) taxi (%.2f euros)\n", taxiTripPrice);
        printf("Enter your selection: ");
        scanf("%d", &selection);

        switch (selection)
        {
        case 1:
            if (money < busTicketPrice)
            {
                printf("You don't have enough money for bus.\n");
                continue;
            }
            else
            {
                money -= busTicketPrice;
                printf("You chose bus.\n");
            }
            break;
        case 2:
            if (money < taxiTripPrice)
            {
                printf("You don't have enough money for taxi.\n");
                continue;
            }
            else
            {
                money -= taxiTripPrice;
                printf("You chose taxi.\n");
            }
            break;
        default:
        {
            printf("Invalid selection.\n");
        }
        break;
        }
    }

    printf("You have %.2f euros left.\n"
           "You need to walk. Bye\n",
           money);

    return 0;
}