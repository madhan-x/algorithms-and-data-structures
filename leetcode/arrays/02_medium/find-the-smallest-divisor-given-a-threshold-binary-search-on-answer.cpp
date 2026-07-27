#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Calculate the total sum after dividing every element
    // by the given divisor using ceiling division
    int totalSum(vector<int>& nums, int divisor)
    {
        int sum = 0;

        for(int num : nums)
        {
            sum += (num + divisor - 1) / divisor;
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold)
    {
        // Search space for the divisor
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            // Check if the current divisor satisfies the threshold
            if(totalSum(nums, mid) <= threshold)
            {
                ans = mid;

                // Try to find a smaller valid divisor
                high = mid - 1;
            }
            else
            {
                // Divisor is too small, increase it
                low = mid + 1;
            }
        }

        return ans;
    }
};

/*
Problem:
LeetCode 1283 - Find the Smallest Divisor Given a Threshold

Approach:
1. Binary Search on the possible divisor.
2. For every divisor, calculate the total using ceiling division.
3. If the total is within the threshold,
   try a smaller divisor.
4. Otherwise, increase the divisor.
5. The smallest valid divisor is the answer.

Pattern:
Binary Search on Answer

Time Complexity:
O(n log m)
n = number of elements
m = maximum element

Space Complexity:
O(1)
*/
