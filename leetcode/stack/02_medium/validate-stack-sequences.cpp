#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Problem:
LeetCode 946 - Validate Stack Sequences

Difficulty:
Medium

Pattern:
Stack Simulation

Example:

pushed = [1, 2, 3, 4, 5]
popped = [4, 5, 3, 2, 1]

Output:
true
*/

class Solution
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> st;

        int j = 0;

        // Process every element that is pushed
        for(int x : pushed)
        {
            // Push the current element onto the stack
            st.push(x);

            // If the top matches the next required popped element,
            // keep popping while possible.
            while(!st.empty() && j < popped.size() &&
                  st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }

        // If every element was successfully popped,
        // the sequence is valid.
        return st.empty();
    }
};

int main()
{
    int n;

    cin >> n;

    vector<int> pushed(n);
    vector<int> popped(n);

    for(int i = 0; i < n; i++)
    {
        cin >> pushed[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> popped[i];
    }

    Solution obj;

    cout << boolalpha
         << obj.validateStackSequences(pushed, popped);

    return 0;
}

/*
Approach:

Simulate the stack operations.

For every element in pushed:
1. Push it onto the stack.
2. Check whether the top of the stack matches
   the next required element in popped.
3. If it matches, pop it.
4. Continue popping while the top matches.

Example:

pushed = [1, 2, 3, 4, 5]
popped = [4, 5, 3, 2, 1]

Push 1 -> [1]
Push 2 -> [1, 2]
Push 3 -> [1, 2, 3]
Push 4 -> [1, 2, 3, 4]
Pop 4
Push 5 -> [1, 2, 3, 5]
Pop 5
Pop 3
Pop 2
Pop 1

Stack becomes empty.

Therefore:
true

Time Complexity: O(n)

Space Complexity: O(n)
*/
