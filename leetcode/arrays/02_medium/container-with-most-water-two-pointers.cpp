/*
 * Problem:    LC 11 - Container With Most Water
 * Difficulty: Medium
 * Pattern:    Two Pointers (greedy)
 * Link:       https://leetcode.com/problems/container-with-most-water/
 *
 * Approach:   Place one pointer at each end. The area is determined by the
 *             shorter line, so moving the shorter side inward is the only
 *             way to find a taller boundary. Update max area each step.
 *
 * Time:       O(n) - single pass
 * Space:      O(1)
 *
 * Example:
 *   Input:  height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
 *   Output: 49   (between indices 1 and 8: min(8,7) * 7 = 49)
 */

#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = (int)height.size() - 1;
        int best = 0;
        while (l < r) {
            int h = min(height[l], height[r]);
            best = max(best, h * (r - l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return best;
    }
};

int main() {
    Solution sol;
    vector<int> h = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    return sol.maxArea(h) == 49 ? 0 : 1;
}
