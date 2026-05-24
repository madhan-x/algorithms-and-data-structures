#include <iostream>
using namespace std;

class Queue
{
public:
    int arr[100];
    int front;
    int rear;

    // Constructor
    Queue()
    {
        front = 0;
        rear = -1;
    }

    // Insert element into queue
    void enqueue(int x)
    {
        rear++;
        arr[rear] = x;
    }

    // Remove element from queue
    void dequeue()
    {
        if(front > rear)
        {
            cout << "Queue Underflow\n";
            return;
        }

        front++;
    }

    // Print front element
    void peek()
    {
        if(front > rear)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << arr[front] << endl;
    }

    // Check if queue is empty
    void isEmpty()
    {
        if(front > rear)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "Queue is not empty\n";
        }
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.peek();

    q.dequeue();

    q.peek();

    return 0;
}
