// Left Rotate by One
#include <iostream>
#include <vector>
using namespace std;

// Rotate array by one position
// Left Rotation
// Time Complexity: O(n)
// Space Complexity: O(1)

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int temp = a[0];

    for(int i = 0; i < n - 1; i++)
        a[i] = a[i + 1];

    a[n - 1] = temp;

    for(int x : a)
        cout << x << " ";

    return 0;
}
