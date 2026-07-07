/*
 * Problem:    LC 19 - Remove Nth Node From End of List
 * Difficulty: Medium
 * Pattern:    Two Pointers
 * Link:       https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 * Approach:   Use a dummy head so removing the first real node is uniform.
 *             Advance a `fast` pointer n+1 steps ahead of a `slow` pointer,
 *             then move both until `fast` reaches the end. `slow` is now
 *             positioned at the node just before the one to remove.
 *
 * Time:       O(n) - single pass
 * Space:      O(1)
 *
 * Example:
 *   Input:  head = [1, 2, 3, 4, 5], n = 2
 *   Output: [1, 2, 3, 5]
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Dummy head handles removal of the actual first node cleanly
        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast n+1 steps ahead so slow lands just before the target
        for(int i = 0; i < n + 1; i++) {
            fast = fast->next;
        }

        // Advance both pointers until fast reaches the end
        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Skip the target node
        ListNode* toDelete = slow->next;
        slow->next = toDelete->next;
        delete toDelete;

        return dummy.next;
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
    ListNode* result = sol.removeNthFromEnd(head, 2);

    // Expected: 1 -> 2 -> 3 -> 5
    int expected[] = {1, 2, 3, 5};
    int i = 0;
    while(result != nullptr) {
        if(result->val != expected[i]) return 1;
        result = result->next;
        i++;
    }

    return (i == 4) ? 0 : 1;
}
