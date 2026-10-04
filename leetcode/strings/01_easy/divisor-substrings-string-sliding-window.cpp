#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {

        // Convert the number into a string
        // so we can easily examine every k-digit substring.
        string s = to_string(num);

        int count = 0;

        // Check every substring of length k.
        for(int i = 0; i + k <= s.length(); i++) {

            // Convert the current substring back to an integer.
            int value = stoi(s.substr(i, k));

            // The divisor cannot be zero.
            if(value != 0 && num % value == 0) {
                count++;
            }
        }

        return count;
    }
};

int main() {

    Solution obj;

    int num = 240;
    int k = 2;

    cout << obj.divisorSubstrings(num, k) << endl;

    return 0;
}

/*
Example:

num = 240
k = 2

2-digit substrings:

"24" -> 240 % 24 == 0 -> valid
"40" -> 240 % 40 == 0 -> valid

Answer = 2

Approach:
- Convert the number to a string.
- Examine every substring of length k.
- Convert each substring to an integer.
- Check whether the number is divisible by that value.

Pattern:
Fixed-Size Sliding Window

Time Complexity:
O(n * k)
where n is the number of digits.

Space Complexity:
O(n)
because of the string representation.
*/
