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

// Calculate height of binary tree
int height(Node* root)
{
    // Empty tree
    if(root == NULL)
    {
        return 0;
    }

    // Height of left subtree
    int leftHeight = height(root->left);

    // Height of right subtree
    int rightHeight = height(root->right);

    // Return larger height + current node
    return 1 + max(leftHeight, rightHeight);
}

int main()
{
    Node* root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->right->right = new Node(50);

    cout << "Height of Tree: "
         << height(root);

    return 0;
}
