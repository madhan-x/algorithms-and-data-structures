#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // Frequency of characters required from s1.
        int need[26] = {0};

        // Frequency of characters in the current window of s2.
        int window[26] = {0};

        // Count characters in s1.
        for(char c : s1) {
            need[c - 'a']++;
        }

        // A valid permutation must have the same length as s1.
        int k = s1.length();

        // Build a fixed-size sliding window in s2.
        for(int i = 0; i < s2.length(); i++) {

            // Add the new character entering the window.
            window[s2[i] - 'a']++;

            // Keep the window size exactly k.
            if(i >= k) {
                window[s2[i - k] - 'a']--;
            }

            // Once the window reaches size k,
            // compare its character frequencies with s1.
            if(i >= k - 1 &&
               equal(need, need + 26, window)) {
                return true;
            }
        }

        return false;
    }
};

int main() {

    Solution obj;

    string s1 = "ab";
    string s2 = "eidbaooo";

    cout << boolalpha
         << obj.checkInclusion(s1, s2) << endl;

    return 0;
}

/*
Example:

s1 = "ab"
s2 = "eidbaooo"

Window:
"ei"  -> frequencies don't match
"id"  -> don't match
"db"  -> don't match
"ba"  -> frequencies match

"ba" is a permutation of "ab".

Output:
true

Approach:
- Count the frequency of every character in s1.
- Maintain a fixed-size window of length s1.length()
  while traversing s2.
- Compare the frequency array of the current window
  with the required frequency array.

Pattern:
Fixed-Size Sliding Window + Frequency Array

Time Complexity:
O(n * 26) = O(n)

Space Complexity:
O(1)
*/
