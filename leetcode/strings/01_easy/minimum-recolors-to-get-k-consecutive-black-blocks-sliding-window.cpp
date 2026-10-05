#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int whiteCount = 0;
        int minRecolors = INT_MAX;
        int left = 0;

        for(int right = 0; right < blocks.length(); right++) {

            // Add the new block entering the window.
            if(blocks[right] == 'W') {
                whiteCount++;
            }

            // Keep the window size exactly k.
            if(right - left + 1 > k) {

                // Remove the block leaving the window.
                if(blocks[left] == 'W') {
                    whiteCount--;
                }

                left++;
            }

            // Once the window reaches size k,
            // the number of white blocks equals the
            // number of recolors required.
            if(right - left + 1 == k) {
                minRecolors = min(minRecolors, whiteCount);
            }
        }

        return minRecolors;
    }
};

int main() {

    Solution obj;

    string blocks = "WBBWWBB";
    int k = 7;

    cout << obj.minimumRecolors(blocks, k) << endl;

    return 0;
}

/*
Approach:
- Maintain a fixed-size window of k blocks.
- Count the number of white blocks inside the window.
- Every white block must be recolored to black.
- Therefore, the number of white blocks is the number
  of recolors needed for that window.
- Keep the minimum across all windows.

Pattern:
Fixed-Size Sliding Window

Time Complexity:
O(n)

Space Complexity:
O(1)
*/
