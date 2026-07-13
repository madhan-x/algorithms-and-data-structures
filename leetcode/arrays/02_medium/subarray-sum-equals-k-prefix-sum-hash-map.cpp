#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int> mp;

        // Prefix sum 0 occurs once before traversal
        mp[0] = 1;

        int prefix = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            // Calculate current prefix sum
            prefix += nums[i];

            // Check if a previous prefix sum exists
            // such that currentPrefix - previousPrefix = k
            if(mp.count(prefix - k))
            {
                count += mp[prefix - k];
            }

            // Store current prefix sum
            mp[prefix]++;
        }

        return count;
    }
};

/*
Approach:
1. Compute prefix sums while traversing.
2. Store frequencies of prefix sums in a Hash Map.
3. If (currentPrefix - k) exists, a valid subarray is found.
4. Add its frequency to the answer.

Pattern: Prefix Sum + Hash Map

Time Complexity: O(n)
Space Complexity: O(n)
*/
