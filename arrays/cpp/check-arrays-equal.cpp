#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Check if two arrays are equal (order doesn't matter)
// Approach:
// If sizes differ → not equal
// Sort both arrays and compare element by element
// Time Complexity: O(n log n)
// Space Complexity: O(1) (ignoring sorting space)

int main()
{
    int n, m;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;

    vector<int> b(m);
    for(int j = 0; j < m; j++)
        cin >> b[j];

    if(n != m)
    {
        cout << "NO";
        return 0;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = 0; i < n; i++)
    {
        if(a[i] != b[i])
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}
