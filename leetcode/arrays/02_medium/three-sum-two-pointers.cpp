#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;

        // Sort the array
        sort(nums.begin(), nums.end());

        // Fix one element at a time
        for(int i = 0; i < nums.size() - 2; i++)
        {
            // Skip duplicate first elements
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            // Apply Two Pointer technique
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                // Triplet found
                if(sum == 0)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate values
                    while(left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }

                    while(left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }

                    left++;
                    right--;
                }

                // Increase sum
                else if(sum < 0)
                {
                    left++;
                }

                // Decrease sum
                else
                {
                    right--;
                }
            }
        }

        return ans;
    }
};
