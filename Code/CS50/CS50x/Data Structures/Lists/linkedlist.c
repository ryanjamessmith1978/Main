// ** LINKED LISTS **

// BIG 'O'
// Search - O(n) - No way to do a binary search. Random accessing is not possible in linked lists. Arrays can.
// Insert - O(1) - Constant time for unsorted linked list.
// Insert - O(n) - Linear time for sorted linked list.

// Runtime - Very fast for inserting items in an unsorted data structure.
// Runtime - Not fast for searching items.
// Memory - Efficient. Slightly better than an array for overall memory use.
// Memory - OS memory allocation process is efficient (smaller chunk allocation, free to grab memory anywhere in available ram, more options).
// Memory - Memory never wasted in a Linked List.  Arrays will often need to be copied, resized, or initialization size is overestimated.
// Memory - Individual elements of a Linked List take up more space on a per element basis because of next->pointer.

// Random accessing is not possible in linked lists.

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// ** Defining a Linked List in C **
// KEYWORDS needed in definition to keep linked list named 'NODE' instead of 'STRUCT NODE' for every reference.
// C KEYWORDS: 'node' keyword needed in title and 'struct' keyword needed in next pointer element name.
typedef struct _node
{
    int number; // this particular linked list uses ints.
    struct _node *next; // struct keyword needed for compiler's sake.  Same as function prototypes
    // next is actually a '_node' element and not a struct _node, despite it's definition here.
}
node;

int main(void)
{
    // Creates a pointer that points to the first address to a link list of nodes.
    // The pointer does have some memory value in of itself (without the pointee) because, list is a variable on the stack.
    node *list = NULL; // Creates a node pointer on the stack pointing to NULL.
    // The pointee memory chunk(heap) created with malloc will return it's index 0 address and assign it to the stack variable list.
    // Array variables themselves doesn't require separate memory, it's replaceable directly with the first element
    // The array name is directly associated with it's index 0 value.
    // node list[]; - This won't compile because array length wasn't specified, or initialized values weren't declared.
    node *list2[] = {malloc(sizeof(node)), malloc(sizeof(node))}; // this is a hash table
    node list3[3]; // this is an array of nodes (not pointers).
    node n1;
    // n1->number = 5 // n1 is not a pointer, therefor you can't deference to access one of it's fields.
    n1.number = 5; // Dot notation used to access individual elements of a struct that doesn't have pointer associated with it.
    node *n1ptr = NULL; // Create a null ptr on the stack.
    n1ptr = malloc(sizeof(node)); // Create a chunk of memory on the heap and assign it's memory address to the pointer
    if(n1ptr != NULL)
    {
        n1.next = n1ptr; // Since n1 is still a regular variable and not a pointer variable, use dot notation to assign
        // it's next value which is a pointer.
    }

    // Create a chuck of memory that can hold a node and then assign that chunk's memory address to n.
    node *n = malloc(sizeof(node));

    if (n != NULL)
    {
        // Dereference n.  With a struct pointer you need to deference the struct node first and use brackets before dot notation
        // Or you can use -> arrow notation
        (*n).number = 1; // or n->number = 1;
        (*n).next = NULL; // clears the garbage value of the next pointer.
        list = n; // adds new n node to the front of list
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
        printf("%i\n", list[i].number); // Because to find the next element in a list, you can't just add a memory value of a node
                                        // That will only take you one node's worth of memory after the previous element.
                                        // Nodes in a list can be anywhere in memory, not neccesarily one memory block over

        // Pointer arithmetic doesn't work because Linked Lists are non-contiguous
        // Looping with indexes is possible with Arrays because arrays are contigous, hence each element
        // is exactly one array element's memory value added to the current spot in memory to find next element.

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
        // at the end of each loop, set the tmp node to next
        // tmp = tmp->next
    }

    node *tmp = list;

    while(tmp != NULL)
    {
        printf("%i\n", tmp->number);
        tmp = tmp->next;
    }

    // GOOD EXAMPLE - Correct way to clear a linked list
    while (list != NULL)
    {
        node *tmpNode = list->next;
        free(list);
        list = tmpNode;
    }

    return 0;
}

// *** LINKED LIST NODE INSERTION ***
// When inserting nodes at the BEGINNING of linked list: O(1)
// Assign the newly inserted Node's next pointer first, before doing anything else
// newNode->next points to memory address of current head of the list. newNode->next = list;
// Assign new Node's value to list. list = Node;

// When inserting nodes anywhere in the MIDDLE of the list: O(n)
// Locate the node that is already pointing to the node you want the inserted node to point to (before node)

// 2nd, assign that node's(previous node) next pointer address value to the new node's next pointer. newNode->next = prevNode->next
// Last, assign new node to previous node's next->pointer. prevNode->next = newNode;