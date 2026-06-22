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

int countNodes(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

    return 1 + leftCount + rightCount;
}

int main()
{
    Node* root = new Node(40);

    root->left = new Node(20);
    root->left->left = new Node(10);
    root->left->right = new Node(30);

    root->right = new Node(60);
    root->right->left = new Node(50);
    root->right->right = new Node(70);

    cout << "Total Nodes = " << countNodes(root);

    return 0;
}
