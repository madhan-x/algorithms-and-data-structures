#include <iostream>
#include <vector>
using namespace std;

// Union of two sorted arrays (unique elements)
// Approach:
// Use two pointers to merge both arrays
// Avoid duplicates by checking last inserted element
// Time Complexity: O(n + m)
// Space Complexity: O(n + m)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int j = 0; j < m; j++)
        cin >> b[j];

    vector<int> result;

    int i = 0, j = 0;

    while(i < n && j < m)
    {
        if(a[i] < b[j])
        {
            if(result.empty() || result.back() != a[i])
                result.push_back(a[i]);
            i++;
        }
        else if(a[i] > b[j])
        {
            if(result.empty() || result.back() != b[j])
                result.push_back(b[j]);
            j++;
        }
        else
        {
            if(result.empty() || result.back() != a[i])
                result.push_back(a[i]);
            i++;
            j++;
        }
    }

    // remaining elements of a
    while(i < n)
    {
        if(result.empty() || result.back() != a[i])
            result.push_back(a[i]);
        i++;
    }

    // remaining elements of b
    while(j < m)
    {
        if(result.empty() || result.back() != b[j])
            result.push_back(b[j]);
        j++;
    }

    // print result
    for(int x : result)
        cout << x << " ";

    return 0;
}
