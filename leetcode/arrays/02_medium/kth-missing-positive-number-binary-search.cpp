
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = static_cast<int>(arr.size()) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Count positive integers missing before arr[mid]
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                // The kth missing number is farther to the right
                left = mid + 1;
            } else {
                // The kth missing number is at or before mid
                right = mid - 1;
            }
        }

        // left is the number of array elements before the kth missing number
        return left + k;
    }
};

int main() {
    Solution solution;

    vector<int> arr = {2, 3, 4, 7, 11};
    cout << solution.findKthPositive(arr, 5) << '\n';

    return 0;
}
