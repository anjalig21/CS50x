#include <stdio.h> //needed to recognize and compile code
#include <cs50.h> //needed to recognize and compile code

int main(void)
{
    int n; //height is an integer
    do 
    {
        n = get_int("Height: "); //get height as an input from user (integer)
    }
    while (n < 1 || n > 8); //Height must be between 1-8
    
    for (int i = 1; i <= n; i++)
    {
        for (int x = (n - 1); x >= i; x--)
        {
            printf(" "); //right-alligned
        } 
        for (int y = 1; y <= i; y ++)
        {
            printf("#");
        }
        for (int c = 1; c <= 2; c++)
        {
            printf(" "); //space in between the towers
        }
        for (int k = 1; k <= i; k++)
        {
            printf("#"); 
        }
       
        printf("\n"); //new line
    }
}

