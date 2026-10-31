
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // Check whether enough flowers exist to make m bouquets
        if (1LL * m * k > bloomDay.size()) {
            return -1;
        }

        // Minimum and maximum possible answer
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            int bouquets = 0;
            int flowers = 0;

            // Count bouquets possible by day mid
            for (int day : bloomDay) {
                if (day <= mid) {
                    flowers++;

                    // Form a bouquet when k consecutive flowers bloom
                    if (flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    // An unbloomed flower breaks the consecutive sequence
                    flowers = 0;
                }
            }

            // Check whether we can make the required bouquets
            if (bouquets >= m) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main() {
    Solution solution;

    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;

    cout << solution.minDays(bloomDay, m, k) << '\n';

    return 0;
}
