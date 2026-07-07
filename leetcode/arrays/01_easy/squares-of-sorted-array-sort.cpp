/*
 * Problem:    LC 977 - Squares of a Sorted Array
 * Difficulty: Easy
 * Pattern:    Sort
 * Link:       https://leetcode.com/problems/squares-of-a-sorted-array/
 *
 * Approach:   Square every element in-place, then sort the array.
 *             std::sort runs in O(n log n), which is fast enough for
 *             the constraints and keeps the implementation minimal.
 *
 * Time:       O(n log n) - sorting dominates
 * Space:      O(1)        - in-place sort
 *
 * Example:
 *   Input:  nums = [-4, -1, 0, 3, 10]
 *   Output: [0, 1, 9, 16, 100]
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        // Square each element in-place
        for(size_t i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }

        // Sort the squared values
        sort(nums.begin(), nums.end());

        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> expected = {0, 1, 9, 16, 100};

    vector<int> result = sol.sortedSquares(nums);

    return result == expected ? 0 : 1;
}
