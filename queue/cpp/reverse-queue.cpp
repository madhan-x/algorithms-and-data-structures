#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    queue<int> q;
    stack<int> st;

    int n;
    cin >> n;

    // Input queue elements
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    // Move queue elements to stack
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    // Move stack elements back to queue
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // Print reversed queue
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
