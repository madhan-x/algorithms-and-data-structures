#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Longest subarray with equal number of 0s and 1s
// Approach:
// Convert 0 → -1
// Use prefix sum and hashmap
// If same sum appears again → subarray has equal 0s and 1s
// Time Complexity: O(n)
// Space Complexity: O(n)

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_map<int, int> mp;
    int sum = 0, maxLen = 0;

    mp[0] = -1; // important

    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0)
            sum += -1;
        else
            sum += 1;

        if(mp.find(sum) != mp.end())
        {
            int len = i - mp[sum];
            if(len > maxLen)
                maxLen = len;
        }
        else
        {
            mp[sum] = i;
        }
    }

    cout << maxLen;

    return 0;
}
