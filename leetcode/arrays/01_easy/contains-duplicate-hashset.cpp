#include<vector>
#include<unordered_set>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> st;

        // Traverse the array
        for(int i = 0; i < nums.size(); i++)
        {
            // Duplicate found
            if(st.find(nums[i]) != st.end())
            {
                return true;
            }

            // Store current element
            st.insert(nums[i]);
        }

        // No duplicates found
        return false;
    }
};
