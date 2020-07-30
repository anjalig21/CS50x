#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
// l is the average number of letters per 100 words in the text, and s is the average number of sentences per 100 words in the text
// count letters, count words and count sentences
// l = (100/words) * letters
// s = (100/words) * sentences

int main(void)
{
    int sentences = 0;
    int words = 1; // first word does not have a space
    int letters = 0;
    string text = get_string("Text: ");
    for (int i = 0; i <= strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences ++;
        }
        else if (text[i] == ' ')
        {
            words ++;
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            letters ++;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            letters ++;
        }
    }

    float l = (100 / (float)words) * (float)letters;
    float s = (100 / (float)words) * (float)sentences;
    float index = 0.0588 * l - 0.296 * s - 15.8; //equation given to calculate
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index <= 16)
    {
        printf("Grade %.0f\n", round(index));
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

}

