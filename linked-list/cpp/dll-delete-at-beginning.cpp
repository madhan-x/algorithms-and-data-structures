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

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete beginning node
void deleteBegin(Node* &head)
{
    // If list is empty
    if(head == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node* toDelete = head;

    // If only one node exists
    if(head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }

    delete toDelete;
}

// Function to display DLL
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

    // Creating DLL using user input
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
