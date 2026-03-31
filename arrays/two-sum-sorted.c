#include <stdio.h>

// Two Sum using Two Pointers (Sorted Array)
// Approach:
// - Use two pointers (start & end)
// - If sum == target → found
// - If sum < target → move left pointer
// - If sum > target → move right pointer
// Time Complexity: O(n)
// Space Complexity: O(1)

int main() {
    int n, i, j, target;

    scanf("%d", &n);
    int a[n];

    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &target);

    i = 0;
    j = n - 1;

    while(i < j) {
        int sum = a[i] + a[j];

        if(sum == target) {
            printf("YES (%d + %d = %d)", a[i], a[j], target);
            return 0;
        }
        else if(sum < target) {
            i++;
        }
        else {
            j--;
        }
    }

    printf("NO");

    return 0;
}
