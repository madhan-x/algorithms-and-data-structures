#include<iostream>
using namespace std;

int main()
{
    int arr[] = {2, 1, 5, 1, 3, 2};
    int n = 6;
    int k = 3;

    int windowSum = 0;

    // Calculate first window sum
    for(int i = 0; i < k; i++)
    {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // Slide the window
    for(int i = k; i < n; i++)
    {
        windowSum = windowSum - arr[i - k] + arr[i];

        if(windowSum > maxSum)
        {
            maxSum = windowSum;
        }
    }

    cout << "Maximum Sum = " << maxSum;

    return 0;
}
