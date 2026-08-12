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
    ListNode* swapPairs(ListNode* head)
    {
        // Dummy node makes swapping the first pair easier
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        // Continue while at least two nodes are available
        while(prev->next != nullptr && prev->next->next != nullptr)
        {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swap the two nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev to the end of the swapped pair
            prev = first;
        }

        ListNode* newHead = dummy->next;

        delete dummy;

        return newHead;
    }
};

// Create a linked list
ListNode* createList(int n)
{
    if(n <= 0)
        return nullptr;

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

// Display linked list
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
    int n;
    cin >> n;

    ListNode* head = createList(n);

    Solution obj;

    head = obj.swapPairs(head);

    cout << "After Swapping Pairs: ";
    display(head);

    return 0;
}

/*
Problem:
LeetCode 24 - Swap Nodes in Pairs

Example:
Input:
5
1 2 3 4 5

Output:
2 -> 1 -> 4 -> 3 -> 5

Approach:
1. Use a dummy node before the head.
2. Take two consecutive nodes at a time.
3. Rearrange their next pointers to swap them.
4. Move the previous pointer to the end of the swapped pair.
5. Continue until fewer than two nodes remain.

Pattern:
Dummy Node + Pointer Manipulation

Time Complexity: O(n)

Space Complexity: O(1)
*/
