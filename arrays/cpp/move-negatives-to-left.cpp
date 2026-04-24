#include<iostream>
#include<vector>
using namespace std;

// Move all negative numbers to left side
// Approach:
// - Use two pointers (i from start, j from end)
// - Move i forward if element is negative
// - Move j backward if element is non-negative
// - Swap when misplaced elements are found
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

    int i = 0;  
    int j = n - 1;  

    while(i < j)
    {
        if(a[i] < 0)
        {
            i++;
        }
        else if(a[j] >= 0)
        {
            j--;
        }
        else
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    for(int x : a)  
        cout << x << " ";  

    return 0;
}
