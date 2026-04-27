#include<iostream>
#include<vector>
using namespace std;

// Sum of array elements
// Approach:
// - Traverse the array and accumulate sum
// Time Complexity: O(n)
// Space Complexity: O(1)

int main()
{
    int n, i, sum = 0;
    cin >> n;

    vector<int> a(n);      
    for(i = 0; i < n; i++)      
    {      
        cin >> a[i];      
    }  

    for(i = 0; i < n; i++)  
    {  
        sum += a[i];  
    }  

    cout << sum;

    return 0;  
}
