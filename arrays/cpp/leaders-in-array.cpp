#include<iostream>
#include<vector>
using namespace std;

// Find leaders in array
// Approach:
// Traverse from right to left
// Keep track of maximum from right side
// If current element > max_right → it's a leader
// Time Complexity: O(n)
// Space Complexity: O(1)

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int max_right = a[n-1];

    cout << max_right << " ";

    for(int i = n-2; i >= 0; i--)
    {
        if(a[i] > max_right)
        {
            cout << a[i] << " ";
            max_right = a[i];
        }
    }

    return 0;
}
