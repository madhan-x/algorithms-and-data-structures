// Problem:    LeetCode 9 - Palindrome Number
// Difficulty: Easy
// Link:       https://leetcode.com/problems/palindrome-number/
//
// Approach:   Negative numbers cannot be palindromes (the leading '-' has no
//             match), so reject them up front. Otherwise, reverse all digits
//             of x into a long long and compare with the original — if they
//             match, x reads the same forwards and backwards.
//
// Time:       O(log10(x))  - one iteration per digit
// Space:      O(1)

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if(x < 0)
        {
            return false;
        }

        int temp = x;
        long long rev = 0;

        while(x != 0)
        {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }

        return temp == rev;
    }
};
