// ** LINKED LISTS **

// BIG 'O'
// Search - O(n) - No way to do a binary search
// Insert - O(1) - Constant time for unsorted linked list.
// Insert - O(n) - Linear time for sorted linked list.

// Runtime - Very fast for inserting items in an unsorted data structure.
// Runtime - Not fast for searching items.
// Memory - Efficient. Slightly better than an array for overall memory use.
// Memory - OS memory allocation process is efficient (smaller chunk allocation, free to grab memory anywhere in available ram, more options).
// Memory - Memory never wasted in a Linked List.  Arrays will often need to be copied, resized, or initialization size is overestimated.
// Memory - Individual elements of a Linked List take up more space on a per element basis because of next->pointer.

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// ** Defining a Linked List in C **
// KEYWORDS needed in definition to keep linked list named 'NODE' instead of 'STRUCT NODE' for every reference.
// C KEYWORDS: 'node' keyword needed in title and 'struct' keyword needed in next pointer element name.
typedef struct node
{
    int number; // this particular linked list uses ints.
    struct node *next; // this isn't actually a struct node pointer or a definition of a struct node
                        // but for compiling purposes these extra keywords are needed.
                            // This is a int linked list def. named node.
}
node;

int main(void)
{
    // Creates a pointer that points to the first address to a link list of nodes.
    node *list = NULL;

    // Create a chuck of memory that can hold a node and then assign that chunk's memory address to the pointer, n.
    node *n = malloc(sizeof(node));

    if (n != NULL)
    {
        (*n).number = 1; // n->number = 1; start at n, go there, and assign the value of 1 to that memory address.
        (*n).next = NULL; // clears the pointer to not point to trash
        list = n; // adds to front of list
    }

    n = malloc(sizeof(node));
    if (n != NULL)
    {
        (*n).number = 2;
        (*n).next = NULL;
        (*list).next = n; // list->next = n;
    }

    /* BAD EXAMPLE - WRONG WAY to clear (free) manually acquired dynamic heap memory **
    // USE valgrind ./linkedlist TO SEE FAILURE
     n = malloc(sizeof(node));
     if (n == NULL)
     {
        free(list); // need to manually clear the garbage data and free up the memory chunk
        free(list->next); // MEMORY LEAK - Unable to locate the node with the number 2 in it!
                          // ORPHANED DATA - List removed, list next pointer to the number 2 node is also gone.  Lost in memory.
                          // ERROR - ** YOU should NEVER touch memory you have already freed!
        return 1;
     }
    */

    n = malloc(sizeof(node));
    if (n != NULL)
    {
        (*n).number = 3;
        (*n).next = NULL;
        //list->next->next = n;
        (*list).next->next = n;
    }

    printf("BAD WAY of looping through Linked Lists, accessing indexes via bracket notation, leads to junk data like this: \n");
    // BAD EXAMPLE - WRONG WAY to LOOP through Linked LIST in C.
    // Pointer arithmetic (looping through indexes) doesn't work on lists (or non-contiguous data structures)
    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i].number);
        // Pointer arithmetic doesn't work because Linked Lists in C are non-contiguous
        // Even though the elements were added by sequential means, the indexing doesn't work for linked lists.

        // Looping through Data Structures using indexes in bracket notation donates using pointer arithmetic.
        // Pointer arithmetic means using that data structure's data type's default memory size (an integer default memory size (4 bytes) for example) and...
        // adding those 4 bytes (for ints) to the address of the currently accessed indexed element to locate the address of the next item up in data structure.
        // However, because nodes in a Linked List are in random non-contigous locations in memory, adding 68 bytes (int bytes and node pointer bytes) to location of the current
        // node will take you to some random memory address where no data exists or random data used elsewhere in the program or operating system.
    }

    printf("CORRECT WAY - create a tmp node pointer assigning it list pointer's address and assign tmp = tmp-> on each iteration.\n");

    // GOOD EXAMPLE - RIGHT WAY to LOOP through a Linked List in C.
    // For each loop for looping through linked lists in C.
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    // GOOD EXAMPLE - Correct way to clear a linked list
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }

    return 0;
}

// *** LINKED LIST NODE INSERTION ***
// When inserting nodes at the beginning of linked list:
// First, Copy first node's next pointer (list's node->next pointer) address and assign it to the inserted node next.
// Then, assign newly created node's current address to list's node's->next pointer.

// When inserting nodes anywhere in the middle of the list (Remember finger pointing example in CS50):
// First, locate the node that is already pointing to the node you want the inserted node to point to
// via separtely stored pointer variable to navigate directly to insert location (memory location of node that points to where new node wants to point to),
// or (assuming sorted list) which element number the insert node exists in the list and call->next that many times until node address is located.
// or traverse by value through entire list until program finds value of a node that will end up being the previous node after the inserted node is inserted.

// 2nd, assign that node's next pointer address to the newly created node's next->pointer.
// Last, just like above, assign the newly inserted pointer's address value to previous node's next->pointer.