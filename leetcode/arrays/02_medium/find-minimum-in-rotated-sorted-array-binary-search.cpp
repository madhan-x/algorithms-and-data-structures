#include <vector>
using namespace std;

class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int low = 0;
        int high = nums.size() - 1;

        // Assume the first element is the minimum
        int mini = nums[0];

        while(low <= high)
        {
            // If the current search space is already sorted,
            // the leftmost element is the minimum.
            if(nums[low] <= nums[high])
            {
                mini = min(mini, nums[low]);
                break;
            }

            int mid = low + (high - low) / 2;

            // Left half is sorted
            if(nums[low] <= nums[mid])
            {
                mini = min(mini, nums[low]);
                low = mid + 1;
            }
            // Right half is sorted
            else
            {
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }

        return mini;
    }
};

/*
Problem:
LeetCode 153 - Find Minimum in Rotated Sorted Array

Approach:
1. Check if the current search space is already sorted.
2. If sorted, the leftmost element is the minimum.
3. Otherwise, determine which half is sorted.
4. Discard the sorted half after updating the minimum.
5. Continue searching in the unsorted half.

Pattern:
Modified Binary Search

Time Complexity: O(log n)

Space Complexity: O(1)
*/
