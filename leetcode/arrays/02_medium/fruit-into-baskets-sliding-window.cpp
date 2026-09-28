#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        // Stores the frequency of each fruit type
        // inside the current window.
        unordered_map<int, int> mp;

        int left = 0;
        int maxLen = 0;

        // Expand the window using the right pointer.
        for(int right = 0; right < fruits.size(); right++) {

            // Add the current fruit to the window.
            mp[fruits[right]]++;

            // We can have at most 2 different fruit types.
            while(mp.size() > 2) {

                // Remove the fruit at the left side.
                mp[fruits[left]]--;

                // If no fruits of this type remain,
                // remove the type from the map.
                if(mp[fruits[left]] == 0)
                    mp.erase(fruits[left]);

                left++;
            }

            // Current window contains at most 2 fruit types.
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {

    Solution sol;

    vector<int> fruits = {
        1, 2, 1, 2, 3, 2, 2
    };

    cout << sol.totalFruit(fruits) << endl;

    return 0;
}

/*
Example:

Input:
[1, 2, 1, 2, 3, 2, 2]

We can carry only 2 types of fruit.

Longest valid subarray:
[1, 2, 1, 2]

Length = 4

Time Complexity:
O(n)

Space Complexity:
O(1) auxiliary space
(at most 3 fruit types are temporarily stored)
*/
