#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int count = 0;
        int maxCount = 0;

        // Traverse the array
        for(int num : nums)
        {
            if(num == 1)
            {
                count++;
                maxCount = max(maxCount, count);
            }
            else
            {
                count = 0;
            }
        }

        return maxCount;
    }
};

/*
Approach:
1. Traverse the array.
2. Count consecutive 1's.
3. Reset the count whenever a 0 appears.
4. Track the maximum count.

Pattern: Array Traversal

Time Complexity: O(n)
Space Complexity: O(1)
*/
