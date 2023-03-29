// =============================================================
// Julien Savary
// CS 1D
// Professor Lebowitz
// =============================================================
// Assignment: 4
// =============================================================
// Description:
//
// Implement a binary tree using an array, a vector or linked list.
// (Note: duplicates are allowed in a binary tree)

// Store the following elements using the properties of a binary
// search tree.

// 12, 24, 49, 9, 59, 288, 19, 13, 888, 77, 25, 109, 55, 118, 89, 33,
// 1001, 18, 44, 88

// Perform the in-order, post-order, pre-order, breadth-first
// traversals.

// In addition to the traversals, develop software to print out the
// binary tree by level. Develop software to show the parent-
// child relationship for all the nodes of the tree.
//
// =============================================================
// File: binaryTrees.cpp
// =============================================================
#include <iostream>
using namespace std;

class binaryTree
{
private:
    struct TreeNode
    {
        int value;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int value, TreeNode *left = NULL, TreeNode *right = NULL)
        {
            this->value = value;
            this->left = left;
            this->right = right;
        }
    };

    TreeNode *root;

    // inserting values into the tree
    void insert(int value, TreeNode *&tree)
    {
        // if the tree is empty, create a new node
        // (BASE CASE 1: the address is null)
        if (tree == NULL)
        {
            tree = new TreeNode(value);
        }
        // if the value is already in the tree, do nothing
        // (BASE CASE 2: the value is already in the tree)
        else if (value == tree->value)
        {
            return;
        }
        // if the value is less than the current node, go left
        else if (value < tree->value)
        {
            insert(value, tree->left);
        }
        // if the value is greater than the current node, go right
        else
        {
            insert(value, tree->right);
        }
    }

    // displaying the tree in order
    void displayInOrder(TreeNode *tree)
    {
        if (tree != NULL)
        {
            displayInOrder(tree->left);
            cout << tree->value << endl;
            displayInOrder(tree->right);
        }
    }

    // displaying the tree in pre order
    void displayPreOrder(TreeNode *tree)
    {
        if (tree != NULL)
        {
            cout << tree->value << endl;
            displayPreOrder(tree->left);
            displayPreOrder(tree->right);
        }
    }

    // displaying the tree in post order
    void displayPostOrder(TreeNode *tree)
    {
        if (tree != NULL)
        {
            displayPostOrder(tree->left);
            displayPostOrder(tree->right);
            cout << tree->value << endl;
        }
    }

    // displaying the tree in breadth first
    void displayBreadthFirst(TreeNode *tree)
    {
        if (tree != NULL)
        {
            cout << tree->value << endl;
            displayBreadthFirst(tree->left);
            displayBreadthFirst(tree->right);
        }
    }

    // displaying the tree by level
    // not forgetting any nodes
    // and showing the parent-child relationships
    // (i.e. the left and right children of each node)
    // this is a recursive function that continues
    // until the tree is empty (BASE CASE)
    void displayByLevel(TreeNode *tree)
    {
        // if the tree is empty, do nothing
        if (tree == NULL)
        {
            return;
        }
        // if the tree is not empty, display the value
        else
        {
            cout << tree->value << endl;
        }
        // if the two childs are not empty (i.e. the node has two children)
        // display the parent-child relationship
        if (tree->left != NULL && tree->right != NULL)
        {
            cout << tree->value << " is the parent of " << tree->left->value << " and " << tree->right->value << endl;
        }
        // if the left child is not empty, display the value
        if (tree->left != NULL)
        {
            cout << tree->value << " is the parent of " << tree->left->value << endl;
        }
        // if the right child is not empty, display the value
        if (tree->right != NULL)
        {
            cout << tree->value << " is the parent of " << tree->right->value << endl;
        }
        // recursively call the function
        displayByLevel(tree->left);
        displayByLevel(tree->right);
    }

public:
    // constructors (important in order to avoid segmentation errors)
    binaryTree()
    {
        root = NULL;
    }

    void insert(int value)
    {
        insert(value, root);
    }

    void showInOrder()
    {
        displayInOrder(root);
    }
    void showPreOrder()
    {
        displayPreOrder(root);
    }
    void showPostOrder()
    {
        displayPostOrder(root);
    }
    void showBreadthFirst()
    {
        displayBreadthFirst(root);
    }

    void showByLevel()
    {
        displayByLevel(root);
    }
};

int main()
{
    binaryTree tree;

    tree.insert(12);
    tree.insert(24);
    tree.insert(49);
    tree.insert(9);
    tree.insert(59);
    tree.insert(288);
    tree.insert(19);
    tree.insert(13);
    tree.insert(888);
    tree.insert(77);
    tree.insert(25);
    tree.insert(109);
    tree.insert(55);
    tree.insert(118);
    tree.insert(89);
    tree.insert(33);
    tree.insert(1001);
    tree.insert(18);
    tree.insert(44);
    tree.insert(88);

    cout << "In Order:" << endl;
    tree.showInOrder();
    cout << endl;

    cout << "Pre Order:" << endl;
    tree.showPreOrder();
    cout << endl;

    cout << "Post Order:" << endl;
    tree.showPostOrder();
    cout << endl;

    cout << "Breadth First:" << endl;
    tree.showBreadthFirst();
    cout << endl;

    cout << "By Level:" << endl;
    tree.showByLevel();
    cout << endl;

    return 0;
}
// =============================================================
// Output:
// =============================================================
//
// This output is what I have for now. In order is correct,
// pre order is correct, post order is correct, breadth first
// is correct, but by level is not correct. I assume that the
// problem is in the displayByLevel function, but I am not sure
// how to fix it. Let me know if you can. Thank you Professor!
//
// =============================================================
/* 
In Order:
9
12
13
18
19
24
25
33
44
49
55
59
77
88
89
109
118
288
888
1001

Pre Order:
12
9
24
19
13
18
49
25
33
44
59
55
288
77
109
89
88
118
888
1001

Post Order:
9
18
13
19
44
33
25
55
88
89
118
109
77
1001
888
288
59
49
24
12

Breadth First:
12
9
24
19
13
18
49
25
33
44
59
55
288
77
109
89
88
118
888
1001

By Level:
12
12 is the parent of 9 and 24
12 is the parent of 9
12 is the parent of 24
9
24
24 is the parent of 19 and 49
24 is the parent of 19
24 is the parent of 49
19
19 is the parent of 13
13
13 is the parent of 18
18
49
49 is the parent of 25 and 59
49 is the parent of 25
49 is the parent of 59
25
25 is the parent of 33
33
33 is the parent of 44
44
59
59 is the parent of 55 and 288
59 is the parent of 55
59 is the parent of 288
55
288
288 is the parent of 77 and 888
288 is the parent of 77
288 is the parent of 888
77
77 is the parent of 109
109
109 is the parent of 89 and 118
109 is the parent of 89
109 is the parent of 118
89
89 is the parent of 88
88
118
888
888 is the parent of 1001
1001
[1] + Done                       "/usr/bin/gdb" --interpreter=mi --tty=${DbgTerm} 0<"/tmp/Microsoft-MIEngine-In-iuncibca.gzo" 1>"/tmp/Microsoft-MIEngine-Out-v4fvjxqn.rfx"
*/