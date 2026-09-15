#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem:
LeetCode 703 - Kth Largest Element in a Stream

Difficulty:
Easy

Pattern:
Min Heap / Priority Queue

Approach:
Maintain a min heap containing only the k largest elements.

- Insert every number into the min heap.
- If heap size becomes greater than k, remove the smallest element.
- The top of the heap will always represent the kth largest element.

Why Min Heap?

We only want to keep the k largest elements.

The smallest among those k elements is the kth largest overall.

Time Complexity:
Constructor: O(n log k)
add(): O(log k)

Space Complexity:
O(k)

Example:

nums = [4, 5, 8, 2]
k = 3

Heap keeps the 3 largest elements.

add(3)  -> [3, 4, 5, 8]      -> 3rd largest = 4
add(5)  -> [3, 4, 5, 5, 8]   -> 3rd largest = 5
add(10) -> [4, 5, 5, 8, 10]  -> 3rd largest = 5
*/

class KthLargest {
    // Min heap to store only k largest elements
    priority_queue<int, vector<int>, greater<int>> pq;

    int k;

public:

    // Constructor
    KthLargest(int x, vector<int>& nums) {
        k = x;

        // Keep only the k largest elements
        for (int num : nums) {
            pq.push(num);

            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    // Add a new value and return kth largest element
    int add(int val) {

        pq.push(val);

        // Remove smallest element if size exceeds k
        if (pq.size() > k) {
            pq.pop();
        }

        // Top represents kth largest element
        return pq.top();
    }
};

int main() {

    vector<int> nums = {4, 5, 8, 2};

    KthLargest obj(3, nums);

    cout << obj.add(3) << endl;   // 4
    cout << obj.add(5) << endl;   // 5
    cout << obj.add(10) << endl;  // 5
    cout << obj.add(9) << endl;   // 8
    cout << obj.add(4) << endl;   // 8

    return 0;
}
