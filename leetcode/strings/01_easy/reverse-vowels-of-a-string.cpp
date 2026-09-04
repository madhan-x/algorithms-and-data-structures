#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
Problem:
LeetCode 345 - Reverse Vowels of a String

Difficulty:
Easy

Pattern:
Two Pointers

Example:

Input:
"hello"

Output:
"holle"

Approach:
Use two pointers:

- i starts from the beginning.
- j starts from the end.

Move i forward until a vowel is found.
Move j backward until a vowel is found.

Swap both vowels and continue until the pointers meet.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:

    // Check whether a character is a vowel
    bool isVowel(char c) {
        return string("aeiouAEIOU").find(c) != string::npos;
    }

    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {

            // Find vowel from the left
            while (i < j && !isVowel(s[i])) {
                i++;
            }

            // Find vowel from the right
            while (i < j && !isVowel(s[j])) {
                j--;
            }

            // Swap the vowels
            swap(s[i], s[j]);

            i++;
            j--;
        }

        return s;
    }
};

int main() {
    string s;
    cin >> s;

    Solution obj;

    cout << obj.reverseVowels(s);

    return 0;
}
