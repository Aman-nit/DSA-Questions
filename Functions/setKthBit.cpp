#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int setKthBit(int &n, int k)
{
    int mask = 1 << k;
    int ans = n | mask;
    return ans;
}

int main()
{
    int n, k;

    cout << "Enter an integer:-";
    cin >> n;
    cout << "Enter the value of k:-";
    cin >> k;

    int finalAns = setKthBit(n, k);
    cout << "Answer is " << finalAns;
    return 0;
}