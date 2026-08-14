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
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        // Find the total number of nodes
        int n = 0;
        ListNode* curr = head;

        while(curr != nullptr)
        {
            n++;
            curr = curr->next;
        }

        // Minimum number of nodes in each part
        int size = n / k;

        // Number of parts that get one extra node
        int extra = n % k;

        vector<ListNode*> ans;

        curr = head;

        for(int i = 0; i < k; i++)
        {
            // Start with the minimum part size
            int partSize = size;

            // Distribute the extra nodes to the first parts
            if(extra > 0)
            {
                partSize++;
                extra--;
            }

            // Store the beginning of this part
            ListNode* partHead = curr;

            // Move to the last node of this part
            for(int j = 1; j < partSize && curr != nullptr; j++)
            {
                curr = curr->next;
            }

            // Disconnect this part from the remaining list
            if(curr != nullptr)
            {
                ListNode* nextPart = curr->next;
                curr->next = nullptr;
                curr = nextPart;
            }

            ans.push_back(partHead);
        }

        return ans;
    }
};

// Create a linked list
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

// Display one linked-list part
void display(ListNode* head)
{
    if(head == nullptr)
    {
        cout << "[]";
        return;
    }

    cout << "[";

    while(head != nullptr)
    {
        cout << head->val;

        if(head->next != nullptr)
        {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << "]";
}

int main()
{
    int n;
    cin >> n;

    ListNode* head = createList(n);

    int k;
    cin >> k;

    Solution obj;

    vector<ListNode*> ans = obj.splitListToParts(head, k);

    for(int i = 0; i < k; i++)
    {
        cout << "Part " << i + 1 << ": ";
        display(ans[i]);
        cout << endl;
    }

    return 0;
}

/*
Problem:
LeetCode 725 - Split Linked List in Parts

Example:
Input:
8
1 2 3 4 5 6 7 8
3

Output:
Part 1: [1 -> 2 -> 3]
Part 2: [4 -> 5 -> 6]
Part 3: [7 -> 8]

Approach:
1. Count the total number of nodes.
2. Calculate the minimum size of each part using n / k.
3. Calculate how many extra nodes remain using n % k.
4. Give one extra node to each of
