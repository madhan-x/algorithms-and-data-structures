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
    ListNode* oddEvenList(ListNode* head)
    {
        // Empty list or only one node
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }

        // Initialize odd and even pointers
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        // Rearrange odd and even nodes
        while(even != nullptr && even->next != nullptr)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        // Attach even list after odd list
        odd->next = evenHead;

        return head;
    }
};

// Display Linked List
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
    Solution obj;

    int n;
    cin >> n;

    if(n == 0)
    {
        return 0;
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

    head = obj.oddEvenList(head);

    cout << "Odd-Even Rearranged List: ";
    display(head);

    return 0;
}

/*
Problem:
LeetCode 328 - Odd Even Linked List

Approach:
1. Maintain separate pointers for odd and even indexed nodes.
2. Rearrange the next pointers to build two lists.
3. Keep the head of the even list.
4. Attach the even list after the odd list.

Pattern:
Linked List + Two Pointers

Time Complexity: O(n)

Space Complexity: O(1)
*/
