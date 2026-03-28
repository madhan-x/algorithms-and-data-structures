#include <stdio.h>
#include <stdlib.h>

// Find middle element of singly linked list using slow & fast pointers
// Approach: 
// - Slow pointer moves 1 step
// - Fast pointer moves 2 steps
// - When fast reaches end, slow is at middle
// Time Complexity: O(n)
// Space Complexity: O(1)

// Define Node
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Find middle
struct Node* findMiddle(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Print list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main
int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printList(head);

    struct Node* middle = findMiddle(head);

    printf("Middle element: %d\n", middle->data);

    return 0;
}
