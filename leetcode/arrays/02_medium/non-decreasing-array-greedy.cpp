#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {

        int changes = 0;

        for(int i = 1; i < nums.size(); i++) {

            // Found a decreasing pair.
            if(nums[i] < nums[i - 1]) {

                changes++;

                // More than one modification is not allowed.
                if(changes > 1)
                    return false;

                // If modifying the previous element is safe,
                // lower it to the current value.
                if(i == 1 || nums[i] >= nums[i - 2]) {
                    nums[i - 1] = nums[i];
                }
                else {
                    // Otherwise, raise the current element
                    // to the previous value.
                    nums[i] = nums[i - 1];
                }
            }
        }

        return true;
    }
};

int main() {

    vector<int> nums = {4, 2, 3};

    Solution obj;

    cout << (obj.checkPossibility(nums) ? "true" : "false") << endl;

    return 0;
}

/*
Approach:
- Traverse the array and find decreasing pairs.
- At most one decreasing pair can be fixed.
- When a violation occurs, greedily decide whether to modify
  nums[i - 1] or nums[i].
- Check nums[i - 2] to make the correct choice.

Pattern:
Greedy

Time Complexity:
O(n)

Space Complexity:
O(1)
*/
