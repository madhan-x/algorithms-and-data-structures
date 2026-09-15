#include <iostream>
#include <stack>
#include <utility>
using namespace std;

/*
Problem:
LeetCode 901 - Online Stock Span

Difficulty:
Medium

Pattern:
Monotonic Stack

Example:

next(100) -> 1
next(80)  -> 1
next(60)  -> 1
next(70)  -> 2
next(60)  -> 1
next(75)  -> 4
next(85)  -> 6
*/

class StockSpanner
{
private:
    // {price, span}
    stack<pair<int, int>> st;

public:

    StockSpanner()
    {
    }

    int next(int price)
    {
        // Current day always contributes 1.
        int span = 1;

        // Merge previous days whose price is
        // less than or equal to the current price.
        while(!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }

        // Store the current price along with its span.
        st.push({price, span});

        return span;
    }
};

int main()
{
    StockSpanner sp;

    cout << sp.next(100) << " ";
    cout << sp.next(80) << " ";
    cout << sp.next(60) << " ";
    cout << sp.next(70) << " ";
    cout << sp.next(60) << " ";
    cout << sp.next(75) << " ";
    cout << sp.next(85) << endl;

    return 0;
}

/*
Output:

1 1 1 2 1 4 6

Approach:

Maintain a monotonic decreasing stack.

Each stack element stores:

{price, span}

When a new price arrives:
1. Start span at 1.
2. Remove all previous prices <= current price.
3. Add their stored spans to the current span.
4. Push {price, span} onto the stack.

Example:

Prices:
100 80 60 70

For 70:

Stack before:
{100,1}
{80,1}
{60,1}

60 <= 70, so:
span = 1 + 1 = 2

Now:
{100,1}
{80,1}

Push:
{70,2}

The stored span lets us skip multiple previous days
instead of checking them one by one.

Time Complexity:
O(n) amortized

Space Complexity:
O(n)
*/
