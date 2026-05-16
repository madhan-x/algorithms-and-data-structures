#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    stack<int> temp;

    // Original stack
    s.push(10);
    s.push(20);
    s.push(30);

    int x = 5;

    // Move all elements from original stack to temp stack
    while(!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }

    // Insert element at bottom
    s.push(x);

    // Move elements back to original stack
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }

    // Print final stack
    cout << "Stack after inserting at bottom:\n";

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
