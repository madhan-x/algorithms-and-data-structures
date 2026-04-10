#include <stdio.h>
#include <limits.h>

// Find second largest element in array
// Time Complexity: O(n)
// Space Complexity: O(1)

int main() {
    int n, i;
    scanf("%d", &n);

    int a[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int max = INT_MIN;
    int second_max = INT_MIN;

    for(i = 0; i < n; i++) {
        if(a[i] > max) {
            second_max = max;
            max = a[i];
        }
        else if(a[i] > second_max && a[i] != max) {
            second_max = a[i];
        }
    }

    if(second_max == INT_MIN) {
        printf("No second largest");
    } else {
        printf("%d", second_max);
    }

    return 0;
}
