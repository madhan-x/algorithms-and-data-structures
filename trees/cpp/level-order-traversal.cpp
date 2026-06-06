#include <iostream>
#include <queue>
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

// Level Order Traversal (BFS)
void levelOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left)
        {
            q.push(curr->left);
        }

        if(curr->right)
        {
            q.push(curr->right);
        }
    }
}

int main()
{
    Node* root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(50);

    root->left->left = new Node(30);
    root->left->right = new Node(40);

    root->right->right = new Node(60);

    levelOrder(root);

    return 0;
}
