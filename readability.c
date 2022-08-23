#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_words(string text);

int count_sentences(string text);

int count_letters(string text);

int main(void)
{

    string text = get_string("Text: ");
    int words = count_words(text);
    int sentences = count_sentences(text);
    int letters = count_letters(text);
    // printf("words: %i\n", words);
    // printf("sentences: %i\n", sentences);
    // printf("letters: %i\n", letters);
    float index;
    float L = ((float)letters / (float)words) * 100;
    float S = ((float)sentences / (float)words) * 100;
    index = 0.0588 * L - 0.296 * S - 15.8;
    // printf("Value of index: %f\n", index);

    int result = round(index);
    if (result > 16)
    {
        printf("Grade 16+\n");
    }
    else if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", result);
    }
}

int count_words(string text)
{
    int counter = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            counter++;
        }
    }
    return counter + 1;
}

int count_sentences(string text)
{
    int counter = 0;
    int specialChars[] = {'.', '!', '?'};
    for (int i = 0; i < strlen(text); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (text[i] == specialChars[j])
            {
                counter++;
            }
        }
    }
    return counter;
}

int count_letters(string text)
{
    char LETTERS[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int counter = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (islower(text[i]) == 0)
        {
            text[i] = text[i] + 32;
        }
    }
    for (int i = 0; i < strlen(text); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (text[i] == LETTERS[j])
            {
                counter++;
            }
        }
    }
    return counter;
}