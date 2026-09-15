#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

/*
Problem:
LeetCode 150 - Evaluate Reverse Polish Notation

Difficulty:
Medium

Pattern:
Stack Simulation

Example:

Input:
["2", "1", "+", "3", "*"]

Evaluation:
2 + 1 = 3
3 * 3 = 9

Output:
9
*/

class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;

        for(string token : tokens)
        {
            // If the token is an operator,
            // pop the top two operands.
            if(token == "+" || token == "-" ||
               token == "*" || token == "/")
            {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                // Order matters for subtraction and division.
                if(token == "+")
                {
                    st.push(b + a);
                }
                else if(token == "-")
                {
                    st.push(b - a);
                }
                else if(token == "*")
                {
                    st.push(b * a);
                }
                else
                {
                    st.push(b / a);
                }
            }
            else
            {
                // Convert operand from string to integer.
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

int main()
{
    int n;
    cin >> n;

    vector<string> tokens(n);

    for(int i = 0; i < n; i++)
    {
        cin >> tokens[i];
    }

    Solution obj;

    cout << obj.evalRPN(tokens);

    return 0;
}

/*
Approach:

Traverse each token.

If it is a number:
    Push it onto the stack.

If it is an operator:
    1. Pop the top operand (a).
    2. Pop the second operand (b).
    3. Perform b operator a.
    4. Push the result back.

Example:

tokens = ["2", "1", "+", "3", "*"]

Stack process:

2  -> [2]
1  -> [2, 1]
+  -> [3]
3  -> [3, 3]
*  -> [9]

Answer = 9

Important:

For subtraction and division:

a = first popped
b = second popped

Result must be:

b - a
b / a

NOT:

a - b
a / b

Time Complexity: O(n)

Space Complexity: O(n)
*/
