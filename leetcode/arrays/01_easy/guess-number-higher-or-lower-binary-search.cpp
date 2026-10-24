
#include <iostream>
using namespace std;

// Mock API for local testing
int pickedNumber = 6;

int guess(int num) {
    if (num == pickedNumber) return 0;
    if (num > pickedNumber) return -1;
    return 1;
}

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int result = guess(mid);

            if (result == 0) {
                return mid;
            } else if (result == -1) {
                // mid is too high, search smaller numbers
                right = mid - 1;
            } else {
                // mid is too low, search larger numbers
                left = mid + 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution solution;
    cout << solution.guessNumber(10) << '\n';
    return 0;
}
