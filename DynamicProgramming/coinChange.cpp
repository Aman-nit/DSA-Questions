#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int> &coins, int amount)
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
        int ans = coinChange(coins, amount - coins[i]);
        if (ans != INT16_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
}

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
    int ans = coinChange(coins, amount);
    if (ans == INT16_MAX)
    {
        cout << "Sorry there is no possiblity ...";
    }
    else
    {
        cout << ans;
    }

    return 0;
}
