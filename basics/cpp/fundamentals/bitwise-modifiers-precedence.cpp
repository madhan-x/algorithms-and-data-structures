#include <iostream>
using namespace std;

/*
🧠 C++ Fundamentals Practice

Topics Covered:
1. Data Type Modifiers
2. Bitwise Operators
3. Operator Precedence & Associativity

⏱️ Time Complexity: O(1)
📦 Space Complexity: O(1)
*/

int main() {

    // -------- DATA TYPE MODIFIERS --------
    // Modify the size or sign of data types
    short int a = 5;        // smaller range than int
    long int b = 100000;    // larger range than int
    unsigned int c = 10;    // only positive values

    cout << "Data Type Modifiers:\n";
    cout << "short int a = " << a << endl;
    cout << "long int b = " << b << endl;
    cout << "unsigned int c = " << c << endl;

    // -------- BITWISE OPERATORS --------
    int x = 5, y = 3;  // 5 = 101, 3 = 011

    cout << "\nBitwise Operators:\n";
    cout << "x & y = " << (x & y) << endl;   // AND → 001 = 1
    cout << "x | y = " << (x | y) << endl;   // OR  → 111 = 7
    cout << "x ^ y = " << (x ^ y) << endl;   // XOR → 110 = 6
    cout << "~x = " << (~x) << endl;         // NOT → flips bits
    cout << "x << 1 = " << (x << 1) << endl; // Left Shift → multiply by 2
    cout << "x >> 1 = " << (x >> 1) << endl; // Right Shift → divide by 2

    // -------- PRECEDENCE & ASSOCIATIVITY --------

    // '*' has higher precedence than '+'
    int result = 5 + 2 * 3;  
    cout << "\nPrecedence (5 + 2 * 3): " << result << endl; // 11

    // Parentheses override precedence
    int result2 = (5 + 2) * 3;  
    cout << "With parentheses ((5 + 2) * 3): " << result2 << endl; // 21

    // Left-to-right associativity for '-'
    int result3 = 10 - 5 - 2;  
    cout << "Associativity (10 - 5 - 2): " << result3 << endl; // 3

    return 0;
}
