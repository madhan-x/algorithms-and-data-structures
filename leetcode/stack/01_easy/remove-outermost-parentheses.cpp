#include <iostream>
#include <string>
using namespace std;

/*
Problem:
LeetCode 1021 - Remove Outermost Parentheses

Difficulty:
Easy

Pattern:
Parentheses Depth

Example:

Input:
(()())(()) 

Output:
()()()
*/

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ans = "";
        int depth = 0;

        for(char c : s)
        {
            if(c == '(')
            {
                // If depth is already greater than 0,
                // this is not an outermost parenthesis.
                if(depth > 0)
                {
                    ans += c;
                }

                depth++;
            }
            else
            {
                depth--;

                // If depth is still greater than 0,
                // this closing parenthesis is not outermost.
                if(depth > 0)
                {
                    ans += c;
                }
            }
        }

        return ans;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution obj;

    cout << obj.removeOuterParentheses(s);

    return 0;
}

/*
Approach:

Maintain the current parenthesis depth.

For '(':
    - If depth > 0, keep it.
    - Increase depth.

For ')':
    - Decrease depth first.
    - If depth > 0, keep it.

The first '(' of a primitive group and its matching
last ')' are therefore excluded.

Example:

(()())(())

Primitive groups:
(()()) + (())

Remove outer parentheses:

()() + ()

Result:
()()()

Time Complexity: O(n)

Space Complexity: O(n)

O(n) space is required for the returned result.
The algorithm itself uses O(1) extra space.
*/
