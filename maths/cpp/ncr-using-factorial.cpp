#include <iostream>
using namespace std;

// Calculate factorial of n
long long factorial(int n) {
    long long fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Calculate nCr using factorial formula
// nCr = n! / (r! * (n-r)!)
// Time Complexity: O(n)
// Space Complexity: O(1)

long long nCr(int n, int r) {
    if(r > n || r < 0) return 0;

    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n, r;
    cin >> n >> r;

    cout << nCr(n, r);

    return 0;
}
