#include<iostream>
using namespace std;

/*
♻️ Circular Linked List - Delete Last Node

🧠 Idea:
- Last node points back to head
- To delete last node:
    1. Traverse to second last node
    2. Store last node
    3. Point second last node to head
    4. Delete last node

⚠️ Edge Cases:
- Empty list
- Single node list

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

// Delete last node
void deleteEnd(Node* &head)
{
    // Empty list
    if(head == NULL)
    {
        cout << "List is empty";
        return;
    }

    // Single node
    if(head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    // Reach second last node
    while(temp->next->next != head)
    {
        temp = temp->next;
    }

    Node* toDelete = temp->next;

    temp->next = head;

    delete toDelete;
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

    // Create Circular Linked List
    for(int i = 0; i < n; i++)
    {
        cin >> val;

        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* temp = head;

            while(temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }

    cout << "Before deletion:\n";
    display(head);

    deleteEnd(head);

    cout << "\nAfter deleting last node:\n";
    display(head);

    return 0;
}
