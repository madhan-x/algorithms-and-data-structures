/*
 * Problem:    LC 2390 - Removing Stars From a String
 * Difficulty: Medium
 * Pattern:    Stack
 * Link:       https://leetcode.com/problems/removing-stars-from-a-string/
 *
 * Approach:   Walk the string left-to-right. Push every non-star character
 *             onto the stack; for every star, pop the most recent character
 *             (stars always have a character to remove by the problem
 *             guarantee). At the end, drain the stack into a string and
 *             reverse it to recover the original order.
 *
 * Time:       O(n) - one pass + one drain
 * Space:      O(n) for the stack
 *
 * Example:
 *   Input:  s = "leet**cod*e"
 *   Output: "lecoe"
 */

#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == '*') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    if (sol.removeStars("leet**cod*e") != "lecoe") return 1;
    if (sol.removeStars("erase*****")      != "")   return 1;
    return 0;
}
