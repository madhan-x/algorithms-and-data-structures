
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row : image) {
            int left = 0;
            int right = static_cast<int>(row.size()) - 1;

            while (left <= right) {
                // Reverse the elements at both ends
                swap(row[left], row[right]);

                // Invert 0 to 1 and 1 to 0 using XOR
                row[left] ^= 1;

                // Avoid inverting the same middle element twice
                if (left != right) {
                    row[right] ^= 1;
                }

                left++;
                right--;
            }
        }

        return image;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> image = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 0, 0}
    };

    vector<vector<int>> result = solution.flipAndInvertImage(image);

    for (const auto& row : result) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << '\n';
    }

    return 0;
}
