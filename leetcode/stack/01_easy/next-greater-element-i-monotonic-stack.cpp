#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

/*
Problem:
LeetCode 496 - Next Greater Element I

Difficulty:
Easy

Pattern:
Monotonic Stack + Hash Map

Example:

Input:
nums1 = [4, 1, 2]
nums2 = [1, 3, 4, 2]

Output:
[-1, 3, -1]
*/

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        stack<int> st;
        unordered_map<int, int> mp;

        // Traverse nums2 from right to left
        for(int i = nums2.size() - 1; i >= 0; i--)
        {
            // Remove elements that cannot be the next greater element
            while(!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }

            // The remaining top is the next greater element
            if(st.empty())
            {
                mp[nums2[i]] = -1;
            }
            else
            {
                mp[nums2[i]] = st.top();
            }

            // Add current element to the stack
            st.push(nums2[i]);
        }

        vector<int> ans;

        // Look up the answer for every element in nums1
        for(int x : nums1)
        {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};

int main()
{
    int n1;
    cin >> n1;

    vector<int> nums1(n1);

    for(int i = 0; i < n1; i++)
    {
        cin >> nums1[i];
    }

    int n2;
    cin >> n2;

    vector<int> nums2(n2);

    for(int i = 0; i < n2; i++)
    {
        cin >> nums2[i];
    }

    Solution obj;

    vector<int> ans = obj.nextGreaterElement(nums1, nums2);

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}

/*
Approach:

1. Traverse nums2 from right to left.
2. Maintain a decreasing monotonic stack.
3. Remove every element smaller than or equal to the current element.
4. The remaining stack top is the next greater element.
5. Store each answer in an unordered_map.
6. Use the map to build the answer for nums1.

Time Complexity:
O(n + m)

Space Complexity:
O(n)

where:
n = nums2.size()
m = nums1.size()
*/
