#include <stdio.h>
#include <cs50.h>
#include <string.h> //get_string
#include <ctype.h> //toupper and tolower

int main(int argc, string argv[])
{
    if (argc != 2) //if a prompt after ./substitution is not given
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string test = argv[1];
    for (int x = 0; x < strlen(test); x++)
    {
        if ((test[x] <= 'Z' && test[x] >='A') || (test[x] >= 'a' && test[x] <= 'z')) //to make sure the key is all letters
        {
            string key = argv[1];
        }
        else
        {
            printf("Usage: ./substitution key\n");
            return 1; //error
        }
    }

    for (int b = 0; b < strlen(test); b++) //to check for duplicates
    {
        for (int c = (b + 1); c < strlen(test); c++)
        {
            if (test[c] == test[b])
            {
                printf("Key must not have any duplicate letters \n");
                return 1;
            }
        }
    }

    string key = argv[1];
    string input = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] >= 32 && input[i] <= 63) //!,?.; etc. (must remain the same)
        {
            printf("%c", input[i]);
        }

        else if (input[i] >= 65 && input[i] <= 90) //uppercase
        {
            int place = input[i] - 64;
            printf("%c", toupper(key[place - 1]));
        }

        else if (input[i] >= 97 && input[i] <= 122) //lowercase
        {
            int place = input[i] - 96;
            printf("%c", tolower(key[place - 1]));
        }
    }

    printf("\n");
}