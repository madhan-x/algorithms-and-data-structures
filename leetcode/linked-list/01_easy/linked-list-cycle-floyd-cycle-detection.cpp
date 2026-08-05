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
    bool hasCycle(ListNode* head)
    {
        // Empty list or single node cannot have a cycle
        if(head == nullptr || head->next == nullptr)
        {
            return false;
        }

        // Initialize slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            // Move slow by one step
            slow = slow->next;

            // Move fast by two steps
            fast = fast->next->next;

            // Cycle detected
            if(slow == fast)
            {
                return true;
            }
        }

        // No cycle found
        return false;
    }
};

int main()
{
    Solution obj;

    // Create sample linked list:
    // 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create cycle: last node points to node with value 2
    head->next->next->next->next = head->next;

    if(obj.hasCycle(head))
    {
        cout << "Cycle Detected";
    }
    else
    {
        cout << "No Cycle";
    }

    return 0;
}

/*
Problem:
LeetCode 141 - Linked List Cycle

Approach:
1. Use two pointers: slow and fast.
2. Slow moves one step at a time.
3. Fast moves two steps at a time.
4. If they meet, a cycle exists.
5. If fast reaches nullptr, there is no cycle.

Pattern:
Floyd's Cycle Detection (Slow & Fast Pointers)

Time Complexity: O(n)

Space Complexity: O(1)
*/
