// Adelson, Velski, & Landis Tree
// AVL is a Self-Balancing Binary Search Tree

// Solves problem of Binary Search Tree 
// BST have issues when data is already sorted, detoriates to a linked list
// Finds the difference of subtree heights
// Balancing Factor (BF) = Height of left subtree - Height of right subtree
// BF = H(LST) - H(RST)
// https://www.youtube.com/watch?v=2ScmZ0_dxJc&list=PLIY8eNdw5tW_zX3OCzX7NJ8bL1p6pWfgG&index=89

#include<iostream>
#define SPACE 10
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class AVLTree {
public:
    TreeNode* root;
    AVLTree() {
        root = NULL;
    }
    bool isTreeEmpty() {
        if (root == NULL) {
            return true;
        }
        else {
            return false;
        }
    }
    // Get Height  
    int height(TreeNode* r) {
        if (r == NULL)
            return -1;
        else {
            /* compute the height of each subtree */
            int lheight = height(r->left);
            int rheight = height(r->right);

            /* use the larger one */
            if (lheight > rheight)
                return (lheight + 1);
            else 
                return (rheight + 1);
        }
    }

    // Get Balance factor of node N  
    int getBalanceFactor(TreeNode* n) {
        if (n == NULL)
            return -1;
        return height(n->left) - height(n->right);
    }
    
    TreeNode* rightRotate(TreeNode* y) { // y is the root node
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        // Perform rotation  
        x->right = y;
        y->left = T2;

        return x;
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right; // change x to the root, and make make old root(y), the right child of x.
        TreeNode* T2 = y->left;

        // Perform rotation  
        y->left = x;
        x->right = T2;

        return y;
    }

    TreeNode* insert(TreeNode* r, TreeNode* new_node) {
        if (r == NULL) {
            r = new_node;
            cout << "Value inserted successfully" << endl;
            return r;
        }

        if (new_node->value < r->value) {
            r->left = insert(r->left, new_node);
        }
        else if (new_node->value > r->value) {
            r->right = insert(r->right, new_node);
        }
        else {
            cout << "No duplicate values allowed!" << endl;
            return r;
        }

        // Perform balancing after the insertion.
        int bf = getBalanceFactor(r);
        // Left Left Case  
        if (bf > 1 && new_node->value < r->left->value)
            return rightRotate(r);

        // Right Right Case  
        if (bf < -1 && new_node->value > r->right->value)
            return leftRotate(r);

        // Left Right Case  
        if (bf > 1 && new_node->value > r->left->value) {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }

        // Right Left Case  
        if (bf < -1 && new_node->value < r->right->value) {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

        /* return the (unchanged) node pointer */
        return r;

    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        /* loop down to find the leftmost leaf */
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    TreeNode* deleteNode(TreeNode* r, int v) {
        // base case 
        if (r == NULL) {
            return NULL;
        }
        // If the key to be deleted is smaller than the root's key, 
        // then it lies in left subtree 
        else if (v < r->value) {
            r->left = deleteNode(r->left, v);
        }
        // If the key to be deleted is greater than the root's key, 
        // then it lies in right subtree 
        else if (v > r->value) {
            r->right = deleteNode(r->right, v);
        }
        // if key is same as root's key, then This is the node to be deleted 
        else {
            // node with only one child or no child 
            if (r->left == NULL) {
                TreeNode* temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL) {
                TreeNode* temp = r->left;
                delete r;
                return temp;
            }
            else {
                // node with two children: Get the inorder successor (smallest 
                // in the right subtree) 
                TreeNode* temp = minValueNode(r->right);
                // Copy the inorder successor's content to this node 
                r->value = temp->value;
                // Delete the inorder successor 
                r->right = deleteNode(r->right, temp->value);
                //deleteNode(r->right, temp->value); 
            }
        }

        int bf = getBalanceFactor(r);
        // Left Left Imbalance/Case or Right rotation 
        if (bf == 2 && getBalanceFactor(r->left) >= 0)
            return rightRotate(r);
            // same as
            // r = rightRotate(r);
            // return r;
        // Left Right Imbalance/Case or LR rotation 
        else if (bf == 2 && getBalanceFactor(r->left) == -1) {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }
        // Right Right Imbalance/Case or Left rotation	
        else if (bf == -2 && getBalanceFactor(r->right) <= -0)
            return leftRotate(r);
        // Right Left Imbalance/Case or RL rotation 
        else if (bf == -2 && getBalanceFactor(r->right) == 1) {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

        return r;
    }

    void print2D(TreeNode* r, int space) {
        if (r == NULL) // Base case  1
            return;
        space += SPACE; // Increase distance between levels   2
        print2D(r->right, space); // Process right child first 3 
        cout << endl;
        for (int i = SPACE; i < space; i++) // 5 
            cout << " "; // 5.1  
        cout << r->value << "\n"; // 6
        print2D(r->left, space); // Process left child  7
    }
    void printPreorder(TreeNode* r) //(current node, Left, Right) 
    {
        if (r == NULL)
            return;
        /* first print data of node */
        cout << r->value << " ";
        /* then recur on left sutree */
        printPreorder(r->left);
        /* now recur on right subtree */
        printPreorder(r->right);
    }

    void printInorder(TreeNode* r) //  (Left, current node, Right)
    {
        if (r == NULL)
            return;
        /* first recur on left child */
        printInorder(r->left);
        /* then print the data of node */
        cout << r->value << " ";
        /* now recur on right child */
        printInorder(r->right);
    }
    void printPostorder(TreeNode* r) //(Left, Right, Root)
    {
        if (r == NULL)
            return;
        // first recur on left subtree 
        printPostorder(r->left);
        // then recur on right subtree 
        printPostorder(r->right);
        // now deal with the node 
        cout << r->value << " ";
    }

    /* Print nodes at a given level */
    void printGivenLevel(TreeNode* r, int level) {
        if (r == NULL)
            return;
        else if (level == 0)
            cout << r->value << " ";
        else // level > 0  
        {
            printGivenLevel(r->left, level - 1);
            printGivenLevel(r->right, level - 1);
        }
    }
    void printLevelOrderBFS(TreeNode* r) {
        int h = height(r);
        for (int i = 0; i <= h; i++)
            printGivenLevel(r, i);
    }

    TreeNode* iterativeSearch(int v) {
        if (root == NULL) {
            return root;
        }
        else {
            TreeNode* temp = root;
            while (temp != NULL) {
                if (v == temp->value) {
                    return temp;
                }
                else if (v < temp->value) {
                    temp = temp->left;
                }
                else {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }

    TreeNode* recursiveSearch(TreeNode* r, int val) {
        if (r == NULL || r->value == val)
            return r;

        else if (val < r->value)
            return recursiveSearch(r->left, val);

        else
            return recursiveSearch(r->right, val);
    }

}; // END of AVL TREE class

int main() {
    AVLTree obj;
    int option, val;

    do {
        cout << "What operation do you want to perform? " <<
            " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal AVL Tree values" << endl;
        cout << "5. Height of Tree" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;
        //Node n1;
        TreeNode* new_node = new TreeNode();

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "AVL INSERT" << endl;
            cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
            cin >> val;
            new_node->value = val;
            obj.root = obj.insert(obj.root, new_node);
            cout << endl;
            break;
        case 2:
            cout << "SEARCH" << endl;
            cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
            cin >> val;
            //new_node = obj.iterativeSearch(val);
            new_node = obj.recursiveSearch(obj.root, val);
            if (new_node != NULL) {
                cout << "Value found" << endl;
            }
            else {
                cout << "Value NOT found" << endl;
            }
            break;
        case 3:
            cout << "DELETE" << endl;
            cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
            cin >> val;
            new_node = obj.recursiveSearch(obj.root, val);
            if (new_node != NULL) {
                obj.root = obj.deleteNode(obj.root, val);
                cout << "Value Deleted" << endl;
            }
            else {
                cout << "Value NOT found" << endl;
            }
            break;
        case 4:
            cout << "PRINT 2D: " << endl;
            obj.print2D(obj.root, 5);
            cout << endl;
            break;
        case 5:
            cout << "TREE HEIGHT" << endl;
            cout << "Height : " << obj.height(obj.root) << endl;
            break;
        case 6:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}

// 1. AVL tree is height balancing BST OR self balancing BST.
// 2. Why BST was not enough ? and we needed balancing BST(AVL Tree)
//   a.Normal BST is having issue when data is sorted or almost sorted(skewed Binary tree).
//   b.Using AVL tree we keep balancing when it becomes non balanced while inserting data.
// 3. AVL tree take the height of left and right sub tree and find the difference(L - R) and 
//      it should be either of { -1, 0, 1 }, called Balance Factor.
// 4. If the balance factor of left and right sub tree is not either of{ -1,0,1 } 
// then tree is balanced using rotation techniques.
//   A.left left - Right Rotation (left imbalance)
//   B.left right - Left and Right Rotation (L-R imbalance)
//   C.right left - Right and Left Rotation (R-L imbalance)
//   D.right right - Left Rotation (right imbalance)

/*

Self balance using rotations
We write the code to re-balance
6 ways of balancing trees.
4 ways use rotations
Example: {10,20,30} - 3 node example
Order on Insertion(4 ways): {30,20,10} | {30,10,20} | {10,20,30} | {10,30,20}

Left_Right rotation: 30,10,20: rotate bottom leaf with parent, left rotation, then...
do a right rotation from the root. 
L-R and R-L imbalanced trees go down a level and switch nodes before doing a rotation on root.
  30
10      // first swap 10 and 20 using left hand rotation
  20    //   30
        //  20
        // 10
        // second, do a right rotation on root, leaving 20 at root, 30 right, and 10 left.

Can subtrees contain bst properties of the root but also be break the 
left-right rules bst if it's 2 levels below the root?
No, all values to the left of the root will always be less, and all values to the right
of the root will always be greater.

When there are more than 3 nodes, multiple subtrees, upon a rotation, and if
you have 2 nodes sharing an edge compare the values of the two, and make one of them a child.

When doing rotations, only be concerned with 3 immediate nodes, all other nodes, subtrees are extras.

After inserting a new node during a sequence, you need to check if tree is balanced.
Ex. 55,66,77,15,11,33,22,35,25,44,88,99

Delete Nodes from AVL tree
3 cases:
* For leaf node - delete the node
* Node with 1 child - Link the parent node parent(n) with this child node child(n) & delete the node(n) in between
* Nodes with 2 children - 
    a.) Find the largest node(nMax) in left subtree
    Replace this node with the node to be deleted.  Delete nMax.
    b.) Find the smallest node(nMin) in the right subtree.
    Replace this node with the node to be deleted.  Delete nMin.
* Then, check for rebalancing. 


Why do you want to use AVL tree over a BST?
* Avg Case of O(log2(n)) v O(n) for worst case in BST.
* Time efficiency
*/

/*  ### AVL Tree Demo ###


class TreeNode
{
public:

    int value;
    TreeNode* leftChild;
    TreeNode* rightChild;

    TreeNode(int v, TreeNode* l, TreeNode* r) : value(v), leftChild(l), rightChild(r) {}
    TreeNode() : value(0), leftChild(NULL), rightChild(NULL){}
}

class AVLTree{

private:
    TreeNode* root;
    // TODO: other variable

public:

    TreeNode* insert(root, value)
    TreeNode* delete(root, value)
    int balanceFactor(root)
    depth-first_search(root)
    breadth-first_search(root)
    print();
    rotateright();
    rotateleft();
    isEmpty();
    getHeight();

}

*/

