#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
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
    void reorderList(ListNode* head)
    {
        // Empty list or single node needs no changes
        if(head == nullptr || head->next == nullptr)
        {
            return;
        }

        // 1. Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Separate the list into two halves
        ListNode* curr = slow->next;
        slow->next = nullptr;

        // 3. Reverse the second half
        ListNode* prev = nullptr;

        while(curr != nullptr)
        {
            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // 4. Merge the two halves alternately
        ListNode* first = head;
        ListNode* second = prev;

        while(second != nullptr)
        {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};

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

    if(n <= 0)
    {
        return 0;
    }

    vector<int> values(n);

    for(int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    // Create the linked list
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;

    for(int i = 1; i < n; i++)
    {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }

    Solution obj;

    obj.reorderList(head);

    cout << "Reordered List: ";
    display(head);

    return 0;
}

/*
Problem:
LeetCode 143 - Reorder List

Example:
Input:
5
1 2 3 4 5

Output:
Reordered List: 1 -> 5 -> 2 -> 4 -> 3

Approach:
1. Find the middle using slow and fast pointers.
2. Split the linked list into two halves.
3. Reverse the second half.
4. Merge the first and reversed second halves alternately.

Pattern:
Slow & Fast Pointers + Linked List Reversal + Two Pointers

Time Complexity: O(n)

Space Complexity: O(1)
*/
