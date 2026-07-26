#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Calculate total hours needed if Koko eats at speed k
    long long totalHours(vector<int>& piles, int k)
    {
        long long hours = 0;

        for(int pile : piles)
        {
            // Ceiling division
            hours += (pile + k - 1LL) / k;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h)
    {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        // Store the minimum valid eating speed
        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            long long hours = totalHours(piles, mid);

            // Current speed is sufficient
            if(hours <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            // Need to eat faster
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

/*
Problem:
LeetCode 875 - Koko Eating Bananas

Approach:
1. Binary Search on the possible eating speed.
2. For each speed, calculate the total hours required.
3. If Koko finishes within h hours,
   try a smaller speed.
4. Otherwise, increase the speed.
5. The smallest valid speed is the answer.

Pattern:
Binary Search on Answer

Time Complexity:
O(n log m)
n = number of piles
m = maximum pile size

Space Complexity:
O(1)
*/
