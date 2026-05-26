#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    queue<int> q;
    stack<int> st;

    // Insert queue elements
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k;
    cin >> k;

    int n = q.size();

    // Step 1:
    // Push first k elements into stack
    for(int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    // Step 2:
    // Push stack elements back into queue
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // Step 3:
    // Rotate remaining elements
    for(int i = 0; i < n - k; i++)
    {
        q.push(q.front());
        q.pop();
    }

    // Print final queue
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
