#include<iostream>
using namespace std;

/*
♻️ Circular Linked List - Insert at Beginning

🧠 Idea:
- Last node points back to head
- To insert at beginning:
    1. Create new node
    2. Traverse to last node
    3. Link last node to new node
    4. New node points to old head
    5. Move head to new node

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

// Insert at beginning
void insertAtBegin(Node* &head, int val)
{
    Node* n = new Node(val);

    // Empty list
    if(head == NULL)
    {
        head = n;
        n->next = head;
        return;
    }

    Node* temp = head;

    // Reach last node
    while(temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;
}

// Display circular linked list
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

        insertAtBegin(head, val);
    }

    cout << "\nCircular Linked List:\n";
    display(head);

    return 0;
}
