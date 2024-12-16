// A man climb stairs ,number of stairs is n and a man can clim one stairs or 2 stairs at a time then find how many ways are possible to clim the stairs

#include <iostream>
using namespace std;

int climbstairs(int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int ans = climbstairs(n - 1) + climbstairs(n - 2);
    return ans;
}

int main()
{
    int n;
    cout << "Enter number of stairs:-";
    cin >> n;
    int ans = climbstairs(n);
    cout << "Number of ways to climb stairs is " << ans;
    return 0;
}