#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char>& s)
    {
        int i = 0;
        int j = s.size() - 1;

        // Reverse the string using Two Pointers
        while(i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};

/*
Approach:
- Place one pointer at the beginning and another at the end.
- Swap both characters.
- Move the pointers towards the center until they meet.

Time Complexity: O(n)
Space Complexity: O(1)
*/
