#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        // Sort the array.
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Case 1:
        // Product of the three largest numbers.
        int product1 =
            nums[n - 1] * nums[n - 2] * nums[n - 3];

        // Case 2:
        // Two smallest negative numbers produce
        // a positive value when multiplied together,
        // then multiply by the largest number.
        int product2 =
            nums[0] * nums[1] * nums[n - 1];

        return max(product1, product2);
    }
};

int main() {

    Solution sol;

    vector<int> nums = {-10, -10, 5, 2};

    cout << sol.maximumProduct(nums) << endl;

    return 0;
}

/*
Approach:
1. Sort the array.
2. Check the product of the three largest numbers.
3. Check the product of the two smallest numbers
   and the largest number.
4. Return the larger product.

Pattern:
Sorting + Greedy Observation

Time Complexity:
O(n log n)

Space Complexity:
O(1) auxiliary space
*/
