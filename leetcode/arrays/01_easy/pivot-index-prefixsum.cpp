/*
 * Problem:    LC 724 - Find Pivot Index
 * Difficulty: Easy
 * Pattern:    Prefix Sum
 * Link:       https://leetcode.com/problems/find-pivot-index/
 *
 * Approach:   For each index i, compute the sum of elements strictly to the
 *             left and strictly to the right using two nested loops. Return
 *             the first i where both sums are equal; return -1 if none exist.
 *
 * Time:       O(n^2) - recompute left/right sums for every index
 * Space:      O(1)
 *
 * Example:
 *   Input:  nums = [1, 7, 3, 6, 5, 6]
 *   Output: 3        (left sum = 1+7+3 = 11, right sum = 5+6 = 11)
 */

#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i++) {

            int leftSum = 0;
            int rightSum = 0;

            // Calculate left sum
            for(int j = 0; j < i; j++) {
                leftSum += nums[j];
            }

            // Calculate right sum
            for(int j = i + 1; j < nums.size(); j++) {
                rightSum += nums[j];
            }

            if(leftSum == rightSum) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    // expected: 3
    return sol.pivotIndex(nums) == 3 ? 0 : 1;
}
