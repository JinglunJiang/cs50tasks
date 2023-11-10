#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> // Just too many libraries should remember to add

int check_key_length(string key);
int check_alphabetic_characters(string key);
bool check_repeated_characters(string key);

int main(int argc, string argv[]) // One for number of command line arguments, one for the position
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    } // Gave me lots segmentation issues, should check the number before defind the below ones
    int key_length = check_key_length(argv[1]);
    int alphabetic_characters = check_alphabetic_characters(argv[1]);
    bool repeated_characters = check_repeated_characters(argv[1]); // The devils
    if (key_length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (alphabetic_characters != 26)
    {
        printf("Key must only contain alphabatic characters.\n");
        return 1;
    }
    else if (repeated_characters)
    {
        printf("Key must not contain repeated characters.\n"); // All above are just some boring error messages
        return 1;
    }
    else // Finally got to the interesting part...
    {
        string key = argv[1];
        int i = 0;
        for (i = 0; i < 26; i++) // Thanks to the known number of alphabets
        {
            key[i] = tolower(key[i]);
        }
        string plain_text = get_string("plaintext: ");
        int k = 0;
        int text_length = strlen(plain_text);
        char *lower_text = malloc((text_length + 1) * sizeof(char)); // Chatgpt taught me this
        while (plain_text[k] != '\0') // Optimize this process next time
        {
            lower_text[k] = tolower(plain_text[k]); // Transform the plain text to all lowercase
            k++;
        }
        int j = 0;
        while (lower_text[j] != '\0')
        {
            if (lower_text[j] >= 'a' && lower_text[j] <= 'z') // Only process the ones that are alphabets
            {
                int index = lower_text[j] - 'a'; // Find the letter that should be matched
                lower_text[j] = key[index]; // Second time to use the index, very useful
                if (isupper(plain_text[j]))
                {
                    lower_text[j] = toupper(lower_text[j]); // Convert the text back to its original case
                }
            }
            j++;
        }
        printf("ciphertext: %s\n", lower_text);
    }
}

int check_key_length(string key) // A function to check the length of the key
{
    int i = 0;
    while (key[i] != '\0')
    {
        i++;
    }
    return i;
}

int check_alphabetic_characters(string key) // A function used to check if all characters are alphabetics characters
{
    int i = 0;
    int alphabetic_characters = 0;
    int text_length = strlen(key);
    char *lower_text = malloc((text_length + 1) * sizeof(char));
    while (key[i] != '\0')
    {
        lower_text[i] = tolower(key[i]);
        if (lower_text[i] >= 'a' && lower_text[i] <= 'z')
        {
            alphabetic_characters += 1;
        }
        i++;
    }
    return alphabetic_characters;
}

bool check_repeated_characters(string key) // Check if there's repeated characters
{
    int i = 0;
    int text_length = strlen(key);
    char *lower_text = malloc((text_length + 1) * sizeof(char));
    for (i = 0; i < 25; i++)
    {
        lower_text[i] = tolower(key[i]);
        int j = 0;
        for (j = i + 1; j < 26; j++)
        {
            lower_text[j] = tolower(key[j]);
            if (lower_text[i] == lower_text[j])
            {
                return true;
            }
        }
    }
    return false;
}
