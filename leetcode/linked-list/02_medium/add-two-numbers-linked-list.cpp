#include <iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        // Dummy node to simplify list creation
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry)
        {
            int sum = carry;

            // Add value from first list
            if(l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add value from second list
            if(l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            // Current digit
            int digit = sum % 10;

            temp->next = new ListNode(digit);
            temp = temp->next;

            // Carry for next iteration
            carry = sum / 10;
        }

        return dummy->next;
    }
};

// Print Linked List
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
    Solution obj;

    int n1;
    cin >> n1;

    ListNode *l1 = nullptr, *tail1 = nullptr;

    for(int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;

        if(l1 == nullptr)
        {
            l1 = new ListNode(x);
            tail1 = l1;
        }
        else
        {
            tail1->next = new ListNode(x);
            tail1 = tail1->next;
        }
    }

    int n2;
    cin >> n2;

    ListNode *l2 = nullptr, *tail2 = nullptr;

    for(int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;

        if(l2 == nullptr)
        {
            l2 = new ListNode(x);
            tail2 = l2;
        }
        else
        {
            tail2->next = new ListNode(x);
            tail2 = tail2->next;
        }
    }

    ListNode* ans = obj.addTwoNumbers(l1, l2);

    cout << "Result: ";
    display(ans);

    return 0;
}

/*
Problem:
LeetCode 2 - Add Two Numbers

Approach:
1. Create a dummy node for the result list.
2. Traverse both linked lists simultaneously.
3. Add corresponding digits along with the carry.
4. Create a new node for the current digit.
5. Update the carry.
6. Continue until both lists and carry are exhausted.

Pattern:
Linked List + Simulation

Time Complexity: O(max(n, m))

Space Complexity: O(max(n, m))
*/
