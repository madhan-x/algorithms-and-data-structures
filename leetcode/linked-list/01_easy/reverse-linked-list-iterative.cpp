/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        // Empty list or single node
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        // Reverse the links one by one
        while(curr != nullptr)
        {
            // Store next node
            next = curr->next;

            // Reverse current link
            curr->next = prev;

            // Move pointers forward
            prev = curr;
            curr = next;
        }

        // 'prev' becomes the new head
        return prev;
    }
};

/*
Problem:
LeetCode 206 - Reverse Linked List

Approach:
1. Initialize three pointers: prev, curr, and next.
2. Store the next node.
3. Reverse the current node's link.
4. Move all pointers one step forward.
5. Continue until the list is fully reversed.

Pattern:
Linked List + Three Pointers

Time Complexity: O(n)

Space Complexity: O(1)
*/
