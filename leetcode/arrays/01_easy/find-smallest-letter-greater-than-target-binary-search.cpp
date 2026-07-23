#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        int low = 0;
        int high = letters.size() - 1;

        // Default answer handles the wrap-around case
        char ans = letters[0];

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            // Found a better candidate
            if(target < letters[mid])
            {
                ans = letters[mid];
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    int n;
    cin >> n;

    vector<char> letters(n);

    for(int i = 0; i < n; i++)
    {
        cin >> letters[i];
    }

    char target;
    cin >> target;

    cout << obj.nextGreatestLetter(letters, target);

    return 0;
}

/*
Problem:
LeetCode 744 - Find Smallest Letter Greater Than Target

Approach:
1. Perform Binary Search on the sorted array.
2. Whenever a letter greater than the target is found,
   store it as the current answer.
3. Continue searching on the left to find a smaller valid letter.
4. If no greater letter exists, return the first element
   (wrap-around condition).

Pattern:
Binary Search

Time Complexity: O(log n)

Space Complexity: O(1)
*/
