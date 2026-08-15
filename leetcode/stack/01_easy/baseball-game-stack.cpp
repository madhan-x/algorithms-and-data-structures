#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

/*
Problem:
LeetCode 682 - Baseball Game

Difficulty:
Easy

Pattern:
Stack

Example:

Input:
5
5 2 C D +

Output:
30
*/

class Solution
{
public:
    int calPoints(vector<string>& operations)
    {
        stack<int> st;

        for(string op : operations)
        {
            // If the operation is a number,
            // convert it to an integer and push it.
            if(op != "C" && op != "D" && op != "+")
            {
                st.push(stoi(op));
            }

            // "C" removes the previous score.
            else if(op == "C")
            {
                st.pop();
            }

            // "D" adds double the previous score.
            else if(op == "D")
            {
                st.push(st.top() * 2);
            }

            // "+" adds the previous two scores.
            else
            {
                int first = st.top();
                st.pop();

                int second = st.top();

                // Restore the first score.
                st.push(first);

                // Push the sum of the previous two scores.
                st.push(first + second);
            }
        }

        // Calculate the final score.
        int total = 0;

        while(!st.empty())
        {
            total += st.top();
            st.pop();
        }

        return total;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<string> operations(n);

    for(int i = 0; i < n; i++)
    {
        cin >> operations[i];
    }

    Solution obj;

    cout << obj.calPoints(operations);

    return 0;
}

/*
Approach:

Use a stack to maintain the valid scores.

Operation:
Number → Push score
"C"    → Remove previous score
"D"    → Push double of previous score
"+"    → Push sum of previous two scores

Time Complexity:
O(n)

Space Complexity:
O(n)
*/
