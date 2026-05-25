#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    // Insert elements
    q.push(10);
    q.push(20);
    q.push(30);

    // Print front and back elements
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;

    // Remove front element
    q.pop();

    // Print new front element
    cout << "Front after pop: " << q.front() << endl;

    return 0;
}
