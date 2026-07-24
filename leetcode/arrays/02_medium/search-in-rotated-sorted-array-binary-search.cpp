#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            // Target found
            if(nums[mid] == target)
            {
                return mid;
            }

            // Left half is sorted
            if(nums[low] <= nums[mid])
            {
                // Target lies in the left half
                if(nums[low] <= target && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else
            {
                // Target lies in the right half
                if(nums[mid] < target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        // Target not found
        return -1;
    }
};

/*
Problem:
LeetCode 33 - Search in Rotated Sorted Array

Approach:
1. Find the middle element.
2. Determine which half is sorted.
3. Check if the target belongs to the sorted half.
4. Search only in the relevant half.
5. Repeat until the target is found or the search space is empty.

Pattern:
Modified Binary Search

Time Complexity: O(log n)

Space Complexity: O(1)
*/
