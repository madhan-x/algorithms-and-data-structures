#include <iostream>
#include <vector>
using namespace std;

// Sort Colors (Dutch National Flag Algorithm)
// Approach:
// - Use three pointers: low, mid, high
// - 0 → swap with low, move low & mid
// - 1 → move mid
// - 2 → swap with high, move high
// Time Complexity: O(n)
// Space Complexity: O(1)

void sortColors(vector<int>& a) {
    int low = 0, mid = 0;
    int high = a.size() - 1;

    while (mid <= high) {
        if (a[mid] == 0) {
            swap(a[low], a[mid]);
            low++;
            mid++;
        }
        else if (a[mid] == 1) {
            mid++;
        }
        else { // a[mid] == 2
            swap(a[mid], a[high]);
            high--;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sortColors(a);

    for (int x : a) {
        cout << x << " ";
    }

    return 0;
}
