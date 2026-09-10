#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

/*
    LeetCode 2558: Take Gifts From the Richest Pile

    Difficulty: Easy
    Pattern: Max Heap / Priority Queue

    Approach:
    1. Put all gift piles into a max heap.
    2. For each operation:
       - Take the largest pile.
       - Replace it with floor(sqrt(pile)).
    3. Add all remaining gifts.

    Time Complexity: O(n + k log n)
    Space Complexity: O(n)
*/

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        // Add all gift piles to the max heap.
        for (int x : gifts) {
            pq.push(x);
        }

        // Perform k operations.
        while (k--) {
            int x = pq.top();
            pq.pop();

            // Replace the largest pile with floor(sqrt(x)).
            pq.push(sqrt(x));
        }

        // Calculate the total number of remaining gifts.
        long long ans = 0;

        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};

int main() {
    Solution solution;

    vector<int> gifts = {25, 64, 9, 4, 100};
    int k = 4;

    cout << "Remaining gifts: "
         << solution.pickGifts(gifts, k)
         << endl;

    return 0;
}
