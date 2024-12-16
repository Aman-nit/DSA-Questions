#include <iostream>
#include <stack>
using namespace std;

void findMiddle(stack<int> &s, int &totalSize)
{

    if (s.size() == 0)
    {
        cout << "there is no element in stack " << endl;
        return;
    }

    if (s.size() == totalSize / 2 + 1)
    {
        cout << "Middle element is: " << s.top();
        return;
    }

    int temp = s.top();
    s.pop();
    // Recursion call
    findMiddle(s, totalSize);
    // backtracking
    s.push(temp);
}

int main()
{
    stack<int> s;
    for (int i = 1; i <= 5; i++)
    {
        s.push(i * 10);
    }

    int totalSize = s.size();
    findMiddle(s, totalSize);

    return 0;
}