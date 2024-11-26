#include <iostream>
#include <vector>

using namespace std;

// RECURSION
int solveUsingRecursion(int n, int k)
{

    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return (k + k * (k - 1));
    }
    int ans;
    ans = (solveUsingRecursion(n - 2, k) + solveUsingRecursion(n - 1, k)) * (k - 1);
    return ans;
}

// RERCURSION + MEMOISATION
int solveUsingMemo(int n, int k, vector<int> &dp)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return (k + k * (k - 1));
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (solveUsingMemo(n - 2, k, dp) + solveUsingMemo(n - 1, k, dp)) * (k - 1);
    return dp[n];
}

// TABULATION
int solveUsingTabu(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = (k + k * (k - 1));
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 2] + dp[i - 1]) * (k - 1);
    }
    return dp[n];
}

// SPACE OPTIMISATION
int solveUsingSpacOpt(int n, int k)
{
    int prev2 = k;
    int prev1 = (k + k * (k - 1));

    int curr;
    for (int i = 3; i <= n; i++)
    {
        curr = (prev1 + prev2) * (k - 1);

        // Shifting
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main()
{
    // Recursion
    int n, k;
    cout << "Enter number of fence:-";
    cin >> n;
    cout << "Enter number of color:-";
    cin >> k;
    cout << "Answer using Recursion\n";
    cout << solveUsingRecursion(n, k) << endl;

    // Memo
    vector<int> dp(n + 1, -1);
    cout << "Answer using Recursion + Memoisation\n";
    cout << solveUsingMemo(n, k, dp) << endl;

    // Tabulation
    cout << "Answer using Tabulation\n";
    cout << solveUsingTabu(n, k) << endl;

    // Space optimisation
    cout << "Answer using Space Optimisation\n";
    cout << solveUsingSpacOpt(n, k) << endl;
}