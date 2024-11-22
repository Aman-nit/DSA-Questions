#include <iostream>
#include <vector>
using namespace std;

// Recursion
int coinChangeRecursion(vector<int> &coins, int amount)
{
    // Base case
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0)
    {
        return INT16_MAX;
    }

    int mini = INT16_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = coinChangeRecursion(coins, amount - coins[i]);
        if (ans != INT16_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
}

// Memoisation
int coinChangeMemo(vector<int> &coins, int amount, vector<int> &dp)
{
    // Base case
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0)
    {
        return INT16_MAX;
    }
    // Ans already exists
    if (dp[amount] != -1)
    {
        return dp[amount];
    }

    int mini = INT16_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = coinChangeMemo(coins, amount - coins[i], dp);
        if (ans != INT16_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    dp[amount] = mini;
    return dp[amount];
}

// Tabulation method
int coinChangeTabul(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT16_MAX);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            int ans = coinChangeMemo(coins, amount - coins[j], dp);
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT16_MAX)
            {
                int ans = dp[i - coins[j]];
                dp[i] = min(dp[i], 1 + ans);
            }
        }
    }
    return dp[amount];
}

// Space optimisatio
// No space optimisation is possible

int main()
{
    int n, amount;
    cout << "Enter number of coin types:-";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter coins:-";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    cout << "Enter target amount:-";
    cin >> amount;
    vector<int> dp(amount + 1, -1);

    cout << "Answer using Recursion ..." << endl;
    int ans = coinChangeRecursion(coins, amount);
    if (ans == INT16_MAX)
    {
        cout << "Sorry there is no possiblity ..." << endl;
    }
    else
    {
        cout << ans << endl;
    }
    cout << "Answer using Recursion + Memoisation ..." << endl;
    int ans2 = coinChangeMemo(coins, amount, dp);
    if (ans2 == INT16_MAX)
    {
        cout << "Sorry there is no possiblity ..." << endl;
    }
    else
    {
        cout << ans2 << endl;
    }

    cout << "Answer using Tabulation  ..." << endl;
    int ans3 = coinChangeTabul(coins, amount);
    if (ans3 == INT16_MAX)
    {
        cout << "Sorry there is no possiblity ..." << endl;
    }
    else
    {
        cout << ans3 << endl;
    }
    return 0;
}
