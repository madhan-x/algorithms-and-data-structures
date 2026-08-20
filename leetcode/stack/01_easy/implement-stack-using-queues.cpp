#include <iostream>
#include <queue>
using namespace std;

/*
Problem:
LeetCode 225 - Implement Stack using Queues

Difficulty:
Easy

Pattern:
Queue + Stack Simulation

Example:

push(1)
push(2)

top()    -> 2
pop()    -> 2
empty()  -> false
*/

class MyStack
{
private:
    queue<int> q;

public:

    MyStack()
    {
    }

    void push(int x)
    {
        // Store the current size before adding the new element
        int size = q.size();

        // Add the new element to the back
        q.push(x);

        // Move all previous elements behind the new element.
        // This makes the newest element appear at the front,
        // giving the queue LIFO behaviour.
        for(int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int x = q.front();
        q.pop();

        return x;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack st;

    st.push(1);
    st.push(2);

    cout << "Top: " << st.top() << endl;

    cout << "Pop: " << st.pop() << endl;

    cout << boolalpha;
    cout << "Empty: " << st.empty() << endl;

    return 0;
}

/*
Approach:

A queue normally follows FIFO:
First In → First Out

A stack follows LIFO:
Last In → First Out

To simulate a stack using one queue:

1. Push the new element into the queue.
2. Rotate all previously existing elements behind it.
3. The newest element becomes the front.
4. Therefore, pop() and top() can simply operate on q.front().

Example:

push(1)
Queue: [1]

push(2)
Queue: [1, 2]

Rotate:
Queue: [2, 1]

Now:

top() -> 2
pop() -> 2

Time Complexity:
push() -> O(n)
pop()  -> O(1)
top()  -> O(1)
empty() -> O(1)

Space Complexity:
O(n)
*/
