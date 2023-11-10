// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 26 + 1;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor -> word) == 0)
        {
            return true;
        }
        cursor = cursor -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    char first = tolower(word[0]);
    char second;
    if (word[1] == 0)
    {
        second = '\0';
        return (first - 'a') * 26;
    }
    else
    {
        second = tolower(word[1]);
        return (first - 'a') * 26 + (second - 'a') + 1;
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char word[LENGTH + 1];
    FILE *file = fopen(dictionary, "r");
    int wordcount = 0;
    if (dictionary == NULL)
    {
        return false;
    }
    else
    {
        while (fscanf(file, "%s", word) != EOF)
        {
            node *newnode = malloc(sizeof(node));
            if (newnode == NULL)
            {
                fclose(file);
                return false;
            }
            else
            {
                strcpy(newnode -> word, word);
                newnode -> next = NULL;
                unsigned int index = hash(word);
                if (table[index] == NULL)
                {
                    table[index] = newnode;
                }
                else
                {
                    newnode -> next = table[index];
                    table[index] = newnode;
                }
                wordcount++;
            }
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int wordcount = 0;
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            wordcount++;
            cursor = cursor -> next;
        }
    }
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor -> next;
            free(tmp);
        }
        table[i] = NULL;
    }
    return true;
}
