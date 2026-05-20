#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    // Input array elements
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    stack<int> st;

    // Find Previous Smaller Element
    for(int i = 0; i < n; i++)
    {
        // Remove greater or equal elements
        while(!st.empty() && st.top() >= a[i])
        {
            st.pop();
        }

        // If stack becomes empty,
        // no smaller element exists on left
        if(st.empty())
        {
            cout << -1 << " ";
        }
        else
        {
            cout << st.top() << " ";
        }

        // Push current element into stack
        st.push(a[i]);
    }

    return 0;
}
