#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {

        int count = 0;

        // Check every substring of size 3.
        for(int i = 0; i + 2 < s.length(); i++) {

            // All three characters must be different.
            if(s[i] != s[i + 1] &&
               s[i + 1] != s[i + 2] &&
               s[i] != s[i + 2]) {

                count++;
            }
        }

        return count;
    }
};

int main() {

    Solution obj;

    string s = "xyzzaz";

    cout << obj.countGoodSubstrings(s) << endl;

    return 0;
}

/*
Example:

s = "xyzzaz"

Substrings of size 3:

"xyz" -> good
"yzz" -> not good
"zza" -> not good
"zaz" -> not good

Answer = 1

Approach:
- Traverse every substring of size 3.
- Check whether all three characters are different.
- Count the valid substrings.

Pattern:
Fixed-Size Sliding Window

Time Complexity:
O(n)

Space Complexity:
O(1)
*/
