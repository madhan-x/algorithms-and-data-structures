#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 2, 3, 4, 5, 1};

    int count = 1;
    int maxCount = 1;

    for(int i = 1; i < arr.size(); i++)
    {
        // Current increasing streak continues
        if(arr[i] > arr[i - 1])
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

    cout << "Length of Longest Increasing Contiguous Subarray = "
         << maxCount;

    return 0;
}
