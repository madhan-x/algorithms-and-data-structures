#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Find second largest element in array (single pass)
// Approach:
// Track largest and second largest while traversing once
// Update values based on comparisons
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

    int largest = INT_MIN;
    int second = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if(a[i] > largest)
        {
            second = largest;
            largest = a[i];
        }
        else if(a[i] > second && a[i] != largest)
        {
            second = a[i];
        }
    }

    if(second == INT_MIN)
        cout << "No second largest";
    else
        cout << second;

    return 0;
}
