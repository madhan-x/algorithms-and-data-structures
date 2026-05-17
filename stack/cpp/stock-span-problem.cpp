#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    // Input stock prices
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Stack stores indices
    stack<int> st;

    // Calculate span for each day
    for(int i = 0; i < n; i++)
    {
        // Remove smaller or equal previous elements
        while(!st.empty() && a[st.top()] <= a[i])
        {
            st.pop();
        }

        int span;

        // If stack becomes empty,
        // span extends from day 0 to current day
        if(st.empty())
        {
            span = i + 1;
        }
        else
        {
            // Difference between current index
            // and previous greater element index
            span = i - st.top();
        }

        cout << span << " ";

        // Push current index into stack
        st.push(i);
    }

    return 0;
}
