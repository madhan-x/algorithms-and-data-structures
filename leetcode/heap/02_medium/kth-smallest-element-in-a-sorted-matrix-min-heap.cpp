#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
    LeetCode 378: Kth Smallest Element in a Sorted Matrix

    Difficulty: Medium
    Pattern: Min Heap / Priority Queue

    Approach:
    1. Insert every element of the matrix into a min heap.
    2. Remove the smallest element k - 1 times.
    3. The element at the top is the kth smallest element.

    Time Complexity: O(n^2 log(n^2))
    Space Complexity: O(n^2)
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        // Min heap: smallest element stays at the top
        priority_queue<int, vector<int>, greater<int>> pq;

        // Insert all matrix elements into the heap
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                pq.push(matrix[i][j]);
            }
        }

        // Remove the first k - 1 smallest elements
        while (k > 1) {
            pq.pop();
            k--;
        }

        // The top is now the kth smallest element
        return pq.top();
    }
};

int main() {

    Solution solution;

    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };

    int k = 8;

    cout << "Kth smallest element: "
         << solution.kthSmallest(matrix, k)
         << endl;

    return 0;
}
