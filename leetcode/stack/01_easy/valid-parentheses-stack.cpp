/*
 * Problem:    LC 20 - Valid Parentheses
 * Difficulty: Easy
 * Pattern:    Stack
 * Link:       https://leetcode.com/problems/valid-parentheses/
 *
 * Approach:   Push every opening bracket. For each closing bracket, pop the
 *             stack and verify it matches the corresponding opening type.
 *             The string is valid iff the stack is empty at the end.
 *
 * Time:       O(n)
 * Space:      O(n) for the stack
 *
 * Example:
 *   Input:  s = "()[]{}"
 *   Output: true
 */

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                st.pop();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    if (!sol.isValid("()[]{}")) return 1;
    if ( sol.isValid("(]"))     return 1;
    return 0;
}
