#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem:
LeetCode 1700 - Number of Students Unable to Eat Lunch

Difficulty:
Easy

Pattern:
Queue Simulation

Approach:
Students stand in a queue and sandwiches are served in order.

1. If the front student prefers the current sandwich:
   - Remove the student.
   - Move to the next sandwich.
   - Reset the rotation count.

2. Otherwise:
   - Move the student to the back of the queue.
   - Increment the rotation count.

3. If every remaining student has been rotated once without
   taking the current sandwich, no student can eat it.
   Stop the process.

Time Complexity:
O(n²) in the worst case.

Space Complexity:
O(n)
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;

        // Add all students to the queue
        for (int student : students) {
            q.push(student);
        }

        int sandwichIndex = 0;
        int count = 0;

        while (!q.empty()) {

            // Front student takes the sandwich
            if (q.front() == sandwiches[sandwichIndex]) {
                q.pop();
                sandwichIndex++;

                // Reset because a student successfully ate
                count = 0;
            }
            else {
                // Move the student to the back of the queue
                q.push(q.front());
                q.pop();

                count++;
            }

            // All remaining students rejected the sandwich
            if (count == q.size()) {
                break;
            }
        }

        return q.size();
    }
};

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};

    Solution obj;

    cout << obj.countStudents(students, sandwiches);

    return 0;
}
