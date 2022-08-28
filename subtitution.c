#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
string encrypt(string text, string key);
// int cipherKey[26];
char LETTERS[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char CAPITAL[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    int counter = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (key[i] == LETTERS[j] || key[i] == CAPITAL[j])
            {
                counter++;
            }
        }
    }
    if (counter != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (islower(key[i]) == 0)
        {
            key[i] = key[i] + 32;
        }
    }
    // This is supposed to return 1 if you have duplicate values in key
    for (int i = 0; i < 26; i++)
    {
        int counter2 = 0;
        for (int j = 0; j < 26; j++)
        {
            if (key[i] == LETTERS[j])
            {
                counter2 = counter2 + 1;
                printf("counter2 is %i\n", counter2);
                if (counter2 > 1)
                {
                    return 1;
                }
            }
        }
    }

    string plainText = get_string("plaintext: ");
    printf("ciphertext: %s\n", encrypt(plainText, key));
    return 0;
}

string encrypt(string plainText, string key)
{
    // string cipherText = NULL;
    // strcpy(cipherText, plainText);

    for (int i = 0; i < strlen(plainText); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (plainText[i] == LETTERS[j])
            {

                plainText[i] = key[j];

                // printf("key[j] is %c and cipherText[i] is %c\n", key[j], plainText[i]);
                break;
                // printf("cipherText[i] = %c \n", cipherText[i]);
            }
            else if (plainText[i] == (CAPITAL[j]))
            {
                plainText[i] = key[j] - 32;
                break;
            }
        }
    }
    return plainText;
}