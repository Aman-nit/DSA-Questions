#include <iostream>
#include <queue>
using namespace std;

void interLeaveQueue(queue<int> &q, queue<int> &s)
{
    int n = q.size();
    int k = n / 2;
    if (q.empty())
    {
        cout << "Queue is empty.." << endl;
        return;
    }

    // Move the first half of the elements from q to s
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // Interleaving process
    while (!s.empty())
    {
        q.push(s.front()); // Add one element from s
        s.pop();
        q.push(q.front()); // Add one element from the remaining second half of q
        q.pop();
    }
    if (n & 1)
    {
        int element = q.front();
        q.pop();
        q.push(element);
    }
}

void printQueue(queue<int> q)
{
    // Print and remove elements until the queue is empty
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    queue<int> s;

    // Adding elements to queue q
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);

    interLeaveQueue(q, s);

    // Printing interleaved queue q
    cout << "Interleaved queue: ";
    printQueue(q);

    // The queue s should be empty now
    cout << "Queue s (should be empty): ";
    printQueue(s);

    return 0;
}
