#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem:
LeetCode 1046 - Last Stone Weight

Difficulty:
Easy

Pattern:
Priority Queue / Max Heap

Approach:
Use a max heap to always access the two heaviest stones.

1. Insert all stones into a max heap.
2. Remove the two largest stones.
3. If their weights are different, push their difference back.
4. Repeat until at most one stone remains.
5. Return the remaining stone's weight, or 0 if no stones remain.

Time Complexity: O(n log n)
Space Complexity: O(n)

Example:
Input:
6
2 7 4 1 8 1

Output:
1
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        // Insert all stones into the max heap
        for (int stone : stones) {
            pq.push(stone);
        }

        // Keep smashing the two heaviest stones
        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();

            int second = pq.top();
            pq.pop();

            // Push the remaining weight if stones are different
            if (first != second) {
                pq.push(first - second);
            }
        }

        // No stones remaining
        if (pq.empty()) {
            return 0;
        }

        return pq.top();
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> stones(n);

    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    Solution obj;

    cout << obj.lastStoneWeight(stones);

    return 0;
}
