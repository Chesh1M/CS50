#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int test_key_validity(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (test_key_validity(argv[1])) // Return non 0 means TRUE, 0 means FALSE
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    string diff = argv[1];

    for (int x = 'A'; x <= 'Z'; x++)
    {
        diff[x - 'A'] = toupper(diff[x - 'A']) - x;
    }

    for (int y = 0, len = strlen(plaintext); y < len; y++)
    {
        if (isalpha(plaintext[y]))
        {
            if (isupper(plaintext[y]))
            {
                plaintext[y] += diff[plaintext[y] - 'A'];
            }
            else
            {
                plaintext[y] += diff[plaintext[y] - 'a'];
            }
        }
        printf("%c", plaintext[y]);
    }
    printf("\n");
}


int test_key_validity(string key)
{
    int len = strlen(key);

    if (len != 26)
        return 1;

    int freq[26] = {0};

    for (int x = 0; x < len; x++)
    {
        if (!isalpha(key[x]))
        {
            return 1;
        }

        int index = toupper(key[x]) - 'A';

        if (freq[index] > 0)
        {
            return 1;
        }
        freq[index]++;
    }

    return 0;
}