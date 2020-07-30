#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    int change;
    int counter = 0;

    do
    {
        dollars = get_float("Change owed in dollars: ");
        change = round(dollars * 100);
    }
    while (change < 0);

    while (change >= 25)
    {
        (change = change - 25); //start with the highest coin value (quarters)
        (counter++);
    }

    while (change >= 10)
    {
        (change = change - 10); //dimes
        (counter++);
    }
    while (change >= 5)
    {
        (change = change - 5); //nickels
        (counter++);
    }
    while (change >= 1)
    {
        (change = change - 1); //pennies
        (counter++);
    }
    printf("%i coins\n", counter);
}
