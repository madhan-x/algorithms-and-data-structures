#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        // Sort the scores.
        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;

        // Check every group of k consecutive elements.
        for(int i = 0; i + k - 1 < nums.size(); i++) {

            // Since the array is sorted, the first element
            // is the minimum and the last element is the maximum.
            int diff = nums[i + k - 1] - nums[i];

            minDiff = min(minDiff, diff);
        }

        return minDiff;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {9, 4, 1, 7};
    int k = 2;

    cout << obj.minimumDifference(nums, k) << endl;

    return 0;
}

/*
Example:

nums = [9,4,1,7]
k = 2

After sorting:

[1,4,7,9]

Windows of size 2:

[1,4] -> 3
[4,7] -> 3
[7,9] -> 2

Answer = 2

Approach:
- Sort the array.
- Check every group of k consecutive elements.
- Calculate maximum - minimum for each group.
- Keep the minimum difference.

Pattern:
Sorting + Fixed-Size Window

Time Complexity:
O(n log n)

Space Complexity:
O(1) auxiliary space
*/
