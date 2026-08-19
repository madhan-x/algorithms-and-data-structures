#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
Problem:
LeetCode 844 - Backspace String Compare

Difficulty:
Easy

Pattern:
Stack + Simulation

Example:

Input:
ab#c
ad#c

Output:
true

Explanation:
ab#c  -> ac
ad#c  -> ac
Therefore, both strings are equal.
*/

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> st;
        stack<char> tt;

        // Process the first string
        for(char c : s)
        {
            if(c == '#')
            {
                // Backspace removes the previous character
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(c);
            }
        }

        // Process the second string
        for(char c : t)
        {
            if(c == '#')
            {
                if(!tt.empty())
                {
                    tt.pop();
                }
            }
            else
            {
                tt.push(c);
            }
        }

        // Both stacks contain the final versions of the strings
        return st == tt;
    }
};

int main()
{
    string s, t;

    cin >> s >> t;

    Solution obj;

    cout << boolalpha << obj.backspaceCompare(s, t);

    return 0;
}

/*
Approach:

Use a stack to simulate typing and backspaces.

For every character:
- Normal character → push into the stack.
- '#' → pop the previous character if the stack isn't empty.

Process both strings independently and compare their final stacks.

Example:

s = "ab#c"

a → [a]
b → [a,b]
# → [a]
c → [a,c]

Final:
ac

Time Complexity: O(n + m)

Space Complexity: O(n + m)

where:
n = length of s
m = length of t
*/
