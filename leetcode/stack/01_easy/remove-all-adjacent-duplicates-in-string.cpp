#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

/*
Problem:
LeetCode 1047 - Remove All Adjacent Duplicates In String

Difficulty:
Easy

Pattern:
Stack

Example:

Input:
abbaca

Output:
ca
*/

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;

        for(char c : s)
        {
            // If the current character matches the top,
            // remove the adjacent duplicate.
            if(!st.empty() && st.top() == c)
            {
                st.pop();
            }
            else
            {
                // Otherwise, store the character.
                st.push(c);
            }
        }

        string ans;

        // Stack stores the answer in reverse order,
        // so pop everything into the result.
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        // Restore the original order.
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution obj;

    cout << obj.removeDuplicates(s);

    return 0;
}

/*
Approach:

Use a stack to process the string from left to right.

For every character:
- If it matches the top of the stack, pop the top.
- Otherwise, push the character.

Example:

abbaca

a → push
b → push
b → matches b → pop
a → matches a → pop
c → push
a → push

Stack:
c → a

Reverse:
ca

Time Complexity: O(n)

Space Complexity: O(n)
*/
