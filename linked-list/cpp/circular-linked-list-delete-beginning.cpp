#include<iostream>
using namespace std;

/*
♻️ Circular Linked List - Delete from Beginning

🧠 Idea:
- Last node points back to head
- To delete beginning node:
    1. Reach last node
    2. Make last node point to second node
    3. Move head forward
    4. Delete old head

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
void insertEnd(Node* &head, int val)
{
    Node* n = new Node(val);

    if(head == NULL)
    {
        head = n;
        n->next = head;
        return;
    }

    Node* temp = head;

    while(temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

// Delete from beginning
void deleteBegin(Node* &head)
{
    if(head == NULL)
    {
        cout << "List is empty";
        return;
    }

    // Only one node
    if(head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    // Reach last node
    while(temp->next != head)
    {
        temp = temp->next;
    }

    Node* toDelete = head;

    temp->next = head->next;
    head = head->next;

    delete toDelete;
}

// Display
void display(Node* head)
{
    if(head == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node* temp = head;

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

    for(int i = 0; i < n; i++)
    {
        cout << "Enter data: ";
        cin >> val;

        insertEnd(head, val);
    }

    cout << "\nBefore deletion:\n";
    display(head);

    deleteBegin(head);

    cout << "\n\nAfter deleting beginning node:\n";
    display(head);

    return 0;
}
