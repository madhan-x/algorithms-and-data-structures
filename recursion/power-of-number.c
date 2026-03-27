#include <stdio.h>

// Calculate x^n using recursion
// Approach: Multiply x with result of power(x, n-1)
// Base Case: n == 0 → return 1
// Time Complexity: O(n)
// Space Complexity: O(n) due to recursion stack

int power(int x, int n)
{
    if(n == 0)
        return 1;

    return x * power(x, n - 1);
}

int main()
{
    int x = 2, n = 5;
    printf("%d^%d = %d", x, n, power(x, n));
    return 0;
}
