#include<iostream>
using namespace std;

/*
🔗 Singly Linked List - Delete at Beginning

🧠 Approach:
- If list is empty → nothing to delete
- Store current head in temp
- Move head to next node
- Delete old head (temp)

⏱️ Time Complexity: O(1)
📦 Space Complexity: O(1)
*/

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert at End (for building list)
void insertAtEnd(Node* &head, int val) {
    Node* newNode = new Node(val);

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete first node
void deleteAtBeginning(Node* &head) {
    if(head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;   // store old head
    head = head->next;   // move head forward
    delete temp;         // free memory
}

// Display list
void display(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for(int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(head, val);
    }

    cout << "Original List:\n";
    display(head);

    deleteAtBeginning(head);

    cout << "After deleting first node:\n";
    display(head);

    return 0;
}
