#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        // Store all unique elements from nums1
        unordered_set<int> s(nums1.begin(), nums1.end());

        // Store the unique common elements
        unordered_set<int> ans;

        // Check every element of nums2
        for(int num : nums2)
        {
            // If present in nums1, add to answer set
            if(s.count(num))
            {
                ans.insert(num);
            }
        }

        // Convert the set into a vector
        return vector<int>(ans.begin(), ans.end());
    }
};

/*
Problem:
LeetCode 349 - Intersection of Two Arrays

Approach:
1. Store all unique elements of nums1 in a Hash Set.
2. Traverse nums2.
3. If an element exists in the first set, insert it into the answer set.
4. Convert the answer set to a vector.

Pattern:
Hash Set

Time Complexity: O(n + m)

Space Complexity: O(n)
*/
