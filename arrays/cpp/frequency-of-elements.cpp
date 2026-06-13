#include<iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 2, 3, 1, 4, 2};
    int n = 7;

    bool visited[7] = {false};

    for(int i = 0; i < n; i++)
    {
        if(visited[i])
        {
            continue;
        }

        int count = 1;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                visited[j] = true;
            }
        }

        cout << arr[i] << " -> " << count << endl;
    }

    return 0;
}
