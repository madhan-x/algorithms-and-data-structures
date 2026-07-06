#include<vector>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int>& nums)
    {
        // Check every index as a possible pivot
        for(int i = 0; i < nums.size(); i++)
        {
            int leftSum = 0;
            int rightSum = 0;

            // Calculate sum of elements on the left
            for(int j = 0; j < i; j++)
            {
                leftSum += nums[j];
            }

            // Calculate sum of elements on the right
            for(int j = i + 1; j < nums.size(); j++)
            {
                rightSum += nums[j];
            }

            // Pivot index found
            if(leftSum == rightSum)
            {
                return i;
            }
        }

        return -1;
    }
};
