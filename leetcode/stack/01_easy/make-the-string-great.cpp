#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
Problem:
LeetCode 1544 - Make The String Great

Difficulty:
Easy

Pattern:
Stack

Example:

Input:
leEeetcode

Output:
leetcode
*/

class Solution
{
public:
    string makeGood(string s)
    {
        // Use a string as a stack.
        string st;

        for(char c : s)
        {
            // If the current character and the top character
            // are the same letter but have different cases,
            // they form a bad pair.
            if(!st.empty() &&
               tolower(static_cast<unsigned char>(st.back())) ==
               tolower(static_cast<unsigned char>(c)) &&
               st.back() != c)
            {
                // Remove the bad pair.
                st.pop_back();
            }
            else
            {
                // Otherwise, add the character to the stack.
                st.push_back(c);
            }
        }

        return st;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution obj;

    cout << obj.makeGood(s);

    return 0;
}

/*
Approach:

Use a string as a stack.

For every character:
1. Compare it with the top character.
2. If they represent the same letter but have different cases,
   remove the top character.
3. Otherwise, push the current character.
4. Continue until the entire string is processed.

Example:

leEeetcode

Process:
l → l
e → le
E → l
e → le
e → lee
t → leet
c → leetc
o → leetco
d → leet cod
e → leetcode

Result:
leetcode

Time Complexity: O(n)

Space Complexity: O(n)
*/
