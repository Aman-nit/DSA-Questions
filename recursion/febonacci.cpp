#include <iostream>

using namespace std;
int fabonacci(int n)
{
    // base case
    if (n == 1)
    {
        // for first term /0th term
        return 0;
    }
    else if (n == 2)
    {
        // for second term /1th term
        return 1;
    }

    // RR
    int ans = fabonacci(n - 1) + fabonacci(n - 2);

    return ans;
}

int main()
{
    int n;
    cout << "Enter the term you want to see in febonaci series:-";
    cin >> n;

    cout << fabonacci(n);
}
