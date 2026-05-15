#include <iostream>
using namespace std;

// Node class for Doubly Linked List
class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// Function to insert node at end
void insertEnd(Node* &head, int val)
{
    Node* newNode = new Node(val);

    // If list is empty
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    // Traverse to last node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    // Connect new node
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to traverse DLL
void traversal(Node* head)
{
    Node* temp = head;

    // Print all nodes
    while(temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL";
}

int main()
{
    Node* head = NULL;

    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    // Taking user input
    for(int i = 0; i < n; i++)
    {
        cout << "Enter data: ";
        cin >> val;

        insertEnd(head, val);
    }

    cout << "\nDoubly Linked List Traversal:\n";
    traversal(head);

    return 0;
}
