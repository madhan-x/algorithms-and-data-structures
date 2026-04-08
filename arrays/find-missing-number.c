#include <stdio.h>

// Find missing number from 1 to n
// Time Complexity: O(n)
// Space Complexity: O(1)

int main()
{
    int n, i, sum = 0;
    scanf("%d", &n);
    int a[n-1];
    for(i = 0; i < n-1; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int expected_sum = n * (n + 1) / 2;
    int missing = expected_sum - sum;
    printf("%d", missing);
    return 0;
}
