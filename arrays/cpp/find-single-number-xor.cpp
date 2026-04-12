#include <iostream>
#include <vector>
using namespace std;

// 🔹 Function declarations (if any)
// Example:
// int solve(vector<int>& a);

int main()
{
    // 🔹 Input
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // 🔹 Logic
    int result = 0;

    for(int i = 0; i < n; i++)
    {
        result = result ^ a[i];
    }

    // 🔹 Output
    cout << result;

    return 0;
}
