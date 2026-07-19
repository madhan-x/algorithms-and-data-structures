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
            // Prevents integer overflow
            int mid = low + (high - low) / 2;

            // Target found
            if(nums[mid] == target)
            {
                return mid;
            }
            // Search in the right half
            else if(target > nums[mid])
            {
                low = mid + 1;
            }
            // Search in the left half
            else
            {
                high = mid - 1;
            }
        }

        // Target not found
        return -1;
    }
};

/*
Problem:
LeetCode 704 - Binary Search

Approach:
1. Initialize low and high pointers.
2. Find the middle element.
3. If target is found, return its index.
4. If target is greater, search the right half.
5. Otherwise, search the left half.
6. Continue until low > high.

Pattern:
Binary Search

Time Complexity: O(log n)

Space Complexity: O(1)
*/
