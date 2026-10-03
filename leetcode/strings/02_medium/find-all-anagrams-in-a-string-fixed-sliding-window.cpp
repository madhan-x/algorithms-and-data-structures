#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        // If s is shorter than p, an anagram is impossible.
        if(s.length() < p.length())
            return ans;

        // Frequency of characters required from p.
        int need[26] = {0};

        // Frequency of characters in the current window of s.
        int window[26] = {0};

        // Count characters in p.
        for(char c : p) {
            need[c - 'a']++;
        }

        // Every anagram must have exactly p.length() characters.
        int k = p.length();

        // Build a fixed-size window in s.
        for(int i = 0; i < s.length(); i++) {

            // Add the new character.
            window[s[i] - 'a']++;

            // Remove the character that leaves the window.
            if(i >= k) {
                window[s[i - k] - 'a']--;
            }

            // Once the window reaches size k,
            // check whether its frequency matches p.
            if(i >= k - 1) {

                if(equal(need, need + 26, window)) {

                    // Store the starting index of the anagram.
                    ans.push_back(i - k + 1);
                }
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s = "cbaebabacd";
    string p = "abc";

    vector<int> ans = obj.findAnagrams(s, p);

    for(int index : ans) {
        cout << index << " ";
    }

    return 0;
}

/*
Example:

s = "cbaebabacd"
p = "abc"

Anagrams of "abc":

"cba" -> index 0
"bac" -> index 6

Output:
0 6

Approach:
- Count the frequency of every character in p.
- Maintain a fixed-size window of length p.length()
  while traversing s.
- Compare the frequency of the current window with p.
- Store the starting index whenever they match.

Pattern:
Fixed-Size Sliding Window + Frequency Array

Time Complexity:
O(n * 26) = O(n)

Space Complexity:
O(1)
*/
