#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        // Traverse from the last digit
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            // If the current digit is less than 9,
            // simply increment it and return.
            if(digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }

            // If the digit is 9, it becomes 0
            // and the carry moves to the left.
            digits[i] = 0;
        }

        // If all digits were 9,
        // insert 1 at the beginning.
        digits.insert(digits.begin(), 1);

        return digits;
    }
};

/*
Problem:
LeetCode 66 - Plus One

Approach:
1. Traverse the digits from right to left.
2. If a digit is less than 9, increment it and return.
3. Otherwise, set it to 0 and carry to the previous digit.
4. If every digit was 9, insert 1 at the beginning.

Pattern:
Array Simulation

Time Complexity: O(n)

Space Complexity: O(1)
(Excluding the output array expansion when all digits are 9)
*/
