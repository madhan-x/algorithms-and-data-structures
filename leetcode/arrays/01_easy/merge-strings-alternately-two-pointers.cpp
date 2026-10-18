
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i = 0, j = 0;

        // Continue until both strings are fully processed
        while (i < word1.size() || j < word2.size()) {
            // Append the next character from word1 if available
            if (i < word1.size()) {
                ans += word1[i++];
            }

            // Append the next character from word2 if available
            if (j < word2.size()) {
                ans += word2[j++];
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;

    cout << solution.mergeAlternately("abc", "pqr") << '\n';
    cout << solution.mergeAlternately("ab", "pqrs") << '\n';
    cout << solution.mergeAlternately("abcd", "pq") << '\n';

    return 0;
}
