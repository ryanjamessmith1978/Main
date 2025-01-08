// BinarySearchTree.cpp | https://www.youtube.com/watch?v=hD7jsNkgie4&t=873s
// 
// A Binary tree with that has no more than 2 children, where
//   the left subtree contain nodes that are less than their parent node
//   and right subtree contain nodes that are greater than their parent, and
//   their subtrees must also be a binary search tree.

// Sorted data in a tree.
// Better than using a sorted array, because complexity of Insert, Delete are log(n).
// If you try to insert into a vector or array in the middle, it's O(n), because
// you'll need to shift and copy all elements to the right. Because the data is sorted, but it's not linear,
// the BST provides the same binary search functionality of an array but can be applied to Insert/Delete.
// You are log(n)'n the data in half per subtree, and insert/delete doesn't require shift and copy, 
// so it's just log(n) for insertion/deletion
// Maintains sorted elements, you have all advantages of data being sorted.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node* insert(Node* head, int data)
{
    if (head == nullptr)
        return new Node(data);
    if (head->data > data)
        head->left = insert(head->left, data);
    else
        head->right = insert(head->right, data);

    return head;
}

void printInOrder(Node* head)
{
    if (head == NULL)
        return;
    printInOrder(head->left);
    cout << head->data << " ";
    printInOrder(head->right);
}

int main()
{
    int totalNodes, value;
    cin >> totalNodes;
    cin >> value;
    totalNodes--; // I've already taken one value, need to reduce totalNodes

    Node* head = insert(nullptr, value); // insert initial head or root Node
    while (totalNodes != 0) // totalNodes != 0;
    {
        cin >> value;
        insert(head, value);
        totalNodes--;
    }

    printInOrder(head);
    
    system("pause");
}

// 6, 5,2,3,1,9,7