#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int altitude = 0;
        int maxAltitude = 0;

        for(int i = 0; i < gain.size(); i++) {

            // Calculate the next altitude.
            altitude += gain[i];

            // Track the highest altitude reached.
            maxAltitude = max(maxAltitude, altitude);
        }

        return maxAltitude;
    }
};

int main() {

    Solution obj;

    vector<int> gain = {-5, 1, 5, 0, -7};

    cout << obj.largestAltitude(gain) << endl;

    return 0;
}

/*
Approach:
- Start at altitude 0.
- Add each gain value to the running altitude.
- Update the maximum altitude after every step.

Pattern:
Prefix Sum

Time Complexity: O(n)
Space Complexity: O(1)
*/
