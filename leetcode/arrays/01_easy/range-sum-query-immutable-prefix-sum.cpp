
#include <iostream>
#include <vector>
using namespace std;

class NumArray {
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);

    cout << numArray.sumRange(0, 2) << '\n';
    cout << numArray.sumRange(2, 5) << '\n';
    cout << numArray.sumRange(0, 5) << '\n';

    return 0;
}
