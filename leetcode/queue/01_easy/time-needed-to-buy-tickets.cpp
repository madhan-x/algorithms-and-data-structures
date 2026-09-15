#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem:
LeetCode 2073 - Time Needed to Buy Tickets

Difficulty:
Easy

Pattern:
Queue Simulation

Example:

Input:
tickets = [2, 3, 2]
k = 2

Output:
6
*/

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;

        // Add all person indices to the queue
        for (int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }

        int time = 0;

        while (!q.empty()) {
            int person = q.front();
            q.pop();

            // Current person buys one ticket
            tickets[person]--;
            time++;

            // If person k bought their final ticket, return time
            if (person == k && tickets[person] == 0) {
                return time;
            }

            // If the person still needs tickets,
            // send them back to the queue
            if (tickets[person] > 0) {
                q.push(person);
            }
        }

        return time;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> tickets(n);

    for (int i = 0; i < n; i++) {
        cin >> tickets[i];
    }

    int k;
    cin >> k;

    Solution obj;

    cout << obj.timeRequiredToBuy(tickets, k);

    return 0;
}

/*
Approach:

Simulate the ticket-buying process using a queue.

1. Push all person's indices into the queue.
2. Take the front person.
3. Let them buy one ticket.
4. Increase time by 1.
5. If they still need tickets, push them back.
6. Stop when person k buys their final ticket.

Example:

tickets = [2, 3, 2]
k = 2

Queue simulation:

Queue: [0,1,2]

Person 0 buys -> [1,3,2] -> time = 1
Person 1 buys -> [1,2,2] -> time = 2
Person 2 buys -> [1,2,1] -> time = 3

Person 0 buys -> [0,2,1] -> time = 4
Person 1 buys -> [0,1,1] -> time = 5
Person 2 buys -> [0,1,0] -> time = 6

Person k has finished.

Answer = 6

Time Complexity: O(total tickets bought until person k finishes)

Space Complexity: O(n)
*/
