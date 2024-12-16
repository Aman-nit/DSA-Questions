#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &s)
{

    int bootomElement = s.top();
    s.pop();

    // Reverese stack(Back Tracking)
}
int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    if (s.empty())
    {
        cout << "Stack is empty , Cant insert at bottom.." << endl;
        return 0;
    }

    reverseStack(s);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}