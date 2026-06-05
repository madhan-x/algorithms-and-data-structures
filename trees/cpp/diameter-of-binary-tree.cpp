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

int diameter = 0;

// Returns height and updates diameter
int height(Node* root)
{
    // Base case
    if(root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Diameter passing through current node
    diameter = max(diameter, 1 + leftHeight + rightHeight);

    // Return height of current subtree
    return 1 + max(leftHeight, rightHeight);
}

int main()
{
    Node* root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(50);

    root->left->left = new Node(30);
    root->left->right = new Node(40);

    root->right->right = new Node(60);

    height(root);

    cout << "Diameter = " << diameter;

    return 0;
}
