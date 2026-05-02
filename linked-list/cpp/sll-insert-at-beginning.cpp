#include<iostream>
using namespace std;

/*
🔗 Singly Linked List - Insert at Beginning

🧠 Approach:
- Create a new node
- Point its next to current head
- Update head to new node

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

// Insert at beginning
void insertAtBeginning(Node* &head, int val) {
    Node* newNode = new Node(val);  // create new node
    newNode->next = head;           // link to old head
    head = newNode;                 // update head
}

// Display linked list
void display(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    int n, value;
    cout << "Enter number of elements: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        insertAtBeginning(head, value);
    }

    cout << "Linked List: ";
    display(head);

    return 0;
}
