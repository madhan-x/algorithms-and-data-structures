#include <iostream>
using namespace std;

/*
🔢 Binary ↔ Decimal Conversion

🧠 Concepts:
1. Binary → Decimal:
   - Take last digit (rem = bin % 10)
   - Multiply with power of 2
   - Increase power (pow *= 2)

2. Decimal → Binary:
   - Take remainder (rem = dec % 2)
   - Build answer using powers of 10
*/

int binToDecimal(int binNum) {
    int ans = 0;
    int pow = 1; // represents 2^0 initially

    while (binNum > 0) {
        int rem = binNum % 10;   // extract last digit
        ans += rem * pow;        // add contribution
        binNum /= 10;            // remove last digit
        pow *= 2;                // next power of 2
    }

    return ans;
}

int decToBinary(int decNum) {
    int ans = 0;
    int pow = 1; // represents 10^0

    while (decNum > 0) {
        int rem = decNum % 2;    // get binary bit
        decNum /= 2;             // reduce number
        ans += rem * pow;        // build binary number
        pow *= 10;               // shift left in decimal form
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    cout << "Binary to Decimal: " << binToDecimal(n) << endl;
    cout << "Decimal to Binary: " << decToBinary(n) << endl;

    return 0;
}
