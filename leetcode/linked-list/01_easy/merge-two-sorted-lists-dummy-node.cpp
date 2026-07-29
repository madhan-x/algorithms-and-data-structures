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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        // Dummy node simplifies edge cases
        ListNode dummy;

        // Tail points to the last node of the merged list
        ListNode* tail = &dummy;

        // Compare nodes from both lists
        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        // Attach the remaining nodes
        if(list1)
            tail->next = list1;
        else
            tail->next = list2;

        return dummy.next;
    }
};

/*
Problem:
LeetCode 21 - Merge Two Sorted Lists

Approach:
1. Create a dummy node to simplify merging.
2. Compare the current nodes of both lists.
3. Attach the smaller node to the merged list.
4. Move the corresponding pointer forward.
5. After one list ends, attach the remaining nodes of the other list.

Pattern:
Linked List + Dummy Node + Two Pointers

Time Complexity: O(n + m)

Space Complexity: O(1)
*/
