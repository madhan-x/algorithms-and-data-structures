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

int main()
{
    // Create root node
    Node* root = new Node(10);

    // Create left and right children
    root->left = new Node(20);
    root->right = new Node(30);

    return 0;
}
