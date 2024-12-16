#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void prevSmallerElement(vector<int> &v, stack<int> &s, vector<int> &ans)
{

    s.push(-1);
    for (int i = 0; i < v.size(); i++)
    {
        // Moving left to right in vector
        while (s.top() >= v[i])
        {
            s.pop();
        }
        // chota element mil gaya hai
        ans[i] = s.top();

        // push krdo element ko
        s.push(v[i]);
    }
}

void printVector(vector<int> &vect)
{

    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << " ";
    }
    cout << endl;
}
int main()
{

    stack<int> st;
    vector<int> v;
    v = {2, 1, 4, 3};
    vector<int> ans(v.size());
    cout << "Orignal vector is:-" << endl;
    printVector(v);
    prevSmallerElement(v, st, ans);
    cout << "Previous smaller element vector is:-" << endl;
    printVector(ans);
}