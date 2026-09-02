#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
Problem:
LeetCode 2810 - Faulty Keyboard

Difficulty:
Easy

Pattern:
String Simulation

Approach:
Traverse the input string character by character.

- If the character is 'i', reverse the current answer.
- Otherwise, append the character to the answer.

Return the final constructed string.

Example:

Input:
string = "string"

Process:

s -> "s"
t -> "st"
r -> "str"
i -> reverse("str") = "rts"
n -> "rtsn"
g -> "rtsng"

Output:
"rtsng"

Time Complexity:
O(n²) in the worst case due to repeated reversing.

Space Complexity:
O(n)
*/

class Solution {
public:
    string finalString(string s) {
        string ans = "";

        for (char c : s) {

            // Faulty keyboard reverses the current string
            if (c == 'i') {
                reverse(ans.begin(), ans.end());
            }
            else {
                ans += c;
            }
        }

        return ans;
    }
};

int main() {
    string s;
    cin >> s;

    Solution obj;

    cout << obj.finalString(s);

    return 0;
}
