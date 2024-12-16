#include <iostream>
using namespace std;

int solve(int dividend, int divisor)
{
    int s = 0;
    int e = abs(dividend);
    int mid;
    int ans = 0;

    while (s <= e)
    {
        mid = s + (e - s) / 2;

        if (abs(mid * divisor) == abs(dividend))
        {
            ans = mid;
            break;
        }
        else if (abs(mid * divisor) < abs(dividend))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    if ((divisor > 0 && dividend > 0) || (divisor < 0 && dividend < 0))
    {
        return ans;
    }
    else
    {
        return -ans;
    }
}

int main()
{
    int divisor;
    int dividend;

    cout << "Enter dividend: ";
    cin >> dividend;
    cout << "Enter divisor: ";
    cin >> divisor;

    int ans = solve(dividend, divisor);
    cout << "The quotient is: " << ans << endl;

    return 0;
}
