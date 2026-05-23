#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string s;
    cin >> s;

    stack<int> st;

    // Traverse postfix expression
    for(int i = 0; i < s.length(); i++)
    {
        // If character is a digit
        if(isdigit(s[i]))
        {
            st.push(s[i] - '0');
        }
        else
        {
            // Take top two elements
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            int result;

            // Perform operation
            if(s[i] == '+')
            {
                result = b + a;
            }
            else if(s[i] == '-')
            {
                result = b - a;
            }
            else if(s[i] == '*')
            {
                result = b * a;
            }
            else if(s[i] == '/')
            {
                result = b / a;
            }

            // Push result back into stack
            st.push(result);
        }
    }

    // Final answer
    cout << st.top();

    return 0;
}
