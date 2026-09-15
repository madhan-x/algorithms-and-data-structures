#include <iostream>
#include <string>
#include <queue>
using namespace std;

/*
Problem:
LeetCode 649 - Dota2 Senate

Difficulty:
Medium

Pattern:
Queue + Greedy Simulation

Approach:
Store the indices of Radiant and Dire senators in separate queues.

The senator with the smaller index gets to act first and bans
a senator from the opposite party.

After acting, the winning senator is pushed back with index + n,
representing their turn in the next round.

Continue until one party has no senators left.

Time Complexity: O(n)

Space Complexity: O(n)

Example:

Input:
"RDD"

Radiant indices: [0]
Dire indices:    [1, 2]

Compare:
R(0) vs D(1)

0 < 1
Radiant acts first and bans Dire.

Push Radiant back as:
0 + 3 = 3

Radiant: [3]
Dire:    [2]

Compare:
R(3) vs D(2)

2 < 3
Dire acts first and bans Radiant.

Radiant queue becomes empty.

Output:
"Dire"
*/

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant;
        queue<int> dire;

        int n = senate.length();

        // Store indices of both parties
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            }
            else {
                dire.push(i);
            }
        }

        // Compare senators based on who gets their turn first
        while (!radiant.empty() && !dire.empty()) {
            int ri = radiant.front();
            radiant.pop();

            int di = dire.front();
            dire.pop();

            if (ri < di) {
                // Radiant acts first and survives to next round
                radiant.push(ri + n);
            }
            else {
                // Dire acts first and survives to next round
                dire.push(di + n);
            }
        }

        // The party with remaining senators wins
        if (!radiant.empty()) {
            return "Radiant";
        }

        return "Dire";
    }
};

int main() {
    string senate;
    cin >> senate;

    Solution obj;

    cout << obj.predictPartyVictory(senate);

    return 0;
}
