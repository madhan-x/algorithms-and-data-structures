#include<iostream>
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

// Find minimum value in BST (Recursive)
int findMin(Node* root)
{
    if(root == NULL)
    {
        return -1;
    }

    // Leftmost node found
    if(root->left == NULL)
    {
        return root->data;
    }

    return findMin(root->left);
}

int main()
{
    Node* root = new Node(20);

    root->left = new Node(10);
    root->right = new Node(30);

    root->left->left = new Node(5);
    root->left->right = new Node(15);

    root->right->left = new Node(25);
    root->right->right = new Node(40);

    cout << "Minimum Element: " << findMin(root);

    return 0;
}
