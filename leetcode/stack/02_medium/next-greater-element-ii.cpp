#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Problem:
LeetCode 503 - Next Greater Element II

Difficulty:
Medium

Pattern:
Monotonic Stack + Circular Array

Example:

Input:
[1, 2, 1]

Output:
[2, -1, 2]

Approach:
Treat the array as circular by traversing it twice.

For every element:
- Use i % n to get its actual index.
- Remove smaller elements from the stack.
- The top of the stack is the next greater element.
- Push the current index onto the stack.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        // Initially, every answer is -1
        vector<int> ans(n, -1);

        // Store indices of elements whose
        // next greater element is not found yet
        stack<int> st;

        // Traverse the array twice to simulate circularity
        for (int i = 0; i < 2 * n; i++) {

            int index = i % n;

            // Remove elements smaller than the current element
            while (!st.empty() && nums[st.top()] < nums[index]) {
                ans[st.top()] = nums[index];
                st.pop();
            }

            // Only push indices during the first traversal.
            // This prevents duplicate indices in the stack.
            if (i < n) {
                st.push(index);
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    vector<int> ans = obj.nextGreaterElements(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}

/*
Example Input:

3
1 2 1

Example Output:

2 -1 2


Why traverse twice?

For:

[1, 2, 1]

The last 1 has no greater element to its right
in the normal array.

But because the array is circular, we continue
from the beginning:

1 -> 2

Therefore its answer is 2.

Using:

index = i % n

allows us to simulate:

0 1 2 0 1 2 */
