#include<string>
using namespace std;

class Solution
{
public:
    // Function to check whether a character is a vowel
    bool isVowel(char ch)
    {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k)
    {
        int count = 0;

        // Count vowels in the first window
        for(int i = 0; i < k; i++)
        {
            if(isVowel(s[i]))
            {
                count++;
            }
        }

        int maxCount = count;

        // Slide the window through the string
        for(int i = k; i < s.length(); i++)
        {
            // Remove the outgoing character
            if(isVowel(s[i - k]))
            {
                count--;
            }

            // Add the incoming character
            if(isVowel(s[i]))
            {
                count++;
            }

            // Update maximum vowel count
            if(count > maxCount)
            {
                maxCount = count;
            }
        }

        return maxCount;
    }
};

/*
Approach:
1. Count vowels in the first window of size k.
2. Slide the window one character at a time.
3. Remove the outgoing character if it is a vowel.
4. Add the incoming character if it is a vowel.
5. Track the maximum number of vowels.

Pattern: Sliding Window

Time Complexity: O(n)
Space Complexity: O(1)
*/
