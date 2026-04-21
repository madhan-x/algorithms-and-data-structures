#include <iostream>
#include <vector>
using namespace std;

// Intersection of two sorted arrays (unique elements)
// Approach:
// - Use two pointers
// - If elements match → add to result (avoid duplicates)
// - Move pointers based on comparison
// Time Complexity: O(n + m)
// Space Complexity: O(min(n, m))

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
        if(a[i] == b[j])
        {
            if(result.empty() || result.back() != a[i])
                result.push_back(a[i]);

            i++;
            j++;
        }
        else if(a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    for(int x : result)
        cout << x << " ";

    return 0;
}
