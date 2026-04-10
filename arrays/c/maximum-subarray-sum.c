#include <stdio.h>

// Maximum Subarray Sum (Kadane’s Algorithm)
// Approach:
// - Keep track of current sum
// - Reset when current sum becomes smaller than current element
// - Track maximum sum
// Time Complexity: O(n)
// Space Complexity: O(1)

int main() {
    int n, i;
    scanf("%d", &n);

    int a[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int curr_sum = a[0];
    int max_sum = a[0];

    for(i = 1; i < n; i++) {
        if(curr_sum + a[i] > a[i]) {
            curr_sum = curr_sum + a[i];
        } else {
            curr_sum = a[i];
        }

        if(curr_sum > max_sum) {
            max_sum = curr_sum;
        }
    }

    printf("max = %d", max_sum);

    return 0;
}
