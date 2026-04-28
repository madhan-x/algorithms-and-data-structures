#include<iostream>
using namespace std;

// Singly Linked List - Creation & Traversal
// Approach:
// - Create nodes dynamically
// - Link them using next pointer
// - Traverse using a temporary pointer
// Time Complexity: O(n)
// Space Complexity: O(n)

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head->next = second;    
    second->next = third;

    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
