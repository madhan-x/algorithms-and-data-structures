#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;

        for (int num : nums) {
            result.push_back(num * num);
        }

        sort(result.begin(), result.end());

        return result;
    }
};

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};

    Solution solution;
    vector<int> result = solution.sortedSquares(nums);

    cout << "Sorted squares: ";

    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}
