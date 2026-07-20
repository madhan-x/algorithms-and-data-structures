/*
 * Problem:    LC 876 - Middle of the Linked List
 * Difficulty: Easy
 * Pattern:    Two Pointers (Slow & Fast)
 * Link:       https://leetcode.com/problems/middle-of-the-linked-list/
 *
 * Approach:   Use a slow and a fast pointer starting at the head.
 *             Advance slow by one step and fast by two steps each
 *             iteration. When fast reaches the end, slow lands exactly
 *             on the middle node. For even-length lists this naturally
 *             returns the second of the two middle nodes.
 *
 * Time:       O(n) - single pass
 * Space:      O(1)
 *
 * Example:
 *   Input:  head = [1, 2, 3, 4, 5]
 *   Output: [3, 4, 5]
 *
 *   Input:  head = [1, 2, 3, 4, 5, 6]
 *   Output: [4, 5, 6]
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Move slow by 1, fast by 2. When fast hits the end, slow is at the middle.
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

int main() {
    // Build list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* result = sol.middleNode(head);

    // Expected: 3 -> 4 -> 5
    int expected[] = {3, 4, 5};
    int i = 0;
    while(result != nullptr) {
        if(result->val != expected[i]) return 1;
        result = result->next;
        i++;
    }

    return (i == 3) ? 0 : 1;
}
