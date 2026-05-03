#include<iostream>
using namespace std;

/*
🔗 Singly Linked List - Insert at End

🧠 Approach:
- Create a new node
- If list is empty → head = new node
- Else traverse to last node
- Link last node to new node

⏱️ Time Complexity: O(n)
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

// Insert at End
void insertAtEnd(Node* &head, int val) {
    Node* newNode = new Node(val);

    // If list is empty
    if(head == NULL) {
        head = newNode;
        return;
    }

    // Traverse to last node
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display Linked List
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
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(head, val);
    }

    cout << "Linked List: ";
    display(head);

    return 0;
}
