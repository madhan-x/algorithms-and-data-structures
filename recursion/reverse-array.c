#include <stdio.h>

// Reverse an array using recursion
// Approach: Swap first and last, then recurse for remaining array
// Time Complexity: O(n)
// Space Complexity: O(n) due to recursion stack

void revarr(int arr[], int start, int end)
{
    if(start >= end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    revarr(arr, start + 1, end - 1);
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = 5;

    revarr(arr, 0, n-1);

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
