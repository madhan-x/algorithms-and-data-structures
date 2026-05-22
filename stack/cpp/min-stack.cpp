#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    stack<int> minStack;

    while(true)
    {
        int choice;
        cin >> choice;

        switch(choice)
        {
            // PUSH operation
            case 1:
            {
                int x;
                cin >> x;

                s.push(x);

                // Push into minStack if:
                // 1. minStack is empty
                // 2. current element is smaller/equal
                if(minStack.empty() || x <= minStack.top())
                {
                    minStack.push(x);
                }

                break;
            }

            // POP operation
            case 2:
            {
                if(!s.empty())
                {
                    // Remove from minStack if
                    // popped element is current minimum
                    if(s.top() == minStack.top())
                    {
                        minStack.pop();
                    }

                    s.pop();
                }

                break;
            }

            // TOP operation
            case 3:
            {
                if(!s.empty())
                {
                    cout << s.top() << endl;
                }

                break;
            }

            // GET MIN operation
            case 4:
            {
                if(!minStack.empty())
                {
                    cout << minStack.top() << endl;
                }

                break;
            }

            // EXIT
            case 5:
            {
                return 0;
            }
        }
    }

    return 0;
}
