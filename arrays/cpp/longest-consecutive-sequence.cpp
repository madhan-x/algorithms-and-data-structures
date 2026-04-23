#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Longest Consecutive Sequence
// Approach:
// - Store elements in a set for O(1) lookup
// - Only start counting when (num - 1) is not present
// - Expand forward to find sequence length
// Time Complexity: O(n)
// Space Complexity: O(n)

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;

    for (int num : s) {
        // start of sequence
        if (s.find(num - 1) == s.end()) {
            int current = num;
            int length = 1;

            while (s.find(current + 1) != s.end()) {
                current++;
                length++;
            }

            longest = max(longest, length);
        }
    }

    return longest;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums);
    return 0;
}
