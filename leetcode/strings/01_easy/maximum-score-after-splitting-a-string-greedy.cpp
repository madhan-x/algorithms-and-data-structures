
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0, maxScore = 0;

        // Count all ones initially
        for (char c : s) {
            if (c == '1') {
                ones++;
            }
        }

        // Try every valid split, leaving at least one character on the right
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') {
                zeros++;
            } else {
                ones--;
            }

            // Score = zeros on the left + ones on the right
            maxScore = max(maxScore, zeros + ones);
        }

        return maxScore;
    }
};

int main() {
    Solution solution;

    cout << solution.maxScore("011101") << '\n';
    cout << solution.maxScore("00111") << '\n';
    cout << solution.maxScore("1111") << '\n';

    return 0;
}
