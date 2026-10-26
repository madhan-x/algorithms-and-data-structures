
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Align mid to an even index
            if (mid % 2 == 1) {
                mid--;
            }

            // If the pair is intact, the single element is to the right
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else {
                // The pair is broken, so the single element is at mid or left
                right = mid;
            }
        }

        // Both pointers converge at the single element
        return nums[left];
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << solution.singleNonDuplicate(nums) << '\n';

    return 0;
}
