#include <iostream>
#include <vector>
using namespace std;

// LeetCode 53 - Maximum Subarray
// Approach: Kadane's Algorithm
// - Track the running sum of the current subarray.
// - At each element, decide whether to extend the current subarray
//   or restart from the current element (drop a negative prefix).
// - Track the maximum sum seen so far.
//
// Edge case: if all numbers are negative, the answer is the largest
// (least negative) single element. Initializing sum and maxi to
// nums[0] handles this without a separate pass.

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int sum = nums[0];
    int maxi = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        sum = max(nums[i], sum + nums[i]);
        maxi = max(maxi, sum);
    }

    cout << maxi;
    return 0;
}
