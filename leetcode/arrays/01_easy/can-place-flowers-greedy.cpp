#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        for(int i = 0; i < flowerbed.size(); i++) {

            // Only an empty position can be used.
            if(flowerbed[i] == 0) {

                // Position is safe if:
                // - it is the first position, OR
                // - the left position is empty.
                bool leftEmpty =
                    (i == 0 || flowerbed[i - 1] == 0);

                // Position is safe if:
                // - it is the last position, OR
                // - the right position is empty.
                bool rightEmpty =
                    (i == flowerbed.size() - 1 ||
                     flowerbed[i + 1] == 0);

                // We can plant here.
                if(leftEmpty && rightEmpty) {

                    flowerbed[i] = 1;
                    n--;

                    // Required number of flowers placed.
                    if(n == 0)
                        return true;
                }
            }
        }

        // If n <= 0, all required flowers were placed.
        return n <= 0;
    }
};

int main() {

    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;

    Solution obj;

    cout << (obj.canPlaceFlowers(flowerbed, n)
             ? "true"
             : "false")
         << endl;

    return 0;
}

/*
Approach:
- Traverse the flowerbed from left to
