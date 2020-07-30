#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
//key = 0 when user inputs a letter instead of a number
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string test = argv[1];
    for (int x = 0; x < strlen(test); x++)
    {
        if (test[x] > '9' || test[x] < '0') //to make sure the key is all numbers
        {
            printf("Usage: ./caesar key\n");
            return 1; //error
        }
    }

    int key = atoi(argv[1]); //changes string to a integer
    if (key < 1)
    {
        printf("Usage: ./caesar key\n");
    }

    string input = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; i <= strlen(input); i++)
    {
        if (input[i] >= 32 && input[i] <= 63) //not letters
        {
            printf("%c", input[i]);
        }
        else
        {
            if (input[i] <= 90 && input[i] >= 65)
            {
                if (input[i] + key <= 90 && input[i] + key >= 65) //uppercase letters
                {
                    printf("%c", input[i] + key);
                }
                else //uppercase letters
                {
                    int counter = (input[i] + key) - 90;
                    counter = counter + 64;
                    if (counter < 90)
                    {
                        printf("%c", counter);
                    }
                    else if (counter > 90)
                    {
                        counter = counter - 90; //for larger keys
                        printf("%c", counter + 64);
                    }
                }
            }

            if (input[i] <= 122 && input[i] >= 97)
            {
                if (input[i] + key <= 122 && input[i] + key >= 97) //lowercase letters
                {
                    printf("%c", input[i] + key);
                }
                else //lowercase letters
                {
                    int counter = (input[i] + key) - 122;
                    counter = counter + 96;
                    if (counter < 122)
                    {
                        printf("%c", counter);
                    }

                    else
                    {
                        while (counter > 122) //for larger keys
                        {
                            counter = counter - 122;
                            if (counter > 26)
                            {
                                counter = counter + 96;
                                counter = counter - 122; //for larger keys
                            }

                            printf("%c", counter + 96);
                        }

                    }
                }
            }

        }
    }
    printf("\n");
}