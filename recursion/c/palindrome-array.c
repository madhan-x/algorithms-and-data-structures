#include <stdio.h>

// Check if an array is palindrome using recursion
// Approach: Compare start and end elements, then recurse inward
// Base Case: start >= end → palindrome
// Time Complexity: O(n)
// Space Complexity: O(n) due to recursion stack

int palindrome(int arr[], int start, int end)
{
    if(start >= end)
        return 1;

    if(arr[start] != arr[end])
        return 0;

    return palindrome(arr, start + 1, end - 1);
}

int main()
{
    int arr[] = {1,2,3,2,1};
    int n = 5;

    if(palindrome(arr, 0, n-1))
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}
