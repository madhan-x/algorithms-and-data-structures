#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

/*
Problem:
LeetCode 3174 - Clear Digits

Difficulty:
Easy

Pattern:
Stack

Example:

Input:
cb34

Output:
""

Another example:

Input:
abc3

Output:
"ab"
*/

class Solution
{
public:
    string clearDigits(string s)
    {
        stack<char> st;

        for(char c : s)
        {
            // If the current character is a digit,
            // remove the most recent character.
            if(isdigit(static_cast<unsigned char>(c)) && !st.empty())
            {
                st.pop();
            }
            else
            {
                // Store non-digit characters.
                st.push(c);
            }
        }

        string ans = "";

        // Extract the remaining characters from the stack.
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        // Stack gives the characters in reverse order.
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    string s;

    cin >> s;

    Solution obj;

    cout << obj.clearDigits(s);

    return 0;
}

/*
Approach:

Traverse the string from left to right.

For every character:

1. If it is a digit:
   - Remove the most recently stored character.

2. Otherwise:
   - Push the character onto the stack.

At the end, the stack contains the characters
that remain after all digit operations.

Example:

"abc3"

a -> [a]
b -> [a,b]
c -> [a,b,c]
3 -> removes c

Result:
"ab"

Time Complexity: O(n)

Space Complexity: O(n)
*/
