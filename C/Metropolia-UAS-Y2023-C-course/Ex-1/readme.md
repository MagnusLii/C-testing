Ex 1.
Write a program that:
1. Asks user to enter the price of a bus ticket
2. Asks user to enter the price of a taxi trip
3. Asks user to enter how much money he/she has
4. If user has not enough money for either type tells user to walk and then the program stops
5. Asks user to choose taxi or bus (use numbers for selection)
6. Checks if user has enough money for the selected trip type
o If User has enough money reduce the money by the selected trip’s price and print
how much money is left, and go back to step 4
o If user has not enough money for the selected trip type then tell that to user and go
back to step 4

For example:

```Enter price of bus ticket: 3.50
Enter price of taxi: 25.70
How much money you have: 30
You have 30.00 euros left.
Do you want to take
1) bus (3.50 euros)
2) taxi (25.70 euros)
Enter your selection: 2
You chose taxi.
You have 4.30 euros left.
Do you want to take
1) bus (3.50 euros)
2) taxi (25.70 euros)
Enter your selection: 2
You chose taxi.
You don’t have enough money for taxi.
You have 4.30 euros left.
Do you want to take
1) bus (3.50 euros)
2) taxi (25.70 euros)
Enter your selection: 1
You chose bus.
You have 0.80 euros left.
You need to walk. Bye```