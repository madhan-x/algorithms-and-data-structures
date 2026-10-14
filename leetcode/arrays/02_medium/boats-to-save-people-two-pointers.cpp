
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Sort people by weight
        sort(people.begin(), people.end());

        int left = 0;
        int right = static_cast<int>(people.size()) - 1;
        int boats = 0;

        while (left <= right) {
            // Pair the lightest and heaviest if they fit together
            if (people[left] + people[right] <= limit) {
                left++;
            }

            // The heaviest person always gets a boat
            right--;
            boats++;
        }

        return boats;
    }
};

int main() {
    Solution solution;

    vector<int> people = {3, 2, 2, 1};
    cout << solution.numRescueBoats(people, 3) << '\n';

    return 0;
}
