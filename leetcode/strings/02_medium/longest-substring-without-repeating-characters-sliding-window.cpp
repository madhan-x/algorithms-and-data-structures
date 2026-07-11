#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, j = 0;
        int maxLength = 0;

        unordered_map<char, int> mp;

        while(j < s.length())
        {
            // Add current character to the window
            mp[s[j]]++;

            // Shrink the window until all characters are unique
            while(mp[s[j]] > 1)
            {
                mp[s[i]]--;
                i++;
            }

            // Update the maximum window length
            maxLength = max(maxLength, j - i + 1);

            j++;
        }

        return maxLength;
    }
};

/*
Approach:
1. Maintain a sliding window.
2. Expand the window by moving j.
3. If a duplicate character appears, shrink the window from the left.
4. Track the maximum window length.

Pattern: Sliding Window + Hash Map

Time Complexity: O(n)
Space Complexity: O(1)
*/
