#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        // If the array is empty, there is no increasing subsequence.
        if(nums.empty()) {
            return 0;
        }

        int currLen = 1;
        int maxLen = 1;

        for(int i = 1; i < nums.size(); i++) {

            // Continue the current increasing sequence.
            if(nums[i] > nums[i - 1]) {
                currLen++;
            }
            else {
                // Increasing sequence is broken.
                currLen = 1;
            }

            // Update the maximum length found so far.
            if(currLen > maxLen) {
                maxLen = currLen;
            }
        }

        return maxLen;
    }
};

int main() {

    Solution sol;

    vector<int> nums = {1, 3, 5, 4, 7};

    cout << sol.findLengthOfLCIS(nums) << endl;

    return 0;
}

/*
Approach:
- Traverse the array once.
- Keep track of the current increasing sequence length.
- When nums[i] > nums[i-1], extend the sequence.
- Otherwise, reset the current length to 1.
- Keep track of the maximum length.

Pattern:
Array Traversal / Counting

Time Complexity:
O(n)

Space Complexity:
O(1)
*/
