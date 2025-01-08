// *** TRIE *** - O(1) - Guaranteed constant time
// Disadvantage - uses the most memory
// TRIE is a TREE Structure where each node is an array.

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

const int trieSize = 26;

typedef struct nodeOfTries
{
    char *number; // don't need a name, implicit in the path that you take to find the node
    struct nodeOfTries *children[trieSize]; // array of nodeOfTries pointers initialized with 26 elements
}                                           // 26 ^ 26 power.  Each nodeOfTries has its own array with 26 elements.
nodeOfTries;

void printTrie(nodeOfTries *myTrie);

int main(void)
{
    nodeOfTries *trie = NULL;

    nodeOfTries *tmp = malloc(sizeof(nodeOfTries));
    tmp->number = "1234";
    for(int i = 0; i < trieSize; i++)
    {
        tmp->children[i] = NULL;
    }

    nodeOfTries *tmp2 = malloc(sizeof(nodeOfTries));
    tmp2->number = "6037031403";
    tmp->children[0] = tmp2;

    printTrie(trie);

}

void printTrie(nodeOfTries *myTrie)
{
    while(myTrie != 0)
    {
        // do something
    }
}