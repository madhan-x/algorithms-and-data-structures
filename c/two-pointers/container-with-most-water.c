#include <stdio.h>

// Container With Most Water (Two Pointers)
// Approach:
// - Use two pointers (left & right)
// - Calculate area = min(height[left], height[right]) * width
// - Move pointer with smaller height
// Time Complexity: O(n)
// Space Complexity: O(1)

int main() {
    int n, i;
    scanf("%d", &n);

    int a[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int left = 0;
    int right = n - 1;
    int maxArea = 0;

    while(left < right) {
        int height;

        if(a[left] < a[right]) {
            height = a[left];
        } else {
            height = a[right];
        }

        int width = right - left;
        int area = height * width;

        if(area > maxArea) {
            maxArea = area;
        }

        if(a[left] < a[right]) {
            left++;
        } else {
            right--;
        }
    }

    printf("Max Area = %d", maxArea);

    return 0;
}
