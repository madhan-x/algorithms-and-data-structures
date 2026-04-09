#include <stdio.h>

// Find all pairs with given sum using two pointers (sorted array)
// Approach:
// - Use two pointers (start & end)
// - If sum == target → print pair and move both pointers
// - If sum < target → move left pointer
// - If sum > target → move right pointer
// Time Complexity: O(n)
// Space Complexity: O(1)

int main() {
    int a[] = {1,2,3,4,5,6};
    int n = 6;
    int target = 7;

    int i = 0, j = n - 1;

    while(i < j) {
        int sum = a[i] + a[j];

        if(sum == target) {
            printf("(%d, %d)\n", a[i], a[j]);
            i++;
            j--;
        }
        else if(sum < target) {
            i++;
        }
        else {
            j--;
        }
    }

    return 0;
}
