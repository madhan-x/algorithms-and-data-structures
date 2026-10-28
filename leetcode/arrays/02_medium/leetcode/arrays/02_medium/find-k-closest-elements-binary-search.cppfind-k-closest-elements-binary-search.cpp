
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = static_cast<int>(arr.size()) - k;

        // Search for the best starting index of a window of size k
        while (left < right) {
            int mid = left + (right - left) / 2;

            // Compare x's distance from the two competing window boundaries
            if (x - arr[mid] > arr[mid + k] - x) {
                // The window starting at mid is too far to the left
                left = mid + 1;
            } else {
                // Keep the left window, including ties
                right = mid;
            }
        }

        // Return the k elements in the closest window
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

int main() {
    Solution solution;

    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> result = solution.findClosestElements(arr, 4, 3);

    for (int value : result) {
        cout << value << " ";
    }

    cout << '\n';
    return 0;
}
