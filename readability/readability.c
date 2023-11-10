#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letter_number = count_letters(text); // Call the function
    int word_number = count_words(text); // Call the function
    int sentence_number = count_sentences(text); // As above
    double index = 0.0588 * letter_number / word_number * 100 - 0.296 * sentence_number / word_number * 100 - 15.8;
    int rounded_index = (int)round(index); // Need to include a new library
    if (rounded_index <= 1) //Print the Grade
    {
        printf("Before Grade 1\n");
    }
    else if (rounded_index < 16)
    {
        printf("Grade %i\n", rounded_index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text) // Count the letters by making them all lower space
{
    int letter_number = 0;
    int i = 0;
    while (text[i] != '\0')
    {
        text[i] = tolower(text[i]); // Switching all to lowercase
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            letter_number += 1;
        }
        i++; // The i should by in the biggest loop
    }
    return letter_number;
}

int count_words(string text) // Count words by counting the spaces and plus 1
{
    int word_number = 1;
    int i = 0;
    while (text[i] != '\0') // Check if the string ends
    {
        if (text[i] == ' ') // Still need to figure our how to detect two spaces
        {
            word_number += 1;
        }
        i++;
    }
    return word_number;
}

int count_sentences(string text) // Count the number of sentences by counting the determining marks
{
    int sentence_number = 0;
    int i = 0;
    while (text[i] != '\0')
    {
        if (text[i] == '.' | text[i] == '?' | text[i] == '!')
        {
            sentence_number += 1;
        }
        i++;
    }
    return (sentence_number);
}