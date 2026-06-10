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

// Insert a node into BST
Node* insertBST(Node* root, int key)
{
    // Position found
    if(root == NULL)
    {
        return new Node(key);
    }

    // Move right
    if(key >= root->data)
    {
        root->right = insertBST(root->right, key);
    }
    // Move left
    else
    {
        root->left = insertBST(root->left, key);
    }

    return root;
}

int main()
{
    Node* root = new Node(20);

    root->left = new Node(10);
    root->right = new Node(30);

    int key;
    cin >> key;

    root = insertBST(root, key);

    return 0;
}
