#include <stdio.h>

// Binary Search using Recursion
// Approach: Divide array into halves and search recursively
// Condition: Array must be sorted
// Time Complexity: O(log n)
// Space Complexity: O(log n) due to recursion stack

int binarySearch(int arr[], int low, int high, int key)
{
    if(low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if(arr[mid] == key)
        return mid;

    else if(key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);

    else
        return binarySearch(arr, mid + 1, high, key);
}

int main()
{
    int arr[] = {1,3,5,7,9};
    int n = 5;
    int key = 7;

    int result = binarySearch(arr, 0, n-1, key);

    if(result != -1)
        printf("Found at index %d", result);
    else
        printf("Not Found");

    return 0;
}
