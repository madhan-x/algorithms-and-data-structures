// Problem:    LeetCode 7 - Reverse Integer
// Difficulty: Medium
// Link:       https://leetcode.com/problems/reverse-integer/
//
// Approach:   Pop digits from x one at a time using modulo/division, and
//             push them onto rev by multiplying by 10 and adding. Before
//             each push, check whether the next rev would overflow int —
//             if it would, return 0.
//
// Time:       O(log10(|x|))  - one iteration per digit
// Space:      O(1)

#include <climits>

class Solution
{
public:
    int reverse(int x)
    {
        int digit = 0;
        int rev = 0;

        while(x != 0)
        {
            // Pre-check: would the next rev*10 overflow?
            if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
            {
                return 0;
            }
            if(rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))
            {
                return 0;
            }

            digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }

        return rev;
    }
};
