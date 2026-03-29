#include <stdio.h>

// Check if an array is sorted (ascending)
// Approach: Compare adjacent elements
// Time Complexity: O(n)
// Space Complexity: O(1)

int main()
{
    int i, n;
    scanf("%d", &n);

    int a[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n - 1; i++)
    {
        if(a[i] > a[i + 1])
        {
            printf("Array is not sorted");
            return 0;
        }
    }

    printf("Array is sorted");
    return 0;
}
