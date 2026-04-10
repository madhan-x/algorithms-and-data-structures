#include <stdio.h>

// Rotate array by k positions using reversal algorithm
// Approach:
// 1. Reverse first k elements
// 2. Reverse remaining elements
// 3. Reverse entire array
// Time Complexity: O(n)
// Space Complexity: O(1)

void reverse(int a[], int start, int end) {
    while(start < end) {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, i, k;

    scanf("%d", &n);
    int a[n];

    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &k);

    k = k % n;

    reverse(a, 0, k-1);
    reverse(a, k, n-1);
    reverse(a, 0, n-1);

    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
