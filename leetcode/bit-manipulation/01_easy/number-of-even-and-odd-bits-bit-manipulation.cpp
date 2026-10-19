
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2, 0);
        int pos = 0;

        // Process each bit from right to left
        while (n > 0) {
            // Count set bits at even or odd positions
            if (n & 1) {
                ans[pos % 2]++;
            }

            // Move to the next bit
            n >>= 1;
            pos++;
        }

        // ans[0] = set bits at even positions
        // ans[1] = set bits at odd positions
        return ans;
    }
};

int main() {
    Solution solution;

    vector<int> result = solution.evenOddBit(17);

    for (int x : result) {
        cout << x << " ";
    }

    cout << '\n';
    return 0;
}
