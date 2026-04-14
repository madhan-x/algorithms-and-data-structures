#include<iostream>
#include<vector>
using namespace std;

// Check if array is sorted and rotated
// Approach:
// Count number of places where a[i] > a[i+1]
// Also check last and first element (circular condition)
// If count <= 1 → array is sorted & rotated
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

    int count = 0;

    // check breaks in normal loop
    for(int i = 0; i < n-1; i++)
    {
        if(a[i] > a[i+1])
        {
            count++;
        }
    }

    // check last and first (circular)
    if(a[n-1] > a[0])
    {
        count++;
    }

    if(count <= 1)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
