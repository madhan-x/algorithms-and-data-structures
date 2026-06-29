#include <vector>
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target)
{

        // Traverse the array
        for(int i = 0; i < nums.size(); i++)
        {
            // Target found
            if(nums[i] == target)
            {
                return i;
            }

            // Target should be inserted here
            if(nums[i] > target)
            {
                return i;
            }
        }

        // Insert at the end
        return nums.size();
    }
};
