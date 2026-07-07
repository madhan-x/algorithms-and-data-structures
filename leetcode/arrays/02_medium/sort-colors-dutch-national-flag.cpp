/*
 * Problem:    LC 75 - Sort Colors
 * Difficulty: Medium
 * Pattern:    Two Pointers (Dutch National Flag)
 * Link:       https://leetcode.com/problems/sort-colors/
 *
 * Approach:   Three-region partition with pointers lo (next slot for 0),
 *             mid (current element), and hi (next slot for 2). When nums[mid]
 *             is 0, swap with nums[lo++] and advance mid. When it is 2, swap
 *             with nums[hi--] and re-check mid (do not advance). When 1,
 *             just advance mid. Invariant: nums[0..lo-1] == 0,
 *             nums[lo..mid-1] == 1, nums[hi+1..n-1] == 2.
 *
 * Time:       O(n) - single pass
 * Space:      O(1)
 *
 * Example:
 *   Input:  nums = [2, 0, 2, 1, 1, 0]
 *   Output: [0, 0, 1, 1, 2, 2]
 */

#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, mid = 0, hi = (int)nums.size() - 1;
        while (mid <= hi) {
            if (nums[mid] == 0) {
                swap(nums[lo], nums[mid]);
                lo++;
                mid++;
            } else if (nums[mid] == 2) {
                swap(nums[mid], nums[hi]);
                hi--;
            } else { // nums[mid] == 1
                mid++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);
    return (nums == vector<int>{0, 0, 1, 1, 2, 2}) ? 0 : 1;
}
