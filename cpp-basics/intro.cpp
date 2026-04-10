#include <iostream>
#include <vector>
using namespace std;

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

int main() {

    // 1. Output
    cout << "🚀 Starting my C++ journey" << endl;

    // 2. Variables
    int x = 10, y = 20;

    // 3. Function
    int sum = add(x, y);
    cout << "Sum: " << sum << endl;

    // 4. Vector (important for DSA)
    vector<int> nums = {1, 2, 3, 4, 5};

    cout << "Vector elements: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
