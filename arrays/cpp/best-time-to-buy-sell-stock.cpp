#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Best Time to Buy and Sell Stock
// Approach:
// - Track minimum price so far
// - Calculate profit at each step
// - Update maximum profit
// Time Complexity: O(n)
// Space Complexity: O(1)

int main()
{
    int n;
    cin >> n;

    if(n == 0) return 0;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int min_so_far = a[0];
    int max_profit = 0;   

    for(int i = 1; i < n; i++)
    {
        int profit = a[i] - min_so_far;

        if(profit > max_profit)
            max_profit = profit;

        if(a[i] < min_so_far)
            min_so_far = a[i];
    }

    cout << max_profit;

    return 0;
}
