#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr = {3, 4, -1, 1};

    int n = arr.size();

    for(int i = 1; i <= n + 1; i++)
    {
        bool found = false;

        for(int j = 0; j < n; j++)
        {
            if(arr[j] == i)
            {
                found = true;
                break;
            }
        }

        if(!found)
        {
            cout << "Smallest Positive Missing Number = " << i;
            break;
        }
    }

    return 0;
}
