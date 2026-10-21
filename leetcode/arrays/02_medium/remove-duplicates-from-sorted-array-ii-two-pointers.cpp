
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // At most two occurrences of each value are allowed
        if (nums.size() <= 2) {
            return nums.size();
        }

        // First two elements can always remain
        int k = 2;

        for (int i = 2; i < nums.size(); i++) {
            // Keep nums[i] if it does not create a third occurrence
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        // Return the length of the modified array
        return k;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1, 2, 2, 3};

    int k = solution.removeDuplicates(nums);

    cout << "Length: " << k << '\n';
    cout << "Array: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    cout << '\n';
    return 0;
}
