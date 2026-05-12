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

// Function to insert a node at the beginning
void insertBegin(Node* &head, int val)
{
    // Create new node
    Node* newNode = new Node(val);

    // If list is not empty
    if(head != NULL)
    {
        newNode->next = head;
        head->prev = newNode;
    }

    // Move head to new node
    head = newNode;
}

// Function to display Doubly Linked List
void display(Node* head)
{
    Node* temp = head;

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

    // Taking input from user
    for(int i = 0; i < n; i++)
    {
        cout << "Enter data: ";
        cin >> val;

        insertBegin(head, val);
    }

    cout << "\nDoubly Linked List:\n";
    display(head);

    return 0;
}
