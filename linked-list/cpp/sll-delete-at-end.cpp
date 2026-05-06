#include<iostream>
using namespace std;

/*
🔗 Singly Linked List - Delete Last Node

🧠 Approach:
- If list is empty → nothing to delete
- If only one node → delete head
- Otherwise:
    traverse till second last node
    delete last node
    make second last node point to NULL

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(1)
*/

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

// Insert at end
void insertAtEnd(Node* &head, int val)
{
    Node* n = new Node(val);

    if(head == NULL)
    {
        head = n;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

// Delete last node
void deleteLast(Node* &head)
{
    if(head == NULL)
    {
        cout << "List is empty";
        return;
    }

    // Only one node
    if(head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    // Reach second last node
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Display list
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

    for(int i = 0; i < n; i++)
    {
        cin >> val;
        insertAtEnd(head, val);
    }

    cout << "Linked List: ";
    display(head);

    deleteLast(head);

    cout << "\nAfter deleting last node: ";
    display(head);

    return 0;
}
