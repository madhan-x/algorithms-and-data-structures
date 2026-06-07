#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Check whether two trees are identical
bool isIdentical(Node* root1, Node* root2)
{
    // Both nodes are NULL
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }

    // One node is NULL and the other is not
    if(root1 == NULL || root2 == NULL)
    {
        return false;
    }

    // Data mismatch
    if(root1->data != root2->data)
    {
        return false;
    }

    // Check left and right subtrees
    return isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

int main()
{
    // Tree 1
    Node* root1 = new Node(10);
    root1->left = new Node(20);
    root1->right = new Node(30);

    // Tree 2
    Node* root2 = new Node(10);
    root2->left = new Node(20);
    root2->right = new Node(30);

    if(isIdentical(root1, root2))
    {
        cout << "Trees are Identical";
    }
    else
    {
        cout << "Trees are Not Identical";
    }

    return 0;
}
