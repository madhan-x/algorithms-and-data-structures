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
    int getDecimalValue(ListNode* head)
    {
        int ans = 0;

        while(head != nullptr)
        {
            // Shift existing binary digits left
            // Multiplying by 2 is equivalent to a left shift
            ans = ans * 2;

            // Add the current binary digit
            ans += head->val;

            head = head->next;
        }

        return ans;
    }
};

// Create linked list from input
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

int main()
{
    int n;
    cin >> n;

    ListNode* head = createList(n);

    Solution obj;

    cout << obj.getDecimalValue(head);

    return 0;
}

/*
Problem:
LeetCode 1290 - Convert Binary Number in a Linked List to Integer

Example:
Input:
4
1 0 1 1

Output:
11

Approach:
For every binary digit:
1. Multiply the current answer by 2.
2. Add the current binary digit.
3. Move to the next node.

For example:

1 → 0 → 1 → 1

ans = 0
ans = 0 * 2 + 1 = 1
ans = 1 * 2 + 0 = 2
ans = 2 * 2 + 1 = 5
ans = 5 * 2 + 1 = 11

Pattern:
Binary Accumulation

Time Complexity: O(n)

Space Complexity: O(1)
*/
