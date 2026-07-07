/*
 * Problem:    LC 28 - Find the Index of the First Occurrence in a String
 * Difficulty: Easy
 * Pattern:    STL (string::find)
 * Link:       https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
 *
 * Approach:   Use std::string::find to locate the first occurrence of the
 *             needle in the haystack. If not found, string::npos is
 *             returned; convert that to -1 as required by the problem.
 *
 * Time:       O(n * m) - library implementation
 * Space:      O(1)
 *
 * Example:
 *   Input:  haystack = "sadbutsad", needle = "sad"
 *   Output: 0
 */

#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        // Empty needle matches at index 0
        if(needle.empty()) {
            return 0;
        }

        // Locate the first occurrence
        size_t pos = haystack.find(needle);

        // Not found -> return -1
        if(pos == string::npos) {
            return -1;
        }

        return static_cast<int>(pos);
    }
};

int main() {
    Solution sol;

    // Test 1: match at start
    if(sol.strStr("sadbutsad", "sad") != 0) return 1;

    // Test 2: no match
    if(sol.strStr("leetcode", "leeto") != -1) return 1;

    // Test 3: empty needle
    if(sol.strStr("abc", "") != 0) return 1;

    return 0;
}
