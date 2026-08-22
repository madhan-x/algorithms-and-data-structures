#include <iostream>
#include <string>
using namespace std;

/*
Problem:
LeetCode 58 - Length of Last Word

Difficulty:
Easy

Pattern:
String Traversal

Example:

Input:
Hello World

Output:
5
*/

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int i = s.length() - 1;

        // Skip trailing spaces
        while(i >= 0 && s[i] == ' ')
        {
            i--;
        }

        int count = 0;

        // Count characters of the last word
        while(i >= 0 && s[i] != ' ')
        {
            count++;
            i--;
        }

        return count;
    }
};

int main()
{
    string s;

    getline(cin, s);

    Solution obj;

    cout << obj.lengthOfLastWord(s);

    return 0;
}

/*
Approach:

1. Start from the end of the string.
2. Skip any trailing spaces.
3. Count characters until a space or the beginning
   of the string is reached.

Example:

"Hello World   "

Skip spaces:
"Hello World"

Count:
d → 1
l → 2
r → 3
o → 4
W → 5

Answer:
5

Time Complexity: O(n)

Space Complexity: O(1)
*/
