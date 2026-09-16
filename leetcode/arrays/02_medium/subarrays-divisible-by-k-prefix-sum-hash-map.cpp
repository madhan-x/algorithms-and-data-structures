#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        // Store frequency of each remainder.
        unordered_map<int, int> mp;

        // Remainder 0 exists once before processing any element.
        mp[0] = 1;

        int prefix = 0;
        int ans = 0;

        for(int x : nums) {

            // Calculate prefix sum.
            prefix += x;

            // Find remainder when prefix sum is divided by k.
            int rem = prefix % k;

            // C++ can produce negative remainders.
            // Convert them into the range [0, k-1].
            if(rem < 0)
                rem += k;

            // If the same remainder appeared before,
            // the elements between those two prefix sums
            // form a subarray divisible by k.
            if(mp.count(rem))
                ans += mp[rem];

            // Record this remainder.
            mp[rem]++;
        }

        return ans;
    }
};

int main() {

    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    Solution obj;

    cout << obj.subarraysDivByK(nums, k) << endl;

    return 0;
}

/*
Approach:
- Calculate prefix sums while traversing the array.
- Store the frequency of each prefix-sum remainder.
- If the same remainder occurs again, the subarray
  between those positions has a sum divisible by k.

Pattern:
Prefix Sum + Hash Map

Time Complexity:
O(n)

Space Complexity:
O(k)
*/
