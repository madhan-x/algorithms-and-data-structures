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

// Search a value in BST
bool searchBST(Node* root, int key)
{
    // Value not found
    if(root == NULL)
    {
        return false;
    }

    // Value found
    if(root->data == key)
    {
        return true;
    }

    // Search in left subtree
    if(key < root->data)
    {
        return searchBST(root->left, key);
    }

    // Search in right subtree
    return searchBST(root->right, key);
}

int main()
{
    Node* root = new Node(20);

    root->left = new Node(10);
    root->right = new Node(30);

    root->left->left = new Node(5);
    root->left->right = new Node(15);

    int key;
    cin >> key;

    if(searchBST(root, key))
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }

    return 0;
}
