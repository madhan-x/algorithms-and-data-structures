// Right Rotate by One
#include <iostream>
#include <vector>
using namespace std;

// Rotate array by one position
// Right Rotation
// Time Complexity: O(n)
// Space Complexity: O(1)

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int temp = a[n - 1];

    for(int i = n - 1; i > 0; i++)
        a[i] = a[i + 1];

    a[0] = temp;

    for(int x : a)
        cout << x << " ";

    return 0;
}
