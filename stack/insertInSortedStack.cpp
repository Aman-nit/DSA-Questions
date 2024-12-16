#include <iostream>
#include <stack>
using namespace std;

void insertInSorted(stack<int> &s, int target)
{

    // base case: if stack is empty or target is greater than top element
    if (s.empty() || s.top() <= target)
    {
        s.push(target);
        return;
    }
    int topElement = s.top();
    s.pop();
    insertInSorted(s, target);

    // Back Tracking
    s.push(topElement);
}

int main()
{

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    insertInSorted(s, 39);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}