#include<vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        // Check every element
        for(int i = 0; i < nums.size(); i++)
        {
            int count = 0;

            // Count its frequency
            for(int j = 0; j < nums.size(); j++)
            {
                if(nums[i] == nums[j])
                {
                    count++;
                }
            }

            // Majority element found
            if(count > nums.size() / 2)
            {
                return nums[i];
            }
        }

        return -1;
    }
};
