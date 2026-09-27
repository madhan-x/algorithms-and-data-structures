#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int zeroCount = 0;
        int maxones = 0;
        int left = 0;

        // Expand the window using right pointer.
        for(int right = 0; right < nums.size(); right++) {

            // Count zeros inside the current window.
            if(nums[right] == 0)
                zeroCount++;

            // If we have more zeros than we are allowed
            // to flip, shrink the window from the left.
            while(zeroCount > k) {

                if(nums[left] == 0)
                    zeroCount--;

                left++;
            }

            // Current window contains at most k zeros.
            maxones = max(maxones, right - left + 1);
        }

        return maxones;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {
        1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
    };

    int k = 2;

    cout << obj.longestOnes(nums, k) << endl;

    return 0;
}

/*
Example:

nums = [1,1,1,0,0,0,1,1,1,1,0]
k = 2

We can flip at most 2 zeros.

Output:
6

Pattern:
Variable-Size Sliding Window

Time Complexity:
O(n)

Space Complexity:
O(1)
*/
