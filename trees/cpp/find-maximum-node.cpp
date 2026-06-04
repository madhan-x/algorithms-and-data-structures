#include <iostream>
#include <climits>
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

int maxi = INT_MIN;

// Find maximum value in the tree
void findMax(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    if(root->data > maxi)
    {
        maxi = root->data;
    }

    findMax(root->left);
    findMax(root->right);
}

int main()
{
    Node* root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    findMax(root);

    cout << "Maximum Value: " << maxi;

    return 0;
}
