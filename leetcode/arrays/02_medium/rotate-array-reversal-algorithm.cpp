#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        // Handle empty array
        if(nums.empty())
            return;

        // Reduce unnecessary rotations
        k %= nums.size();

        // Step 1: Reverse the entire array
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse the remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};

/*
Problem:
LeetCode 189 - Rotate Array

Approach:
1. Compute the effective number of rotations using k % n.
2. Reverse the entire array.
3. Reverse the first k elements.
4. Reverse the remaining n - k elements.
5. The array is now rotated to the right by k positions.

Pattern:
Array + Reversal Algorithm

Time Complexity: O(n)

Space Complexity: O(1)
*/
