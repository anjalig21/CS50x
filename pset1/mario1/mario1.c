#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8); //only accept values between 1-8
    for (int i = 1; i <= n; i++)
    {
        for (int j = (n - 1); j >= i; j--)
        {
            printf(" "); //right-alligned
        }
        for (int x = 1; x <= i; x++)
        {
            printf("#"); //bricks
        }

        printf("\n");
    }

}
