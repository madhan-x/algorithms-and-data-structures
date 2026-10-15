
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        // Match characters of s in order within t
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        // All characters of s must be matched
        return i == s.size();
    }
};

int main() {
    Solution solution;

    cout << boolalpha;
    cout << solution.isSubsequence("abc", "ahbgdc") << '\n';
    cout << solution.isSubsequence("axc", "ahbgdc") << '\n';
    cout << solution.isSubsequence("", "ahbgdc") << '\n';

    return 0;
}
