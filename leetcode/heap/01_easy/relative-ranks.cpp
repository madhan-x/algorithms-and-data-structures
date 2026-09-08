#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

/*
Problem:
LeetCode 506 - Relative Ranks

Difficulty:
Easy

Pattern:
Max Heap / Priority Queue

Approach:
Store each score along with its original index in a max heap.

The max heap automatically gives the highest score first.

For every extracted score:
- Rank 1 -> Gold Medal
- Rank 2 -> Silver Medal
- Rank 3 -> Bronze Medal
- Remaining ranks -> Rank number

Use the stored original index to place the result
in the correct position.

Time Complexity: O(n log n)
Space Complexity: O(n)

Example:

Input:
5
10 3 8 9 4

Ranking:
10 -> Gold Medal
9  -> Silver Medal
8  -> Bronze Medal
4  -> 4
3  -> 5

Output:
Gold Medal 5 Bronze Medal Silver Medal 4
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        // Max heap stores {score, original index}
        priority_queue<pair<int, int>> pq;

        // Insert scores with their original indices
        for (int i = 0; i < score.size(); i++) {
            pq.push({score[i], i});
        }

        vector<string> ans(score.size());

        int rank = 1;

        // Process scores from highest to lowest
        while (!pq.empty()) {

            int index = pq.top().second;
            pq.pop();

            // Assign medals to top 3 ranks
            if (rank == 1) {
                ans[index] = "Gold Medal";
            }
            else if (rank == 2) {
                ans[index] = "Silver Medal";
            }
            else if (rank == 3) {
                ans[index] = "Bronze Medal";
            }
            else {
                ans[index] = to_string(rank);
            }

            rank++;
        }

        return ans;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> score(n);

    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }

    Solution obj;

    vector<string> ans = obj.findRelativeRanks(score);

    for (string rank : ans) {
        cout << rank << " ";
    }

    return 0;
}
