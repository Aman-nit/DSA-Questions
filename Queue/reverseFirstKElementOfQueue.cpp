#include <iostream>
#include <stack>
#include <queue>
using namespace std;
// add feature in this if  k = n then reverse all element of queue

void reverseFirstKElementOfQueue(queue<int> &q, int k)
{
    stack<int> s;
    int n = q.size();
    if (k <= 0 || k >= n)
    {
        cout << "Invalid value of k." << endl;
        return;
    }

    // Step 1: Push the first k elements into the stack
    for (int i = 0; i < k; i++)
    {
        int temp = q.front();
        q.pop();
        s.push(temp);
    }

    // Step 2: Add the elements from the stack back to the queue
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    // Step 3: Move the remaining elements (n - k) from front to back of the queue
    for (int i = 0; i < n - k; i++)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

void printQueue(queue<int> q)
{

    int count = 0;
    for (int i = 0; i < q.size(); i++)
    {
        /* code */
    }

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
    int k;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    cout << "Enter the value of k:-";
    cin >> k;

    printQueue(q);
    // reverseQueue(q);
    reverseFirstKElementOfQueue(q, k);
    printQueue(q);

    return 0;
}