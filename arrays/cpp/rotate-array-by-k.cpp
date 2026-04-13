#include <iostream>
#include <vector>
using namespace std;

// Rotate array by K positions using Reversal Algorithm
// Approach:
// 1. Reverse first k elements
// 2. Reverse remaining elements
// 3. Reverse whole array
// Time Complexity: O(n)
// Space Complexity: O(1)

void reverse(vector<int> &a, int start, int end)
{
while(start < end)
{
int temp = a[start];
a[start] = a[end];
a[end] = temp;
start++;
end--;
}
}

int main()
{
int n, k;
cin >> n;

if(n == 0) return 0;      
  
vector<int> a(n);      
for(int i = 0; i < n; i++)      
{      
    cin >> a[i];      
}      
  
cin >> k;      
k = k % n;      
  
// Left rotate by k      
reverse(a, 0, k - 1);      
reverse(a, k, n - 1);      
reverse(a, 0, n - 1);      
  
for(int i = 0; i < n; i++)      
{      
    cout << a[i] << " ";      
}      
  
return 0;

}
