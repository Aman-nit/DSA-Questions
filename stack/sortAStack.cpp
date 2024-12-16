#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &s, int target)
{
    // base case: if stack is empty or target is greater than or equal to top element
    if (s.empty() || s.top() <= target)
    {
        s.push(target);
        return;
    }
    int topElement = s.top();
    s.pop();
    insertSorted(s, target);

    // Backtracking: restore the top element after placing the target
    s.push(topElement);
}

void sortStack(stack<int> &s)
{
    // base case: if stack is empty, return
    if (s.empty())
    {
        return;
    }

    // Remove the top element and sort the remaining stack
    int topElement = s.top();
    s.pop();
    sortStack(s);

    // Insert the top element back in its sorted position
    insertSorted(s, topElement);
}

int main()
{
    // Stack initialization
    stack<int> s;
    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);

    // Sort the stack
    sortStack(s);

    // Print the sorted stack (note that it's printed in descending order due to stack behavior)
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
