// Implements a dictionary's functionality
#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
node *list;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    list = table[index]->next;
    while (list != NULL)
    {
        int search = strcasecmp(word, list->word);
        if (search != 0)
        {
            list = list->next;
        }
        else
        {
            return true;
        }
    }


    return false;

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int index = 0;
    if (islower(word[0]))
    {
        index = word[0] - 'a';
    }
    else if (isupper(word[0]))
    {
        index = word[0] - 'A';
    }

    return index;
}

int count;
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    count = 0;
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        node *item = malloc(sizeof(node));
        if (item == NULL)
        {
            return false;
        }

        item->next = NULL;
        table[i] = item;
    }

    char buffer[LENGTH + 1];
    int index = 0;
    while (fscanf(file, "%s", buffer) != EOF)
    {
        node *item = malloc(sizeof(node));
        if (item == NULL)
        {
            return false;
        }

        strcpy(item->word, buffer);

        count += 1;

        index = hash(item->word);
        item->next = table[index]->next;
        table[index]->next = item;

    }
    fclose(file);

    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        list = table[i];
        while (list != NULL)
        {
            node *tmp = list;
            list = list->next;
            free(tmp);
        }

    }
    return true;
}
