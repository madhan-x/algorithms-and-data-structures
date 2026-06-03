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

int sum = 0;

// Preorder traversal to calculate sum
void preorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    // Add current node value
    sum += root->data;

    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node* root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(50);

    preorder(root);

    cout << "Sum = " << sum;

    return 0;
}
