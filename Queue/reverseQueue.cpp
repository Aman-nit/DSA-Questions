#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// using stack
// time compexity O(n)
// space complexity O(n)
void reverseQueue(queue<int> &q)
{
    stack<int> s;
    // step01 put data from queue to stack
    while (!q.empty())
    {
        int elemnt = q.front();
        q.pop();

        s.push(elemnt);
    }

    // step02 put stack element into queue
    while (!s.empty())
    {
        int elemnt = s.top();
        s.pop();

        q.push(elemnt);
    }
}

// Using Recursion
// time complexity O(n)
// space comlexity O(n)

void reverseQueueUsingRecursion(queue<int> &q)
{

    if (!q.empty())
    {
        int element = q.front();
        q.pop();
        reverseQueueUsingRecursion(q);
        q.push(element);
    }
}

void printQueue(queue<int> q)
{

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
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    printQueue(q);
    // reverseQueue(q);
    reverseQueueUsingRecursion(q);
    printQueue(q);

    return 0;
}