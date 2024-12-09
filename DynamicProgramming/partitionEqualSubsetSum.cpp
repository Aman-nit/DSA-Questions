#include <iostream>
#include <vector>

using namespace std;

// RECURSTION
bool solveUsingRecursion(int index, vector<int> &nums, int target)
{
    // base
    if (index >= nums.size())
    {
        return false;
    }
    if (target < 0)
    {
        return false;
    }
    if (target == 0)
    {
        return true;
    }

    bool include = solveUsingRecursion(index + 1, nums, target - nums[index]);
    bool exclde = solveUsingRecursion(index + 1, nums, target);
    return (include || exclde);
}

// RECURSTION + MEMOISATION
bool solveUsingMemo(int index, vector<int> nums, int target, vector<vector<int>> &dp)
{
    if (index >= nums.size())
    {
        return false;
    }
    if (target < 0)
    {
        return false;
    }
    if (target == 0)
    {
        return true;
    }
    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }

    bool include = solveUsingMemo(index + 1, nums, target - nums[index], dp);
    bool exclude = solveUsingMemo(index + 1, nums, target, dp);
    dp[index][target] = (include || exclude);
    return dp[index][target];
}

// Tbulation
bool solveUsingTabu(int index, vector<int> &nums, int target)
{
    vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));
    for (int i = 0; i < nums.size(); i++)
    {
        dp[i][0] = 1;
    }
    for (int index = nums.size() - 1; index >= 0; index--)
    {
        for (int tar = 1; tar <= target; tar++)
        {
            if (tar - nums[index] >= 0)
            {
                bool include = dp[index + 1][tar - nums[index]];
                bool exclude = dp[index + 1][tar];
                dp[index][tar] = (include || exclude);
            }
        }
    }
    return dp[index][target];
}
int main()
{
    vector<int> nums = {1, 5, 11, 5};
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    int target = sum / 2;
    int index = 0;
    if (target & 1)
    {
        return false;
    }

    // Recurstion
    bool ans = solveUsingRecursion(index, nums, target);
    if (ans)
    {
        cout << "True...\n";
    }
    else
    {
        cout << "False..\n";
    }

    // Recurstion + Memoisation
    vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
    bool ans = solveUsingMemo(index, nums, target, dp);
    if (ans)
    {
        cout << "True...\n";
    }
    else
    {
        cout << "False..\n";
    }

    return 0;
}