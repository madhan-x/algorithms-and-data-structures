#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        // Store all jewel types in a Hash Set.
        unordered_set<char> us;

        for(char c : jewels) {
            us.insert(c);
        }

        int count = 0;

        // Check every stone.
        for(char c : stones) {

            // If the stone is a jewel, count it.
            if(us.count(c)) {
                count++;
            }
        }

        return count;
    }
};

int main() {

    Solution obj;

    string jewels = "aA";
    string stones = "aAAbbbb";

    cout << obj.numJewelsInStones(jewels, stones) << endl;

    return 0;
}

/*
Example:

jewels = "aA"
stones = "aAAbbbb"

Jewels:
a, A

Stones:
a A A b b b b

Jewels found:
a, A, A

Answer:
3

Approach:
- Store all jewel characters in an unordered_set.
- Traverse the stones.
- If a stone exists in the set, increment the count.

Pattern:
Hash Set

Time Complexity:
O(n + m)

Space Complexity:
O(m)

where:
n = number of stones
m = number of jewels
*/
