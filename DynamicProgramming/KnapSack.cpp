#include <iostream>
#include <vector>
using namespace std;

// RECURSION
int solveUsingRecursion(int weight[], int value[], int capacity, int index)
{
    if (index == 0)
    {
        if (weight[index] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    // Include And Exclude
    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveUsingRecursion(weight, value, capacity - weight[index], index - 1);
    }
    int exclude = 0 + solveUsingRecursion(weight, value, capacity, index - 1);

    int ans = max(include, exclude);

    return ans;
}

// RECURSTION +MEMOISATION
int solveUsingMemo(int weight[], int value[], int capacity, int index, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[index] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    // Include And Exclude
    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveUsingRecursion(weight, value, capacity - weight[index], index - 1);
    }
    int exclude = 0 + solveUsingRecursion(weight, value, capacity, index - 1);

    dp[index][capacity] = max(include, exclude);

    return dp[index][capacity];
}

// TABULATION
int solveUsingTabu(int weight[], int value[], int capacity, int index)
{
}

int main()
{

    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;

    // RECURSTION
    cout << "Answer using Recursion...\n";
    cout << solveUsingRecursion(weight, value, capacity, n - 1) << endl;

    // RECURSTION + MEMOISATION
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
    cout << "Answer using Memoisation...\n";
    cout << solveUsingMemo(weight, value, capacity, n - 1, dp) << endl;
}