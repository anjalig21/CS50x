#include <stdio.h> //needed to understand the code
#include <cs50.h> //needed to understand the code
#include <string.h> //needed for get_string function 

int main(void)
{
    string name = get_string("What is your name? "); //inputs for your name
    printf("hello, %s\n", name); //prints the name that was inputted
}
