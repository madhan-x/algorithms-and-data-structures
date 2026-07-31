#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();

        // Stores product of all elements to the left
        vector<int> left(n);

        // Stores product of all elements to the right
        vector<int> right(n);

        // Final answer
        vector<int> ans(n);

        // No elements on the left of the first element
        left[0] = 1;

        // Build left product array
        for(int i = 1; i < n; i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }

        // No elements on the right of the last element
        right[n - 1] = 1;

        // Build right product array
        for(int i = n - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }

        // Multiply left and right products
        for(int i = 0; i < n; i++)
        {
            ans[i] = left[i] * right[i];
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> ans = obj.productExceptSelf(nums);

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}

/*
Problem:
LeetCode 238 - Product of Array Except Self

Approach:
1. Build a prefix product array.
2. Build a suffix product array.
3. Multiply corresponding prefix and suffix values.
4. The result is the product of all elements except the current one.

Pattern:
Prefix Sum / Prefix & Suffix Products

Time Complexity: O(n)

Space Complexity: O(n)
*/
