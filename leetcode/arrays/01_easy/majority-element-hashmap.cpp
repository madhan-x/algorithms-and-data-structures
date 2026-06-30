/*
 * Problem:    LeetCode 169 - Majority Element
 * Difficulty: Easy
 * Pattern:    Hash Map (frequency count)
 * Link:       https://leetcode.com/problems/majority-element/
 *
 * Approach:   Two-pass solution using an unordered_map.
 *             Pass 1: count the frequency of every element.
 *             Pass 2: scan the map and return the first element whose
 *             count exceeds n/2. The problem guarantees such an
 *             element exists, so the final return is a safety fallback.
 *
 * Time:       O(n) - one pass to build the map, one pass to scan it.
 * Space:      O(n) - the map holds up to n distinct keys in the worst case.
 *
 * Example:
 *   Input:  nums = [3, 2, 2, 2, 3]
 *   Output: 2
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;

        // Pass 1: count frequencies
        for (size_t i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // Pass 2: find the element with count > n/2
        unordered_map<int, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            if (it->second > static_cast<int>(nums.size()) / 2) {
                return it->first;
            }
        }

        return nums[0];  // fallback (problem guarantees a majority exists)
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 2, 2, 3};
    cout << s.majorityElement(nums) << endl;  // Expected: 2
    return 0;
}
