#include <iostream>
#include <deque>
#include <stack>
#include <vector>
using namespace std;

void slidingWindow(vector<int> &v, int &k)
{
    int n = v.size();
    deque<int> q;
    // procss first window of size k;
    for (int i = 0; i < k; i++)
    {
        /* code */
    }
}

int main()
{
    vector<int> v = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    slidingWindow(v, k);
}