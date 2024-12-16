#include <iostream>
#include <queue>

using namespace std;
// 1.input ristricted Queue
// 2. Output ristricted Queue
// 3.Doubly Ended Queue(deque)
// deqeue == pop()
// enqueue == pus()

class CirQueue
{
public:
    int *arr;
    int size;
    int rear;
    int front;

    CirQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void push(int data)
    {
        // Queue Full
        if ((front == 0 && rear == size - 1) && (rear == front - 1))
        {
            cout << "Queue is full,Cannot insert element." << endl;
        }
        // Single elemnt case
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
        }
        // Circulare flow creation
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        // normalflow of insertion
        else
        {
            rear++;
            arr[rear] = data;
        }
    }
    void pop()
    {
        // empty check
        if (front == -1)
        {
            cout << "Queue is empty , cannot pop " << endl;
        }
        // single element
        else if (front == rear)
        {
            arr[front] = -1;
            front - 1;
            rear = -1;
        }
        // cirular flow
        else if (rear == 0)
        {
            rear = size - 1;
        }
        // normal flow
        else
        {
            rear--;
        }
    }
};
int main()
{

    return 0;
}