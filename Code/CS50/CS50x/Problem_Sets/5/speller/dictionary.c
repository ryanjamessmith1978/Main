// Implements a dictionary's functionality

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <getopt.h>
#include <math.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1]; // 46
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int hashIndexes = 1024;

int totalElements = 0;
bool isLoaded = true;

// Hash table
node *table[hashIndexes];

// Loads dictionary into memory, returning true if successful, else false
// Open dictionary file
// Read strings from dict. file one at a time
// Create a new node per word
// Hash word using Hash function
// Insert node into hash table at the hash index
bool load(const char *dictionary)
{
    char *word = malloc(LENGTH * sizeof(char*));
    int indexValue;
    FILE *inptr = fopen(dictionary, "r");
    if(inptr == NULL)
    {
        return false;
    }

    // Scan the open file (dictionary passed in), one string at a time, until reaching the end of file.
    while(fscanf(inptr, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        strcpy(n->word, word);
        n->next = NULL;

        indexValue = hash(n->word);
        // insert into link list specified by the hash'd index.
        if(table[indexValue] == NULL)
        {
            table[indexValue] = n; // insert first node to the head of that hash table's index.
        }
        else
        {
            // Insert new node to the beginning of the list, by:
            // pointing new node's next to current head,
            // assigning the new node's address to the value of the head of the list.
            n->next = table[indexValue];
            table[indexValue] = n;
        }

        totalElements++; // keep track of total elements.
    }

    return true;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // strcasecmp
    int correctIndex = hash(word);
    int result;

    node *tmp = table[correctIndex];

    while(tmp != NULL)
    {
        result = strcasecmp(word, tmp->word);

        if(result == 0)
        {
            return true;
        }

        tmp = tmp->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    //return toupper(word[0]) - 'A';


    int hashValue = 0;

    for(int i = 0; i < strlen(word); i++)
    {
        hashValue += tolower((int)word[i]);
    }

    return hashIndexes % hashValue;
}



// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if(isLoaded)
    {
        return totalElements;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Call free() any memory, return true
    // iterating over your hash table
    // iterating over each linked list
    // current variable to where we are in the linked list
    node *current;
    node *tmp;

    // iterate over each index in the hash table
    for(int i = 0; i < hashIndexes; i++)
    {
        current = table[i];

        while(current != NULL)
        {
            tmp = current->next;
            free(current);
            current = tmp;
        }

        if(current == NULL && i == hashIndexes - 1)
        {
            return true;
        }
    }

    return false;
}