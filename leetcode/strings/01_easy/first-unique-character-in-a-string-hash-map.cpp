#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> mp;

        // Count the frequency of each character
        for(char ch : s)
        {
            mp[ch]++;
        }

        // Find the first character with frequency 1
        for(int i = 0; i < s.length(); i++)
        {
            if(mp[s[i]] == 1)
            {
                return i;
            }
        }

        // No unique character found
        return -1;
    }
};

/*
Approach:
1. Store the frequency of every character using a Hash Map.
2. Traverse the string again.
3. Return the index of the first character whose frequency is 1.

Pattern: Hash Map / Frequency Counting

Time Complexity: O(n)
Space Complexity: O(1)
*/
