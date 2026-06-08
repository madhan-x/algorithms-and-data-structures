#include <iostream>
#include <algorithm>
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

// Convert tree into its mirror image
void mirror(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    // Swap left and right children
    swap(root->left, root->right);

    // Mirror left subtree
    mirror(root->left);

    // Mirror right subtree
    mirror(root->right);
}

// Preorder traversal
void preorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node* root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(40);

    root->left->left = new Node(30);
    root->right->right = new Node(50);

    cout << "Before Mirror: ";
    preorder(root);
    cout << endl;

    mirror(root);

    cout << "After Mirror: ";
    preorder(root);

    return 0;
}
