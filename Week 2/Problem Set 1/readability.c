#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    float L = count_letters(text) * 100.0 / count_words(text);
    float S = count_sentences(text) * 100.0 / count_words(text);

    int grade_level = round(0.0588 * L - 0.296 * S - 15.8);

    if (grade_level >= 16) {
        printf("Grade 16+\n");
    }
    else if (grade_level < 1) {
        printf("Before Grade 1\n");
    }
    else {
        printf("Grade %d\n", grade_level);
    }
}

// Function for counting number of alphabets in a text excluding spaces etc.
int count_letters(string text) {
    int string_length = strlen(text);
    int count = 0;

    for (int x = 0; x < string_length; x++) {
        if (isalpha(text[x])) {
            count++;
        }
    }
    return count;
}

// Function for counting number of words in a text.
int count_words(string text) {
    int string_length = strlen(text);
    int count = 0;

    for (int x = 0; x < string_length; x++) {
        if (isspace(text[x])) { // Every word is followed by a space (except the last word)
            count++;
        }
    }
    return count+1;
}

// Function for counting number of sentence in a text
int count_sentences(string text) {
    int string_length = strlen(text);
    int count = 0;

    for (int x = 0; x < string_length; x++) {
        if ((int)text[x] == 46 || (int)text[x] == 33 || (int)text[x] == 63) { //Every sentence is followed by either a full stop, exclamation mark or question mark
            count++;
        }
    }
    return count;
}