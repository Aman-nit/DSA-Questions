#include <iostream>
#include <vector>
// #include <queue>
using namespace std;

// Implimentation of Queues using class
class Queue
{
public:
    int *arr;
    int size;
    int front;
    int raer;

    Queue(int data)
    {
        this->size = data;
        arr = new int[size];
        front = 0;
        raer = 0;
    }

    void push(int data)
    {
        if (size == raer)
        {
            cout << "Sorry Queue is full..." << endl;
        }
        else
        {
            arr[raer] = data;
            raer++;
        }
    }

    void pop()
    {
        if (front == raer)
        {
            cout << "Queue is emoty" << endl;
        }
        else
        {
            arr[front] = -1; // just for marking not necessary to mark ,we cant delete any integer that's why we mark
            front++;
            // it indicate queue is empty but may be its start from any other location like raer and front is at 4 so we will be filling from 4 so 0 to 3 index will be waste for utilize that space we initilize from 0
            if (front == raer)
            {
                front = 0;
                raer = 0;
            }
        }
    }

    int getFront()
    {
        if (front == raer)
        {
            cout << "Queue is emoty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        if (front == raer)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int getSize()
    {
        return raer - front;
    }
};

// Printing Queue
void PrintQueue()
{
}

int main()
{

    // USING STL

    // // creating a Queue
    // queue<int> q;

    // // insertion
    // q.push(5);
    // q.push(15);
    // q.push(25);
    // q.push(35);
    // q.push(45);

    // // size
    // cout << "Size of Queue is: " << q.size() << endl;

    // // Removal
    // q.pop();
    // cout << "Size of Queue is: " << q.size() << endl;

    // if (q.empty())
    // {
    //     cout << "Queue is empty " << endl;
    // }
    // else
    // {
    //     cout << "Queue is not empty " << endl;
    // }

    // // Front element of Queue

    // cout << q.front() << endl;

    // USING SELF IMPLEMENTED QUEUE WITH ARRAY

    Queue q(10);

    q.push(5);
    q.push(15);
    q.push(25);
    q.push(35);
    q.push(45);

    cout << "Size of Queue is: " << q.getSize() << endl;
    q.pop();
    cout << "Size of Queue is: " << q.getSize() << endl;
    cout << "Front element of Queue is: " << q.getFront() << endl;
    if (q.isEmpty())
    {
        cout << "Queue is empty ...." << endl;
    }
    else
    {
        cout << "Queu is not empty...." << endl;
    }

    return 0;
}