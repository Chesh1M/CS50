#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int quarters, dimes, nickels, pennies, remainders, min_coins;

    float change_owed_in_dollars;
    // Prompt for change owed in dollars
    do {
        change_owed_in_dollars = get_float("How much change is owed? (in dollars): ");
    } while (change_owed_in_dollars <= 0); // Keep repeating prompt if input is not an <= 0 dollars

    int change_owed_in_cents = round(change_owed_in_dollars * 100); // Convert changed owed in dollars to cents

    quarters = change_owed_in_cents / 25;
    remainders = change_owed_in_cents % 25;

    dimes = remainders / 10;
    remainders = remainders % 10;

    nickels = remainders / 5;
    remainders = remainders % 5;

    pennies = remainders / 1;

    min_coins = quarters + dimes + nickels + pennies; // Add up total number of coins required

    printf("%d\n", min_coins);
}