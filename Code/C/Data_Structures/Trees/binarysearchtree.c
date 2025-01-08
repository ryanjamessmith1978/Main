// ** Binary Search Tree **
//
// Root is the top of tree, one variable (root) allows for full navigation of all treeNodes.
// Every left child is smaller than the parent, every right child is larger than the parent
// Every tree and subtree has at most 2 children.

// Big 'O'
// Runtime - (O)log(n) - binary search runtime to find element in tree
// Runtime - (O)n - if not properly setup with a balance in the tree - a one sided tree is the same thing as a list.
// Memory - More space used on a per element basis.

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct treeNode
{
    int number;
    struct treeNode *left;
    struct treeNode *right;
}
treeNode;

void printTree(treeNode *currentNode);
void free_tree(treeNode *currentNode);
bool search_tree(treeNode *currentNode, int value);

int main(void)
{
    treeNode *myTree = NULL;

    treeNode *n = malloc(sizeof(treeNode));
    if(n == NULL)
    {
        return 1;
    }

    (*n).number = 4;
    (*n).right = NULL;
    (*n).left = NULL;
    myTree = n;

    n = malloc(sizeof(treeNode));
    if(n == NULL)
    {
        free(myTree);
        return 1;
    }

    (*n).number = 2;
    (*n).right = NULL;
    (*n).left = NULL;
    (*myTree).left = n;

    n = malloc(sizeof(treeNode));
    if(n == NULL)
    {
        free(myTree->left);
        free(myTree);
        return 1;
    }

    (*n).number = 3;
    (*n).right = NULL;
    (*n).left = NULL;
    (*myTree).left->right = n;

    // Recursive printTree call explained below.
    printTree(myTree);

    bool valueInTree = search_tree(myTree, 5);

    printf("The value was found in tree: %i\n", valueInTree);

    free_tree(myTree);

    return 0;
}

// ** TREE RECURSION ** printTree(treeNode*) STACK BREAKDOWN

// Original root for myTree(4) gets passed into printTree in main; printTree(myTree(4)) is put on top of stack with it's integer value of 4.
// Before printTree(myTree(4)) finishes, it puts currentNode->left(2).printTree() on top of stack (recursively)
// printTree(myTree(4)) is now at bottom of stack.
// CurrentNode(2) calls printTree(left) - 2nd time printTreeLeft is put on top of stack, but it immediately returns, popping it off the stack
// CurrentNode(2) continues with it's own PrintTree call and prints it value of 2, then recursively calls printTreeRight().
// CurrentNode(2) goes to middle of stack, printTree(4) still at bottom of stack, and CurrentNode(3).printTree() is currently at top of stack
// CurrentNode(3) calls printLeft, immediately pops off stack, resumes CurrentNode(3).printTree then prints its value of 3.
// CurrentNode(3) calls printTreeRight, it goes to top of stack, then immediately pops off.  What's the next highest on the stack?
// CurrentNode(3).printTree() is still on top of stack after passing NULL to printTreeRight.
// With nothing else to do, CurrnetNode(3).printTree returns, popping itself off stack and adding NO NEW function calls to top of stack.
// CurrentNode(2) waiting patiently, is back on top of stack but with nothing left to do, it finally returns.
// The initial myTree.printTree(4) is back on the top of the stack and with printLeft with nothing left to do, myTree(4) prints its value of 4.
// CurrentNode(4) puts printRightTree on top of stack but immediately is popped off stack because it's null
// Lastly, myTree.printTree(4) has no more instructions to do, so it returns, ending the original recursive function call.

void printTree(treeNode* currentNode)
{
    if(currentNode == NULL)
    {
        return;
    }

    printTree(currentNode->left);
    printf("%i\n", currentNode->number);
    printTree(currentNode->right);

}

void free_tree(treeNode *currentNode)
{
    if(currentNode == NULL)
    {
        return;
    }

    free_tree(currentNode->left);
    free_tree(currentNode->right);
    free(currentNode);
}

bool search_tree(treeNode *currentNode, int value)
{
    if(currentNode == NULL)
    {
        return false;
    }

    if(currentNode->number == value)
    {
        return true;
    }
    else if(currentNode->number < value)
    {
        search_tree(currentNode->left, value); // search_tree((*currentNode).left);
    }
    else if(currentNode->number > value)
    {
        search_tree(currentNode->right, value);
    }

    return false;

}