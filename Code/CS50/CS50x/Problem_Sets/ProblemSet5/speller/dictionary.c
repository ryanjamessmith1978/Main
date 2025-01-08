// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table | LENGTH = 45 (this was typedef'd in the .h file)
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1024;
int dictionarySize = 0;

// Hash table
node *table[N];

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open input file
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        printf("Could not open dictionary\n");
        return false;
    }

    char word[LENGTH + 1];
    int hashIndex = 0;

    while (fscanf(inptr, "%s", word) != EOF)
    {
        node *inWord = malloc(sizeof(node));
        if (inWord == NULL)
        {
            return false;
        }

        strcpy(inWord->word, word);

        // hash word
        hashIndex = hash(inWord->word);
        // Index into your hash table to determine which link list to add this particular word into.
        // Add a new node to a linked list
        // Inserting node into hash table based on which linked list it should belong to
        if(table[hashIndex] == NULL)
        {
            //table[hashIndex] = inWord;
            inWord->next = NULL;
        }
        else
        {
            //node *tmp = malloc(sizeof(node));
            inWord->next = table[hashIndex];
            //free(tmp);
        }
        table[hashIndex] = inWord;
        dictionarySize += 1;
    }

    fclose(inptr);
    //free(inWord);

    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    long sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }

    return sum % N;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Return true if in the dictionary
    // Case insensitive
    // Hash word to obtain hash value
    // Access linked list at hash index in the hash table
    // Traverse linked list, looking for the word (strcasecmp) - case insensitive

    int hashIndex = hash(word);

    for (node *n = table[hashIndex]; n != NULL; n = n->next)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
            n = n->next;
        }
    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dictionarySize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Call free() any memory, return true
    // iterating over your hash table
    // iterating over each linked list
    // variable to where we are in the linked list

    int hashSize = N;

    for (int i = 0; i < hashSize; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        if ((cursor == NULL) && (i == (N - 1)))
        {
            return true;
        }
    }
    return false;

    //node *tmp = malloc(sizeof(node));
    //node *cursor = malloc(sizeof(node));
}