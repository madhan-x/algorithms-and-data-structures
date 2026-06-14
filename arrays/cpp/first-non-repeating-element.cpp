#include<iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 2, 3, 1, 4, 5, 4};
    int n = 8;

    for(int i = 0; i < n; i++)
    {
        int count = 0;

        for(int j = 0; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }

        if(count == 1)
        {
            cout << "First Non-Repeating Element = " << arr[i];
            break;
        }
    }

    return 0;
}
