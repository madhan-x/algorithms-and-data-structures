
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells,
                                vector<int>& potions,
                                long long success) {
        // Sort potions so binary search can find the first successful one
        sort(potions.begin(), potions.end());

        int n = static_cast<int>(potions.size());
        vector<int> ans;

        for (int spell : spells) {
            int left = 0;
            int right = n;

            // Find the first potion that reaches the success threshold
            while (left < right) {
                int mid = left + (right - left) / 2;

                // Use long long to prevent multiplication overflow
                if (1LL * spell * potions[mid] >= success) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }

            // Every potion from left to the end forms a successful pair
            ans.push_back(n - left);
        }

        return ans;
    }
};

int main() {
    Solution solution;

    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 7;

    vector<int> result = solution.successfulPairs(spells, potions, success);

    for (int count : result) {
        cout << count << " ";
    }

    cout << '\n';
    return 0;
}
