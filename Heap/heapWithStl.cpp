#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // max-heap
    priority_queue<int> mh;
    mh.push(3);
    mh.push(6);
    mh.push(8);
    mh.push(9);
    mh.push(4);
    mh.push(12);

    cout << "Printing Max Heap..." << endl;
    cout << "Top Element:- " << mh.top() << endl;
    mh.pop();
    cout << "Top Element:- " << mh.top() << endl;
    mh.pop();
    cout << "Top Element:- " << mh.top() << endl;
    mh.pop();
    cout << "Top Element:- " << mh.top() << endl;
    mh.pop();
    cout << "Top Element:- " << mh.top() << endl;
    mh.pop();
    cout << "Top Element:- " << mh.top() << endl;
    mh.pop();
    cout << "Size:- " << mh.size() << endl;
    if (mh.empty())
    {
        cout << "Max heap is empty " << endl;
    }
    else
    {
        cout << "Max heap is not empty." << endl;
    }

    cout << endl
         << endl
         << "Printing Min Heap..." << endl;

    // Min-Heap

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(3);
    pq.push(6);
    pq.push(8);
    pq.push(9);
    pq.push(4);
    pq.push(12);

    cout << "Top Element:- " << pq.top() << endl;
    pq.pop();
    cout << "Top Element:- " << pq.top() << endl;
    pq.pop();
    cout << "Top Element:- " << pq.top() << endl;
    pq.pop();
    cout << "Top Element:- " << pq.top() << endl;
    pq.pop();
    cout << "Top Element:- " << pq.top() << endl;
    pq.pop();
    cout << "Top Element:- " << pq.top() << endl;
    pq.pop();
    cout << "Size:- " << pq.size() << endl;
    if (pq.empty())
    {
        cout << "Min heap is empty " << endl;
    }
    else
    {
        cout << "Min heap is not empty." << endl;
    }
}