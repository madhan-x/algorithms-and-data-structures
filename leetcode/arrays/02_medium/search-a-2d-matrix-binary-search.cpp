#include <iostream>
#include <vector>
using namespace std;

/*
Problem:
LeetCode 74 - Search a 2D Matrix

Difficulty:
Medium

Pattern:
Binary Search

Example:

Input:
3 4
1  3  5  7
10 11 16 20
23 30 34 60
3

Output:
true
*/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // Treat the 2D matrix as a sorted 1D array.
        int low = 0;
        int high = m * n - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            // Convert the 1D index back to row and column.
            int row = mid / n;
            int col = mid % n;

            if(matrix[row][col] == target)
            {
                return true;
            }

            if(matrix[row][col] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return false;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    Solution obj;

    cout << boolalpha << obj.searchMatrix(matrix, target);

    return 0;
}

/*
Approach:

Instead of performing binary search separately on every row,
consider the matrix as one sorted 1D array.

For a 1D index mid:

row = mid / n
col = mid % n

Example:

1  3  5
7  9  11

Virtual 1D array:

1 3 5 7 9 11

If mid = 4:

row = 4 / 3 = 1
col = 4 % 3 = 1

matrix[1][1] = 9

Time Complexity: O(log(m * n))

Space Complexity: O(1)
*/
