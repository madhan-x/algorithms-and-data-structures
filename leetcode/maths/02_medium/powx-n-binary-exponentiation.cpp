#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {

        double ans = 1.0;

        // Use long long because INT_MIN cannot be safely negated as int.
        long long nn = n;

        // Work with the absolute value of the exponent.
        if(nn < 0)
            nn = -nn;

        while(nn) {

            // If the current exponent is odd,
            // multiply the answer by x.
            if(nn % 2) {
                ans *= x;
                nn -= 1;
            }
            else {
                // If exponent is even:
                // x^n = (x^2)^(n/2)
                x *= x;
                nn /= 2;
            }
        }

        // For a negative exponent:
        // x^(-n) = 1 / x^n
        if(n < 0)
            ans = 1.0 / ans;

        return ans;
    }
};

int main() {

    Solution obj;

    double x = 2.0;
    int n = 10;

    cout << obj.myPow(x, n) << endl;

    return 0;
}

/*
Approach:
- Use binary exponentiation.
- If the exponent is odd, multiply the answer by x
  and reduce the exponent by 1.
- If the exponent is even, square x and divide the
  exponent by 2.
- For a negative exponent, return 1 / ans.

Pattern:
Binary Exponentiation / Fast Power

Time Complexity:
O(log n)

Space Complexity:
O(1)
*/
