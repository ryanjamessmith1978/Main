#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    node *list = NULL;

    for(int i = 1; i <argc; i++)
    {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if (!n){return 1;} // Subtle bug - if not n in the 2nd iteration of the loop, but not first.  First was never freed.

        n->number = number;
        n->next = NULL;
        n->next = list; // both list pointer and n->next point to first node in list

        list = n; // the start of the list (list pointer) is now pointing to the node just added to the list
        // pre-pending or setting up a stack LIFO data structure - paradigm.
    }

    // *** TO ITERATE THROUGH A LINKED LiST ***

    node *tmp = list; // Create a temporary pointer as a place holder to check values of a list - starts a head of list

    while(tmp != NULL) // While the tmp pointer has a valid address value
    {
        printf("%i \n", tmp->number); // Do something (read) the current value.
        tmp = tmp->next;  // Assign the ptr node to point to the next value in the list
    }
    // Doesn't modify original list values or change the next node values.  Maintains original list integrity.
    // Wouldn't do this to change multiple values in original linked list, but used to read or search for values.

    tmp = list; // resets the tmp to point to the beginning of the original list.
    while (tmp != NULL)
    {
        node *temp = tmp->next;
        free(tmp);
        tmp = temp;
    }

}