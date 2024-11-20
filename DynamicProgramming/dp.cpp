/*
// DYNAMIC PROGRAMMING
// is a programming techicke where we lern not to claculate again and again same subproblem

// Approaches
// 1.Top  Down approacf
// Recursion +memoisation

// 2.Bottom up
// Tabulation method

// 3.Space Optimisation

// WHEN TO APPPLY..?
// 1.Overlapping sub Problem present(same problem ko bar bar solve krna)
// 2.Optimal SUbstructure(Optimal sol of bigger problem can be calculated using optimal solution of smaller problem )
*/

#include <iostream>
#include <vector>
using namespace std;

// TOP DOWN DP / Recursion + Memoisation f
int topDownSolve(int n, vector<int> &dp)
{

    // Base case
    if (n == 1 || n == 0)
    {
        return n;
    }

    // step 02. check if answer already exist
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // step 02. replace ans with dp [n]
    dp[n] = topDownSolve(n - 1, dp) + topDownSolve(n - 2, dp);
    return dp[n];
}

// Bottom Up / Tabulation method
int bottomUpsolve(int n, vector<int> &dp)
{

    dp[0] = 0;
    if (n == 0)
    {
        return dp[0];
    }

    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Space Optimisation
int spaceOptSolve(int n)
{

    int prev2 = 0;
    int prev1 = 1;

    if (n == 0)
    {
        return prev2;
    }
    if (n == 1)
    {
        return prev1;
    }
    int curr;

    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;

        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main()
{
    int n;
    cout << "Enter the value of n :-";
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << "Printing solution of Top Down app...." << endl;
    int ans = topDownSolve(n, dp);
    cout << ans << "\n";
    cout << "Printing solution of Bottom up app...." << endl;
    int ans2 = bottomUpsolve(n, dp);
    cout << ans2 << "\n";
    int ans3 = spaceOptSolve(n);
    cout << "Printing solution of Space OPtimaised s app...." << endl;
    cout << ans3 << "\n";
}