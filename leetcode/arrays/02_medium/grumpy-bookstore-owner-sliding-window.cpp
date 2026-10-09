#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers,
                     vector<int>& grumpy,
                     int minutes) {

        int alreadySatisfied = 0;
        int extraSatisfied = 0;
        int maxExtra = 0;

        for(int i = 0; i < customers.size(); i++) {

            // Customers satisfied without using the technique.
            if(grumpy[i] == 0)
                alreadySatisfied += customers[i];

            // Potential additional customers satisfied.
            else
                extraSatisfied += customers[i];

            // Remove the element that leaves the window.
            if(i >= minutes && grumpy[i - minutes] == 1)
                extraSatisfied -= customers[i - minutes];

            // Track the maximum additional customers satisfied.
            maxExtra = max(maxExtra, extraSatisfied);
        }

        // Baseline satisfaction + best possible improvement.
        return alreadySatisfied + maxExtra;
    }
};

int main() {
    Solution obj;

    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy =    {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;

    cout << obj.maxSatisfied(customers, grumpy, minutes) << endl;

    return 0;
}

/*
Approach:
- Count customers already satisfied when grumpy[i] == 0.
- Maintain a window sum of customers who can be additionally
  satisfied when grumpy[i] == 1.
- Keep the maximum additional satisfaction over all windows.
- Add the baseline and maximum improvement.

Pattern:
Fixed-Size Sliding Window

Time Complexity: O(n)
Space Complexity: O(1)
*/
