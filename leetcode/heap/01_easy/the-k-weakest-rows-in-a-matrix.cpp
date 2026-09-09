#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem:
LeetCode 1337 - The K Weakest Rows in a Matrix

Difficulty:
Easy

Pattern:
Min Heap / Priority Queue

Approach:
For every row, count the number of soldiers (1s).

Store:
{number of soldiers, row index}

in a Min Heap.

Since pair compares the first value first and then the second value,
the weakest row comes first.

If two rows have the same number of soldiers,
the smaller row index gets priority.

Pop the heap k times to get the k weakest rows.

Time Complexity:
O(m * n + m log m)

Space Complexity:
O(m)

where:
m = number of rows
n = number of columns
*/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        // Min Heap:
        // First compare soldier count,
        // then compare row index.
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Count soldiers in every row
        for (int i = 0; i < mat.size(); i++) {

            int count = 0;

            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    count++;
                }
            }

            // Store {soldiers, row index}
            pq.push({count, i});
        }

        vector<int> ans;

        // Extract k weakest rows
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

int main() {

    vector<vector<int>> mat = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };

    int k = 3;

    Solution obj;

    vector<int> ans = obj.kWeakestRows(mat, k);

    for (int row : ans) {
        cout << row << " ";
    }

    return 0;
}
