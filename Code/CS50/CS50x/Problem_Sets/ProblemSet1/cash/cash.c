#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

// replace every TODO and return 0;
//

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

// Reads input for user to find how much change is needed
int get_cents(void)
{
    int cents = 0;

    do
    {
        cents = get_int("Changed owed: \n");
    }
    while (cents < 0);

    return cents;
}

// Calculates the number of quarters
int calculate_quarters(int cents)
{
    int quarters = 0;
    quarters = cents / 25;

    return quarters;
}

// Calculates the number of dimes
int calculate_dimes(int cents)
{
    int dimes = 0;
    dimes = cents / 10;

    return dimes;
}

// Calculates the number of nickels
int calculate_nickels(int cents)
{
    int nickels = 0;
    nickels = cents / 5;

    return nickels;
}

// Calculates the number of pennies
int calculate_pennies(int cents)
{
    int pennies = 0;
    pennies = cents;

    return pennies;
}