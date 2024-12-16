#include <iostream>
using namespace std;

class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushRear(int data)
    {
        // Queue Full
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            cout << "Queue is full, Cannot insert element." << endl;
            return;
        }
        // Single element case
        else if (front == -1)
        {
            front = rear = 0;
        }
        // Circular flow creation
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        // Normal flow of insertion
        else
        {
            rear++;
        }
        arr[rear] = data;
    }

    void pushFront(int data)
    {
        // Queue Full
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            cout << "Queue is full, Cannot insert element." << endl;
            return;
        }
        // Single element case
        else if (front == -1)
        {
            front = rear = 0;
        }
        // Circular flow creation
        else if (front == 0)
        {
            front = size - 1;
        }
        // Normal flow of insertion
        else
        {
            front--;
        }
        arr[front] = data;
    }

    void popFront()
    {
        // Empty check
        if (front == -1)
        {
            cout << "Queue is empty, cannot pop." << endl;
            return;
        }

        // Single element case
        if (front == rear)
        {
            arr[front] = -1;
            front = rear = -1;
        }
        // Circular flow
        else if (front == size - 1)
        {
            front = 0;
        }
        // Normal flow
        else
        {
            front++;
        }
    }

    void popRear()
    {
        // Empty check
        if (front == -1)
        {
            cout << "Queue is empty, cannot pop." << endl;
            return;
        }

        // Single element case
        if (front == rear)
        {
            arr[rear] = -1;
            front = rear = -1;
        }
        // Circular flow
        else if (rear == 0)
        {
            rear = size - 1;
        }
        // Normal flow
        else
        {
            rear--;
        }
    }

    void printDeque()
    {
        if (front == -1)
        {
            cout << "Deque is empty" << endl;
            return;
        }

        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    // Create a deque of size 10
    Deque dq(10);

    // Test operations
    dq.pushFront(5);
    dq.pushFront(10);
    dq.pushRear(15);
    dq.pushRear(25);

    dq.printDeque();

    dq.popFront();
    dq.printDeque();

    dq.popRear();
    dq.printDeque();

    return 0;
}
