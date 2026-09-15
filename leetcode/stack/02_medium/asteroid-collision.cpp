#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdlib>
using namespace std;

/*
Problem:
LeetCode 735 - Asteroid Collision

Difficulty:
Medium

Pattern:
Stack Simulation

Example:

Input:
[5, 10, -5]

Output:
[5, 10]

Explanation:
10 and -5 collide.
10 is larger, so -5 is destroyed.
*/


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for (int x : asteroids) {

            bool destroyed = false;

            /*
            A collision can happen only when:

            st.top() > 0
                -> previous asteroid is moving right

            x < 0
                -> current asteroid is moving left
            */
            while (!st.empty() && st.top() > 0 && x < 0) {

                // Previous asteroid is smaller
                if (st.top() < abs(x)) {
                    st.pop();
                }

                // Both asteroids have the same size
                else if (st.top() == abs(x)) {
                    st.pop();

                    // Current asteroid is also destroyed
                    destroyed = true;
                    break;
                }

                // Previous asteroid is larger
                else {
                    // Current asteroid is destroyed
                    destroyed = true;
                    break;
                }
            }

            // Push current asteroid if it survived
            if (!destroyed) {
                st.push(x);
            }
        }

        vector<int> ans;

        // Stack contains the final asteroids in reverse order
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};


int main() {

    int n;
    cin >> n;

    vector<int> asteroids(n);

    for (int i = 0; i < n; i++) {
        cin >> asteroids[i];
    }

    Solution obj;

    vector<int> ans = obj.asteroidCollision(asteroids);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}

/*
Approach:

Use a stack to store asteroids that are currently alive.

For every asteroid:

1. If no collision is possible, push it.
2. If the current asteroid is moving left (-)
   and the stack top is moving right (+),
   a collision occurs.
3. Compare their absolute sizes:
   - Stack top smaller -> pop it and continue.
   - Equal sizes -> both are destroyed.
   - Stack top larger -> current asteroid is destroyed.
4. Push the current asteroid if it survives.

Example:

[10, 2, -5]

10 -> [10]
2  -> [10, 2]

-5 collides with 2:
2 < 5 -> remove 2

Now -5 collides with 10:
10 > 5 -> -5 destroyed

Final:
[10]

Time Complexity:
O(n)

Space Complexity:
O(n)

Although there is a while loop, each asteroid is pushed
onto the stack once and popped at most once.
Therefore the overall complexity is O(n).
*/
