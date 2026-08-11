#include <iostream>
#include <vector>
using namespace std;

/*
Problem:
LeetCode 203 - Remove Linked List Elements

Example:

Input:
7
1 2 6 3 4 5 6
6

Output:
1 -> 2 -> 3 -> 4 -> 5
*/

struct ListNode
{
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
    ListNode* removeElements(ListNode* head, int val)
    {
        // Create a dummy node before the actual head.
        // This makes deleting the head node easier.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy;

        // Traverse the list
        while(curr->next != nullptr)
        {
            // If the next node contains the target value
            if(curr->next->val == val)
            {
                ListNode* temp = curr->next;

                // Skip the node
                curr->next = curr->next->next;

                // Free the removed node
                delete temp;
            }
            else
            {
                // Move forward only when no deletion happens
                curr = curr->next;
            }
        }

        // Store the new head
        ListNode* newHead = dummy->next;

        delete dummy;

        return newHead;
    }
};

// Create a linked list from input
ListNode* createList(int n)
{
    if(n <= 0)
    {
        return nullptr;
    }

    int value;
    cin >> value;

    ListNode* head = new ListNode(value);
    ListNode* tail = head;

    for(int i = 1; i < n; i++)
    {
        cin >> value;

        tail->next = new ListNode(value);
        tail = tail->next;
    }

    return head;
}

// Display the linked list
void display(ListNode* head)
{
    while(head != nullptr)
    {
        cout << head->val;

        if(head->next != nullptr)
        {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    ListNode* head = createList(n);

    int val;
    cin >> val;

    Solution obj;

    head = obj.removeElements(head, val);

    display(head);

    return 0;
}

/*
Approach:
1. Create a dummy node before the head.
2. Traverse the linked list.
3. If the next node contains val, remove it.
4. Otherwise move to the next node.
5. Return the new head.

Pattern:
Dummy Node + Linked List Traversal

Time Complexity: O(n)

Space Complexity: O(1)
*/
