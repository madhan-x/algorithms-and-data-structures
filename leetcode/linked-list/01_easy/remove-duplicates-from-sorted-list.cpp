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
    ListNode* deleteDuplicates(ListNode* head)
    {
        // Empty list or single node
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* temp = head;

        while(temp != nullptr && temp->next != nullptr)
        {
            // Duplicate node found
            if(temp->val == temp->next->val)
            {
                ListNode* duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;      // Free memory
            }
            else
            {
                temp = temp->next;
            }
        }

        return head;
    }
};

// Display Linked List
void display(ListNode* head)
{
    while(head != nullptr)
    {
        cout << head->val << " ";
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

    // Create Linked List
    for(int i = 1; i < n; i++)
    {
        cin >> value;
        tail->next = new ListNode(value);
        tail = tail->next;
    }

    head = obj.deleteDuplicates(head);

    cout << "After Removing Duplicates: ";
    display(head);

    return 0;
}

/*
Problem:
LeetCode 83 - Remove Duplicates from Sorted List

Approach:
1. Traverse the sorted linked list.
2. If two consecutive nodes have the same value,
   remove the duplicate node.
3. Otherwise move to the next node.
4. Continue until the end of the list.

Pattern:
Linked List

Time Complexity: O(n)

Space Complexity: O(1)
*/
