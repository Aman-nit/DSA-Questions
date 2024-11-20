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

// TOP DOWN DP
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

int main()
{
    int n;
    cout << "Enter the value of n :-";
    cin >> n;
    vector<int> dp(n + 1, -1);

    int ans = topDownSolve(n, dp);
    cout << ans << " ";
}