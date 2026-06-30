/*
 * Problem:    LeetCode 1512 - Number of Good Pairs
 * Difficulty: Easy
 * Pattern:    Hash Map (frequency count)
 * Link:       https://leetcode.com/problems/number-of-good-pairs/
 *
 * Approach:   Single-pass solution using an unordered_map.
 *             Count the frequency of every element. For each value that
 *             appears c times, the number of good pairs it contributes is
 *             C(c, 2) = c * (c - 1) / 2. Sum these across all values.
 *
 * Time:       O(n) - one pass to build the map, one pass to scan it.
 * Space:      O(k) - the map holds at most k distinct keys (k <= n).
 *
 * Example:
 *   Input:  nums = [1, 2, 3, 1, 1, 3]
 *   Output: 4
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;

        // Count frequency of each number
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            mp[nums[i]]++;
        }

        // Each value appearing c times contributes c*(c-1)/2 good pairs
        int count = 0;
        unordered_map<int, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            count += (it->second * (it->second - 1)) / 2;
        }

        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    cout << s.numIdenticalPairs(nums) << endl;  // Expected: 4
    return 0;
}
