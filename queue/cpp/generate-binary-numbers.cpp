#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;

    queue<string> q;

    // Start with binary "1"
    q.push("1");

    for(int i = 1; i <= n; i++)
    {
        // Get front binary number
        string curr = q.front();
        q.pop();

        // Print current binary number
        cout << curr << endl;

        // Generate next binary numbers
        q.push(curr + "0");
        q.push(curr + "1");
    }

    return 0;
}
