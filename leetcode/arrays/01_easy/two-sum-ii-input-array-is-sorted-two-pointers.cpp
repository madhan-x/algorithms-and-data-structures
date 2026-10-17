
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = static_cast<int>(numbers.size()) - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                // LeetCode requires 1-based indices
                return {left + 1, right + 1};
            } else if (sum < target) {
                // Increase the sum by moving left to a larger value
                left++;
            } else {
                // Decrease the sum by moving right to a smaller value
                right--;
            }
        }

        // No valid pair found
        return {};
    }
};

int main() {
    Solution solution;

    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = solution.twoSum(numbers, target);

    for (int index : result) {
        cout << index << " ";
    }

    cout << '\n';
    return 0;
}
