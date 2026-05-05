#include <iostream>
using namespace std;

/*
🧠 Moore’s Voting Algorithm - Majority Element (> n/2)

📌 Idea:
- Treat elements like votes
- Same element → increase count
- Different element → decrease count
- When count becomes 0 → choose new candidate

⚡ Steps:
1. Find candidate
2. Verify candidate

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(1)
*/

int main() {
    int arr[] = {2, 2, 1, 2, 3, 2, 2};
    int n = 7;

    int candidate = arr[0];
    int count = 1;

    // Step 1: Find candidate
    for(int i = 1; i < n; i++) {
        if(arr[i] == candidate)
            count++;
        else
            count--;

        if(count == 0) {
            candidate = arr[i];
            count = 1;
        }
    }

    // Step 2: Verify candidate
    count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == candidate)
            count++;
    }

    if(count > n/2)
        cout << "Majority element: " << candidate;
    else
        cout << "No majority element";

    return 0;
}
