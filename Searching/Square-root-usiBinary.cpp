#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findSqr(int n)
{
    int s = 0;
    int e = n;
    int mid = s + (e - s) / 2;
    int target = n;
    int ans = -1;
    while (s <= e)
    {
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Square root of :-";
    cin >> n;
    int ans = findSqr(n);
    int precision;
    cout << "Enter the number of floating digits in precisions:-";
    cin >> precision;
    double step = 0.1;
    double finalAns = ans;
    for (int i = 0; i < precision; i++)
    {
        for (double j = ans; j * j <= n; j = j + step)
        {
            finalAns = j;
        }
        step = step / 10;
    }

    cout << "Square root of " << n << " is " << finalAns << endl;
    //  main();
    return 0;
}