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
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect whether a cycle exists
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            // Slow and fast meet inside the cycle
            if(slow == fast)
            {
                // Phase 2:
                // Move one pointer back to the head
                slow = head;

                // Move both pointers one step at a time.
                // Their meeting point is the cycle's starting node.
                while(slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        // No cycle exists
        return nullptr;
    }
};

int main()
{
    Solution obj;

    /*
        Create:

        3 -> 2 -> 0 -> -4
             ^         |
             |_________|

        Cycle starts at node 2.
    */

    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create the cycle
    head->next->next->next->next = head->next;

    ListNode* cycleStart = obj.detectCycle(head);

    if(cycleStart != nullptr)
    {
        cout << "Cycle starts at node with value: "
             << cycleStart->val;
    }
    else
    {
        cout << "No cycle";
    }

    return 0;
}

/*
Problem:
LeetCode 142 - Linked List Cycle II

Approach:
1. Use Floyd's Slow & Fast Pointer algorithm.
2. If slow and fast meet, a cycle exists.
3. Move slow back to the head.
4. Move slow and fast one step at a time.
5. Their next meeting point is the beginning of the cycle.

Pattern:
Floyd's Cycle Detection + Slow & Fast Pointers

Time Complexity: O(n)

Space Complexity: O(1)
*/
