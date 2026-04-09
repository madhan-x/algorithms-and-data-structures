#include <stdio.h>

// Find all triplets with given sum using two pointers (sorted array)
// Approach:
// - Fix one element (i)
// - Use two pointers (left & right) for remaining array
// - Adjust pointers based on sum
// Time Complexity: O(n^2)
// Space Complexity: O(1)

int main() {
    int a[] = {1,2,3,4,5,6};
    int n = 6;
    int target = 10;

    for(int i = 0; i < n-2; i++) {
        int left = i + 1;
        int right = n - 1;

        while(left < right) {
            int sum = a[i] + a[left] + a[right];

            if(sum == target) {
                printf("(%d, %d, %d)\n", a[i], a[left], a[right]);
                left++;
                right--;
            }
            else if(sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return 0;
}
