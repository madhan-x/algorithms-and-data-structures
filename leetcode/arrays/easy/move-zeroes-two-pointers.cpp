#include <vector>
using namespace std;

// LeetCode 283 - Move Zeroes
// Approach: Two Pointers (in-place)
//
// slow  -> position to place the next non-zero element
// fast  -> scans every element in the array
//
// On each step:
//   - If nums[fast] is non-zero, swap it into nums[slow] and advance slow.
//   - Zeros get pushed toward the end via the swaps.
//
// After the loop:
//   - Positions [0 .. slow) hold non-zero elements in original order.
//   - Positions [slow .. end) hold zeros.
//
// Time:  O(n)  - single pass
// Space: O(1)  - in-place

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < (int)nums.size(); fast++) {
            if (nums[fast] != 0) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
        }
    }
};