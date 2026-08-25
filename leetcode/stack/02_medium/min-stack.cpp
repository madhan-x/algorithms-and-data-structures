#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
Problem:
LeetCode 155 - Min Stack

Difficulty:
Medium

Pattern:
Stack + Auxiliary Stack

Operations:
push(val)
pop()
top()
getMin()

All operations should run in O(1).
*/

class MinStack
{
private:
    vector<int> stack;
    vector<int> minStack;

public:

    MinStack()
    {
    }

    void push(int val)
    {
        // Store the value in the main stack.
        stack.push_back(val);

        // Store the value in minStack if it is
        // the smallest value seen so far.
        //
        // <= is important because duplicate minimum
        // values must also be stored.
        if(minStack.empty() || val <= minStack.back())
        {
            minStack.push_back(val);
        }
    }

    void pop()
    {
        int val = stack.back();

        // Remove the top element from the main stack.
        stack.pop_back();

        // If the removed value was the current minimum,
        // remove it from minStack as well.
        if(val == minStack.back())
        {
            minStack.pop_back();
        }
    }

    int top()
    {
        return stack.back();
    }

    int getMin()
    {
        // The top of minStack is always
        // the minimum element in the main stack.
        return minStack.back();
    }
};

int main()
{
    MinStack st;

    st.push(-2);
    st.push(0);
    st.push(-3);

    cout << "Minimum: " << st.getMin() << endl;

    st.pop();

    cout << "Top: " << st.top() << endl;
    cout << "Minimum: " << st.getMin() << endl;

    return 0;
}

/*
Example:

push(-2)
push(0)
push(-3)

Main Stack:
[-2, 0, -3]

Min Stack:
[-2, -3]

getMin() -> -3

After pop():

Main Stack:
[-2, 0]

Min Stack:
[-2]

getMin() -> -2


Why use two stacks?

The normal stack can give us the top element in O(1),
but finding the minimum by searching the entire stack
would take O(n).

minStack keeps track of the minimum at every stage,
so getMin() becomes O(1).

Time Complexity:
push()   -> O(1)
pop()    -> O(1)
top()    -> O(1)
getMin() -> O(1)

Space Complexity:
O(n)
*/
