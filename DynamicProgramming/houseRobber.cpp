#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Recursion
int houseRobberRec(vector<int> &nums, int n)
{
    // base case
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return nums[0];
    }
    // Include
    int include = houseRobberRec(nums, n - 2) + nums[n];
    // Exclude
    int exclude = houseRobberRec(nums, n - 1) + 0;

    return max(include, exclude);
}

// Recursion + Memoisation
int houseRObberMemo(vector<int> &nums, int n, vector<int> &dp)
{
    // base case
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return nums[0];
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // Include
    int include = houseRobberRec(nums, n - 2) + nums[n];
    // Exclude
    int exclude = houseRobberRec(nums, n - 1) + 0;

    dp[n] = max(include, exclude);

    return dp[n];
}

// Tabulation
int houseRobberTabu(vector<int> &nums, int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = nums[0];

    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        if (i - 2 >= 0)
        {
            temp = dp[i - 2];
        }

        // Include
        int include = temp + nums[i];
        // Exclude
        int exclude = dp[i - 1] + 0;

        dp[i] = max(include, exclude);
    }
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter the number of houses:-";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the amount present in all houese:-" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> dp(n + 1, -1);
    cout << houseRobberRec(nums, n) << endl;
    cout << houseRObberMemo(nums, n, dp) << endl;
    cout << houseRobberTabu(nums, n) << endl;

    return 0;
}