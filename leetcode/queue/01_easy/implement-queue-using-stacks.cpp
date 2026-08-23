#include <iostream>
#include <stack>
using namespace std;

/*
Problem:
LeetCode 232 - Implement Queue using Stacks

Difficulty:
Easy

Pattern:
Two Stacks

Example:

push(1)
push(2)
push(3)

peek() -> 1
pop()  -> 1
peek() -> 2
empty() -> false
*/

class MyQueue
{
private:
    stack<int> s1;
    stack<int> s2;

    // Move elements from s1 to s2 only when s2 is empty.
    void transfer()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:

    MyQueue()
    {
    }

    void push(int x)
    {
        // New elements are always added to s1.
        s1.push(x);
    }

    int pop()
    {
        // Make sure the oldest element is available in s2.
        transfer();

        int x = s2.top();
        s2.pop();

        return x;
    }

    int peek()
    {
        // Make sure the oldest element is available in s2.
        transfer();

        return s2.top();
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

int main()
{
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Peek: " << q.peek() << endl;
    cout << "Pop: " << q.pop() << endl;
    cout << "Peek: " << q.peek() << endl;
    cout << boolalpha;
    cout << "Empty: " << q.empty() << endl;

    return 0;
}

/*
How it works:

Queue:
FIFO -> First In, First Out

Stack:
LIFO -> Last In, First Out

Use two stacks:

s1 -> stores newly pushed elements
s2 -> provides queue order

Example:

push(1)
push(2)
push(3)

s1:
[3]
[2]
[1]

Transfer to s2:

s2:
[1]
[2]
[3]

Now s2.top() is 1, which is the oldest element.

Important:
We transfer only when s2 is empty.

This avoids repeatedly moving the same elements.

Complexities:

push()  -> O(1)
pop()   -> O(1) amortized
peek()  -> O(1) amortized
empty() -> O(1)

Space Complexity:
O(n)
*/
