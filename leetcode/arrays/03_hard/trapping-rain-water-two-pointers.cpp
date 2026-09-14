#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;

        int water = 0;
        int leftmax = 0;
        int rightmax = 0;

        while(i < j) {

            // Process the side with the smaller height.
            if(height[i] < height[j]) {

                // Update maximum height seen from the left.
                if(height[i] > leftmax) {
                    leftmax = height[i];
                }
                else {
                    // Water trapped above the current bar.
                    water += leftmax - height[i];
                }

                i++;
            }
            else {

                // Update maximum height seen from the right.
                if(height[j] > rightmax) {
                    rightmax = height[j];
                }
                else {
                    // Water trapped above the current bar.
                    water += rightmax - height[j];
                }

                j--;
            }
        }

        return water;
    }
};

int main() {
    Solution solution;

    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << "Trapped Rain Water: "
         << solution.trap(height) << endl;

    return 0;
}

/*
Approach:
- Use two pointers, one from the left and one from the right.
- Maintain the maximum height encountered from both sides.
- Always process the side with the smaller current height.
- If the current height is smaller than its corresponding maximum,
  water can be trapped above it.

Pattern:
Two Pointers

Time Complexity:
O(n)

Space Complexity:
O(1)
*/
