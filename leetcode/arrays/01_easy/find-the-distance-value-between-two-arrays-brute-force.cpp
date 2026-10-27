
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;

        // Check every element in arr1
        for (int x : arr1) {
            bool valid = true;

            // Check its distance from every element in arr2
            for (int y : arr2) {
                if (abs(x - y) <= d) {
                    // Found an element too close to x
                    valid = false;
                    break;
                }
            }

            // Count x only if every distance is greater than d
            if (valid) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution solution;

    vector<int> arr1 = {4, 5, 8};
    vector<int> arr2 = {10, 9, 1, 8};
    int d = 2;

    cout << solution.findTheDistanceValue(arr1, arr2, d) << '\n';

    return 0;
}
