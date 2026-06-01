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

// Count leaf nodes in a binary tree
int countLeaves(Node* root)
{
    // Empty tree
    if(root == NULL)
    {
        return 0;
    }

    // Leaf node
    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    // Count leaves in left and right subtree
    return countLeaves(root->left) +
           countLeaves(root->right);
}

int main()
{
    Node* root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(50);

    cout << "Leaf Nodes: "
         << countLeaves(root);

    return 0;
}
