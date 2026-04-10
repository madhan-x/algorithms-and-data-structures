#include <stdio.h>

// Check if array is palindrome using two pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

int main()
{
    int n, i, j;
    scanf("%d", &n);

    int a[n];
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    i = 0;
    j = n - 1;

    while(i < j)
    {
        if(a[i] != a[j])
        {
            printf("Not Palindrome");
            return 0;
        }
        i++;
        j--;
    }

    printf("Palindrome");

    return 0;
}
