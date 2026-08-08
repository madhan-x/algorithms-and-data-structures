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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        ListNode* mainHeadA = headA;
        ListNode* mainHeadB = headB;

        while(headA != headB)
        {
            if(headA == nullptr)
                headA = mainHeadB;
            else
                headA = headA->next;

            if(headB == nullptr)
                headB = mainHeadA;
            else
                headB = headB->next;
        }

        return headA;
    }
};

int main()
{
    Solution obj;

    // Common part
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    // List A
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    // List B
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    ListNode* ans = obj.getIntersectionNode(headA, headB);

    if(ans != nullptr)
        cout << "Intersection Node = " << ans->val;
    else
        cout << "No Intersection";

    return 0;
}

/*
Problem:
LeetCode 160 - Intersection of Two Linked Lists

Approach:
1. Start one pointer from each list.
2. When a pointer reaches the end,
   move it to the head of the other list.
3. Both pointers travel the same total distance.
4. They either meet at the intersection node
   or both become nullptr.

Pattern:
Two Pointers

Time Complexity: O(n + m)

Space Complexity: O(1)
*/
