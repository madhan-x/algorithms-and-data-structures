#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    queue<int> firstHalf;

    int n;
    cin >> n;

    // Input queue elements
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        q.push(x);
    }

    int half = n / 2;

    // Move first half elements into another queue
    for(int i = 0; i < half; i++)
    {
        firstHalf.push(q.front());
        q.pop();
    }

    // Interleave both halves
    while(!firstHalf.empty())
    {
        cout << firstHalf.front() << " ";
        firstHalf.pop();

        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
