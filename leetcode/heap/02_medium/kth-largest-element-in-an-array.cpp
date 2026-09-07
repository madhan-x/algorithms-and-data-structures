#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem:
LeetCode 215 - Kth Largest Element in an Array

Difficulty:
Medium

Pattern:
Max Heap / Priority Queue

Approach:
Use a max heap to store all elements.

Since a max heap always keeps the largest element at the top:

1. Insert all elements into the max heap.
2. Remove the largest element k - 1 times.
3. The element at the top is the kth largest element.

Time Complexity:
O(n log n)

Space Complexity:
O(n)

Example:

Input:
nums = [3, 2, 1, 5, 6, 4]
k = 2

Sorted order:
[6, 5, 4, 3, 2, 1]

The 2nd largest element is:
5
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // Max heap
        priority_queue<int> pq;

        // Insert all elements into the heap
        for (int num : nums) {
            pq.push(num);
        }

        // Remove the largest elements k - 1 times
        while (k > 1) {
            pq.pop();
            k--;
        }

        // The top is the kth largest element
        return pq.top();
    }
};

int main() {

    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    Solution obj;

    cout << obj.findKthLargest(nums, k);

    return 0;
}
