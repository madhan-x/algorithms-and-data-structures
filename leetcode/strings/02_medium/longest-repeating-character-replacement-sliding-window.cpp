#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int i = 0, j = 0;
        int maxFreq = 0;
        int maxLength = 0;

        unordered_map<char, int> mp;

        while(j < s.length())
        {
            // Include current character
            mp[s[j]]++;

            // Store the highest frequency character in the window
            maxFreq = max(maxFreq, mp[s[j]]);

            // Shrink the window if more than k replacements are required
            while((j - i + 1) - maxFreq > k)
            {
                mp[s[i]]--;
                i++;
            }

            // Update maximum valid window length
            maxLength = max(maxLength, j - i + 1);

            j++;
        }

        return maxLength;
    }
};

/*
Approach:
1. Expand the sliding window.
2. Track the frequency of each character.
3. Maintain the highest frequency character.
4. Shrink the window if replacements required exceed k.
5. Record the maximum valid window.

Pattern: Sliding Window + Hash Map

Time Complexity: O(n)
Space Complexity: O(1)
*/
