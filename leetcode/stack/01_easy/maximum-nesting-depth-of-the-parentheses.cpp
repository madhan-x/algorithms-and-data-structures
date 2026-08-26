#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

/*
Problem:
LeetCode 1614 - Maximum Nesting Depth of the Parentheses

Difficulty:
Easy

Pattern:
Stack

Example:

Input:
(1+(2*3)+((8)/4))+1

Output:
3
*/

class Solution
{
public:
    int maxDepth(string s)
    {
        stack<char> st;
        int ans = 0;

        for(char c : s)
        {
            // Opening parenthesis increases the current depth
            if(c == '(')
            {
                st.push(c);

                // Update maximum depth
                ans = max(ans, (int)st.size());
            }

            // Closing parenthesis decreases the current depth
            else if(c == ')')
            {
                st.pop();
            }
        }

        return ans;
    }
};

int main()
{
    string s;

    getline(cin, s);

    Solution obj;

    cout << obj.maxDepth(s);

    return 0;
}

/*
Approach:

Use a stack to keep track of currently open parentheses.

For '(':
    Push it into the stack.
    The stack size represents the current nesting depth.

For ')':
    Pop the corresponding opening parenthesis.

Keep track of the maximum stack size reached.

Example:

(1+(2*3)+((8)/4))+1

Maximum number of simultaneously open '(':
3

Therefore:
Answer = 3

Time Complexity: O(n)

Space Complexity: O(n)
*/
