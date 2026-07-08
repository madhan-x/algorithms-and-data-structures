/*
 * Problem:    LeetCode 643 - Maximum Average Subarray I
 * Difficulty: Easy
 * Pattern:    Sliding Window (fixed size)
 * Link:       https://leetcode.com/problems/maximum-average-subarray-i/
 *
 * Approach:   Sum the first window of size k, then slide it across the array.
 *             At each step subtract the element leaving the window and add the
 *             new element entering it. Track the maximum window sum and return
 *             it divided by k as the average.
 *
 * Time:       O(n) - single pass after the initial window sum
 * Space:      O(1) - only a few integer variables
 *
 * Example:
 *   Input:  nums = [1,12,-5,-6,50,3], k = 4
 *   Output: 12.75  (window [12,-5,-6,50] -> sum 51 -> 51/4 = 12.75)
 */

#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;

        // Sum of the first window
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;

        // Slide the window: drop the leftmost, add the new rightmost
        for (int i = k; i < nums.size(); i++) {
            sum = sum - nums[i - k] + nums[i];
            if (sum > maxSum) {
                maxSum = sum;
            }
        }

        return (double)maxSum / k;
    }
};
