#include <stdio.h>

// Find maximum consecutive 1s in an array
// Approach:
// - Traverse array
// - Count consecutive 1s
// - Reset count when 0 appears
// Time Complexity: O(n)
// Space Complexity: O(1)

int main() {
    int n, i;
    scanf("%d", &n);

    int a[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int count = 0;
    int max = 0;

    for(i = 0; i < n; i++) {
        if(a[i] == 1) {
            count++;
            if(count > max) {
                max = count;
            }
        } else {
            count = 0;
        }
    }

    printf("%d", max);

    return 0;
}
