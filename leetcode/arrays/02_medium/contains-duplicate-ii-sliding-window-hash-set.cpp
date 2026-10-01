#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        // Stores the elements inside the current window.
        unordered_set<int> window;

        for(int i = 0; i < nums.size(); i++) {

            // If the current number already exists
            // inside the window, its distance from i
            // is at most k.
            if(window.count(nums[i])) {
                return true;
            }

            // Add current element to the window.
            window.insert(nums[i]);

            // Keep only the previous k elements.
            if(window.size() > k) {
                window.erase(nums[i - k]);
            }
        }

        return false;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    cout << boolalpha
         << obj.containsNearbyDuplicate(nums, k) << endl;

    return 0;
}

/*
Example:

nums = [1,2,3,1]
k = 3

At index 3:
nums[3] = 1

1 already exists in the window.

Distance:
3 - 0 = 3

Since 3 <= k, return true.

Approach:
- Maintain a sliding window using an unordered_set.
- The window contains the previous k elements.
- If the current element already exists in the window,
  a nearby duplicate has been found.

Pattern:
Sliding Window + Hash Set

Time Complexity:
O(n) average

Space Complexity:
O(k)
*/
