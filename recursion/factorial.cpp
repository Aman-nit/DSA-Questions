#include <iostream>

using namespace std;
int factorial(int n)
{
    // base case
    if (n == 1)
    {
        return 1;
    }
    int ans;
    // function factorial is calling itself
    int chotiProblemAns = factorial(n - 1);
    int badiProblemAns = n * chotiProblemAns;

    return badiProblemAns;
}

int main()
{
    int n;
    cout << "Enter a number:-";
    cin >> n;
    int ans = factorial(n);
    cout << "factorial of " << n << " is " << ans;
}
