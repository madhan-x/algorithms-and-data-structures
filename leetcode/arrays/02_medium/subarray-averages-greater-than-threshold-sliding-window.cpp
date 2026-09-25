#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int windowSum = 0;
        int count = 0;

        // Calculate the sum of the first window.
        for(int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        // Instead of calculating:
        // windowSum / k >= threshold
        //
        // We compare:
        // windowSum >= k * threshold
        if(windowSum >= k * threshold)
            count++;

        // Slide the window one position at a time.
        for(int i = k; i < arr.size(); i++) {

            // Add the new element entering the window.
            windowSum += arr[i];

            // Remove the element leaving the window.
            windowSum -= arr[i - k];

            // Check whether the current window
            // satisfies the required average.
            if(windowSum >= k * threshold)
                count++;
        }

        return count;
    }
};

int main() {

    Solution obj;

    vector<int> arr = {2, 2, 2, 2, 5, 5, 5, 8};

    int k = 3;
    int threshold = 4;

    cout << obj.numOfSubarrays(arr, k, threshold) << endl;

    return 0;
}

/*
Example:

arr = [2,2,2,2,5,5,5,8]
k = 3
threshold = 4

Required:
average >= 4

Instead of calculating the average,
we check:

windowSum >= k * threshold

windowSum >= 
