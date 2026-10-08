#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        // Calculate the total sum of all cards.
        int totalSum = 0;

        for(int x : cardPoints) {
            totalSum += x;
        }

        // Instead of choosing k cards directly,
        // find the minimum sum of the n-k cards
        // that remain in the middle.
        int windowSize = n - k;

        int windowSum = 0;

        // Calculate the first window of size n-k.
        for(int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }

        int minSum = windowSum;

        // Slide the window across the array.
        for(int i = windowSize; i < n; i++) {

            // Add the new element.
            windowSum += cardPoints[i];

            // Remove the element leaving the window.
            windowSum -= cardPoints[i - windowSize];

            // Find the minimum middle window.
            minSum = min(minSum, windowSum);
        }

        // The cards we take are everything outside
        // the minimum-sum middle window.
        return totalSum - minSum;
    }
};

int main() {

    Solution obj;

    vector<int> cardPoints = {
        1, 2, 3, 4, 5, 6, 1
    };

    int k = 3;

    cout << obj.maxScore(cardPoints) << endl;

    return 0;
}

/*
Example:

cardPoints = [1,2,3,4,5,6,1]
k = 3

Total sum = 22

We must leave n-k = 4 cards in the middle.

Windows of size 4:

[1,2,3,4] -> 10
[2,3,4,5] -> 14
[3,4,5,6] -> 18
[4,5,6,1] -> 16

Minimum window sum = 10

Maximum score:
22 - 10 = 12

Approach:
- Calculate the total sum.
- We take exactly k cards from the ends.
- Therefore, n-k consecutive cards remain untouched.
- Find the minimum sum window of size n-k.
- Subtract it from the total sum.

Pattern:
Sliding Window + Complement

Time Complexity:
O(n)

Space Complexity:
O(1)
*/
