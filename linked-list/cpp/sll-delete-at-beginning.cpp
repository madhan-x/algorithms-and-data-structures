#include <iostream>
using namespace std;

// Node class for Singly Linked List
class Node
{
public:
    int data;
    Node* next;

    // Constructor
    Node(int val)
    {
        data = val;
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

    temp->next = newNode;
}

// Function to delete first node
void deleteBegin(Node* &head)
{
    // If list is empty
    if(head == NULL)
    {
        cout << "List is empty";
        return;
    }

    // Store current head
    Node* toDelete = head;

    // Move head to next node
    head = head->next;

    // Delete old head
    delete toDelete;
}

// Function to display SLL
void display(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " -> ";
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

        insertEnd(head, val);
    }

    cout << "\nBefore deletion:\n";
    display(head);

    // Delete first node
    deleteBegin(head);

    cout << "\nAfter deleting beginning node:\n";
    display(head);

    return 0;
}
