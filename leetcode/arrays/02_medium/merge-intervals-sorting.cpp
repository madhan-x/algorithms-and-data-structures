#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Sort intervals by starting time.
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(int i = 0; i < intervals.size(); i++) {

            // If there is no interval yet, or the current
            // interval does not overlap with the last interval.
            if(ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            }
            else {
                // Overlapping intervals:
                // Extend the ending point if necessary.
                ans.back()[1] =
                    max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};

int main() {

    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    Solution obj;

    vector<vector<int>> ans = obj.merge(intervals);

    for(auto interval : ans) {
        cout << "[" << interval[0]
             << "," << interval[1] << "] ";
    }

    return 0;
}

/*
Approach:
1. Sort all intervals by their starting value.
2. Compare each interval with the last interval in ans.
3. If they overlap, merge them.
4. Otherwise, add the current interval as a new interval.

Pattern:
Sorting + Intervals

Time Complexity:
O(n log n)

Space Complexity:
O(n)
- O(n) for the output vector.
*/
