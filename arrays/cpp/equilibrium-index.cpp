#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 3, 5, 2, 2};

    int n = arr.size();

    for(int i = 0; i < n; i++)
    {
        int leftSum = 0;
        int rightSum = 0;

        // Calculate left sum
        for(int j = 0; j < i; j++)
        {
            leftSum += arr[j];
        }

        // Calculate right sum
        for(int j = i + 1; j < n; j++)
        {
            rightSum += arr[j];
        }

        // Check equilibrium condition
        if(leftSum == rightSum)
        {
            cout << "Equilibrium Index = " << i;
            return 0;
        }
    }

    cout << -1;

    return 0;
}
