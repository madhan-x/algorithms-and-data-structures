#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        int k = 0;

        // Traverse the array
        for(int i = 0; i < nums.size(); i++)
        {
            // Keep elements that are not equal to val
            if(nums[i] != val)
            {
                nums[k] = nums[i];
                k++;
            }
        }

        // Number of remaining elements
        return k;
    }
};
