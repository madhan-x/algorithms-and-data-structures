
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = static_cast<int>(arr.size()) - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If the slope is rising, the peak is to the right
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                // Falling slope means the peak is at mid or to the left
                right = mid;
            }
        }

        // Both pointers converge at the peak
        return left;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {0, 2, 5, 3, 1};

    cout << solution.peakIndexInMountainArray(arr) << '\n';

    return 0;
}
