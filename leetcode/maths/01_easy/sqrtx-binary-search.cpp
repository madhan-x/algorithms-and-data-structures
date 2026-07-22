#include <vector>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int low = 0;
        int high = x;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            // Prevent integer overflow
            long long square = 1LL * mid * mid;

            if(square == x)
            {
                return mid;
            }
            else if(square < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        // 'high' stores the integer square root
        return high;
    }
};

/*
Problem:
LeetCode 69 - Sqrt(x)

Approach:
1. Apply Binary Search on the range [0, x].
2. Calculate mid and its square.
3. If square equals x, return mid.
4. If square is smaller, search the right half.
5. Otherwise, search the left half.
6. When the loop ends, 'high' is the floor of the square root.

Pattern:
Binary Search on Answer

Time Complexity: O(log x)

Space Complexity: O(1)
*/
