#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr = {9, 8, 7, 10, 6, 5, 4, 3};

    int count = 1;
    int maxCount = 1;

    for(int i = 1; i < arr.size(); i++)
    {
        // Current decreasing streak continues
        if(arr[i] < arr[i - 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }

        // Update maximum streak length
        if(count > maxCount)
        {
            maxCount = count;
        }
    }

    cout << "Length of Longest Decreasing Contiguous Subarray = "
         << maxCount;

    return 0;
}
