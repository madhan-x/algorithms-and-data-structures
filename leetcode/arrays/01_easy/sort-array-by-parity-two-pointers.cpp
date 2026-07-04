#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        int j = 0;

        // Traverse the array
        for(int i = 0; i < nums.size(); i++)
        {
            // Place even numbers at the beginning
            if(nums[i] % 2 == 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }

        return nums;
    }
};
