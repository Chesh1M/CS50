#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int number_of_args, string args[]) // argc = number of arguements, argv = arguements
{
    // Check if arguements are valid
    if (number_of_args != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (number_of_args == 2)
    {
        for (int x = 0, n = strlen(args[1]); x < n; x++)
        {
            if (isalpha(args[1][x]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        // Prompt user for plaintext
        string plaintext = get_string("plaintext: ");

        // Convert key number selected to int
        int key = atoi(args[1]);

        printf("ciphertext: ");
        for (int x = 0, n = strlen(plaintext); x < n; x++)
        {
            char c = plaintext[x];

            // Check if character is an alphabet
            if (isalpha(c))
            {
                // Placeholder value to correspond the alphabets to 0 on the ASCII chart.
                // Depending on whether the alphabet is uppercase or lowercase. By default, assume uppercase, giving placeholder value of 'A' or 65 when converted in ASCII
                char placeholder_value = 'A';

                if (islower(c))
                {
                    // If alphabet is detected to be lowercase, give placeholder value of 'a' or 97 instead.
                    placeholder_value = 'a';
                }
                // Reduce the alphabet/c's ASCII value to 0, apply the key, and finally modulo 26 to get the new alphabet. In case the key causes the alphabet to be >25 (aka Z), which will loop the alphabet back to 'a'
                // Add back the placeholder to get back the corresponding alphabet in the ASCII chart, print the character
                printf("%c", (c - placeholder_value + key) % 26 + placeholder_value);
            }
            else
                // If character is not an alphabet (ie. ! or ?), print it as is
                printf("%c", c);
        }
        printf("\n");
    }
}