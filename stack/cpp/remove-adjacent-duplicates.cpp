#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    stack<char> st;

    // Traverse string
    for(int i = 0; i < s.length(); i++)
    {
        // If top element matches current character,
        // remove duplicate
        if(!st.empty() && st.top() == s[i])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    string ans = "";

    // Convert stack to string
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    // Reverse because stack stores characters in reverse order
    reverse(ans.begin(), ans.end());

    cout << ans;

    return 0;
}
