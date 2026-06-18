#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr = {8, 3, 15, 6, 2, 10};

    int maxi = arr[0];
    int mini = arr[0];

    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] > maxi)
        {
            maxi = arr[i];
        }

        if(arr[i] < mini)
        {
            mini = arr[i];
        }
    }

    cout << "Difference = " << maxi - mini;

    return 0;
}
