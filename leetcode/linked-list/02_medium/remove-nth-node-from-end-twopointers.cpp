#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node helps when the head itself needs to be removed.
        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast n + 1 steps ahead.
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end.
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow is now just before the node to delete.
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;

        delete nodeToDelete;

        return dummy.next;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr) {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << endl;
}

int main() {
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    Solution solution;
    head = solution.removeNthFromEnd(head, n);

    cout << "After removing " << n
         << "nd node from the end: ";

    printList(head);

    // Free remaining nodes.
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
