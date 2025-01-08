// *** HASH TABLE *** O(n) - worst case with poor hash function
// Really close to O(1) with the caveat of having good hash function

// Hash Tables use the concepts introduced in Dictionaries/Maps to organize values
// 'Bucketizing' - Shrinking a problem - hashing the values
// Larger Domain to a smaller Range.
// Hash function is the algorithm/math that implements the concept of 'bucketizing'.

// HashMap is non-syncronized and is not thread safe while HashTable is thread safe and is synchronized.
// HashMap allows one null key and null values whereas HashTable doesn't allow null key or value.
// HashMap is faster than HashTable

#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    char word[LENGTH + 1]; // value of this element
    struct node *next; // pointer to next value in this linked list.
}
hashTable; // Hash Table is an array with linked list elements.

CONST int elements = 64;

int main(void)
{
    hashTable *myHashTable[64]; // array of pointers of size 64.  * doesn't go inside the brackets.
    // hashTable is the type (typedef'd above)
    // myHashTable is the name.

}