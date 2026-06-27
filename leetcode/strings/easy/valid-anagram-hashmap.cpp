#include<string>
#include<unordered_map>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // Strings of different lengths cannot be anagrams
        if(s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, int> count;

        // Count frequency of characters in first string
        for(char ch : s)
        {
            count[ch]++;
        }

        // Decrease frequency using second string
        for(char ch : t)
        {
            // Character not found
            if(count.find(ch) == count.end())
            {
                return false;
            }

            count[ch]--;

            // Character appears more times in second string
            if(count[ch] < 0)
            {
                return false;
            }
        }

        // Strings are anagrams
        return true;
    }
};
