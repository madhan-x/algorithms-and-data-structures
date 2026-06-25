#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int i = 0;

        // Traverse the array
        for(int j = 1; j < nums.size(); j++)
        {
            // Found a new unique element
            if(nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }

        // Number of unique elements
        return i + 1;
    }
};
