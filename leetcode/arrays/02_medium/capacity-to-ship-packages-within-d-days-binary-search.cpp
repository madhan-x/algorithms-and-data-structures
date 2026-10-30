
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // Minimum capacity must accommodate the heaviest package
        int left = *max_element(weights.begin(), weights.end());

        // Maximum capacity can ship all packages in one day
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;

            int requiredDays = 1;
            int load = 0;

            // Calculate the days needed with capacity = mid
            for (int weight : weights) {
                if (load + weight > mid) {
                    requiredDays++;
                    load = 0;
                }

                load += weight;
            }

            // If we can ship within the given days, try a smaller capacity
            if (requiredDays <= days) {
                right = mid;
            } else {
                // Otherwise, increase the capacity
                left = mid + 1;
            }
        }

        // The smallest feasible shipping capacity
        return left;
    }
};

int main() {
    Solution solution;

    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    cout << solution.shipWithinDays(weights, days) << '\n';

    return 0;
}
