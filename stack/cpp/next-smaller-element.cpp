#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> ans(n);

    // Input array elements
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    stack<int> st;

    // Traverse from right to left
    for(int i = n - 1; i >= 0; i--)
    {
        // Remove greater or equal elements
        while(!st.empty() && st.top() >= a[i])
        {
            st.pop();
        }

        // Store next smaller element
        if(st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }

        // Push current element into stack
        st.push(a[i]);
    }

    // Print answer
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
