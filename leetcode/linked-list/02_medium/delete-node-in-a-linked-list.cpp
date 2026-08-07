#include <iostream>
using namespace std;

// Definition for singly-linked list
class ListNode
{
public:
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

class Solution
{
public:
    void deleteNode(ListNode* node)
    {
        // Copy the value of the next node
        node->val = node->next->val;

        // Store the duplicate node
        ListNode* temp = node->next;

        // Skip the next node
        node->next = node->next->next;

        // Free memory
        delete temp;
    }
};

// Display Linked List
void display(ListNode* head)
{
    while(head != nullptr)
    {
        cout << head->val;

        if(head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main()
{
    Solution obj;

    // Sample List:
    // 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Before Deletion: ";
    display(head);

    // Delete node with value 5
    obj.deleteNode(head->next);

    cout << "After Deletion : ";
    display(head);

    return 0;
}

/*
Problem:
LeetCode 237 - Delete Node in a Linked List

Approach:
1. Copy the value of the next node into the current node.
2. Skip the next node.
3. Delete the skipped node to free memory.
4. Since we don't have access to the previous node,
   we modify the current node instead.

Pattern:
Linked List

Time Complexity: O(1)

Space Complexity: O(1)
*/
