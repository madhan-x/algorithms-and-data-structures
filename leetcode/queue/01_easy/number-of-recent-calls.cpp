#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
Problem:
LeetCode 933 - Number of Recent Calls

Difficulty:
Easy

Pattern:
Queue / Sliding Window

Approach:
Each ping happens at time t.

We need to count all requests that happened in the range:

[t - 3000, t]

1. Push the current ping time into the queue.
2. Remove all ping times smaller than t - 3000.
3. The remaining queue size represents valid recent calls.

Time Complexity:
O(n) overall for n ping calls.
Each timestamp is pushed once and popped at most once.

Space Complexity:
O(n)

Example:

ping(1)
Queue: [1]
Return: 1

ping(100)
Queue: [1, 100]
Return: 2

ping(3001)
Queue: [1, 100, 3001]
Return: 3

ping(3002)
Remove 1 because 1 < 2

Queue: [100, 3001, 3002]
Return: 3
*/

class RecentCounter {
private:
    queue<int> q;

public:
    RecentCounter() {
    }

    int ping(int t) {
        // Add current request time
        q.push(t);

        // Remove requests outside the range [t - 3000, t]
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        // Remaining requests are within the valid range
        return q.size();
    }
};

int main() {
    RecentCounter obj;

    vector<int> calls = {1, 100, 3001, 3002};

    for (int t : calls) {
        cout << obj.ping(t) << " ";
    }

    return 0;
}
