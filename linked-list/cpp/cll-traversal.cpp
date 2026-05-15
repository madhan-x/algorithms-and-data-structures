#include <iostream>
using namespace std;

// Node class for Circular Linked List
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
        newNode->next = head;
        return;
    }

    Node* temp = head;

    // Traverse to last node
    while(temp->next != head)
    {
        temp = temp->next;
    }

    // Connect last node to new node
    temp->next = newNode;

    // Connect new node back to head
    newNode->next = head;
}

// Function to display Circular Linked List
void traversal(Node* head)
{
    // If list is empty
    if(head == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node* temp = head;

    // Traversing CLL using do-while
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    while(temp != head);

    cout << "(head)";
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

    cout << "\nCircular Linked List Traversal:\n";
    traversal(head);

    return 0;
}
