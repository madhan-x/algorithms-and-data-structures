
#include <iostream>
using namespace std;

// Mock API for local testing
int badVersion = 4;

bool isBadVersion(int version) {
    return version >= badVersion;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (isBadVersion(mid)) {
                // mid may be the first bad version
                right = mid;
            } else {
                // The first bad version must be after mid
                left = mid + 1;
            }
        }

        return left;
    }
};

int main() {
    Solution solution;
    cout << solution.firstBadVersion(5) << '\n';
    return 0;
}
