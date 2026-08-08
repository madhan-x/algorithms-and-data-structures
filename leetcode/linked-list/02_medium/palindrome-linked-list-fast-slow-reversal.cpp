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
    bool isPalindrome(ListNode* head)
    {
        // Empty list or single node is always a palindrome
        if(head == nullptr || head->next == nullptr)
        {
            return true;
        }

        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while(curr != nullptr)
        {
            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // Step 3: Compare first half with reversed second half
        ListNode* left = head;
        ListNode* right = prev;

        while(right != nullptr)
        {
            if(left->val != right->val)
            {
                return false;
            }

            left = left->next;
            right = right->next;
        }

        return true;
    }
};

// Create a linked list from input
ListNode* createList(int n)
{
    if(n == 0)
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
    Solution obj;

    int n;
    cin >> n;

    ListNode* head = createList(n);

    if(obj.isPalindrome(head))
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not a Palindrome";
    }

    return 0;
}

/*
Problem:
LeetCode 234 - Palindrome Linked List

Approach:
1. Use slow and fast pointers to find the middle.
2. Reverse the second half of the linked list.
3. Compare the first half with the reversed second half.
4. If every value matches, the list is a palindrome.

Pattern:
Slow & Fast Pointers + Linked List Reversal

Time Complexity: O(n)

Space Complexity: O(1)
*/
