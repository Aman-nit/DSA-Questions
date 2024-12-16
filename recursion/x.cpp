// An array of integer given to you  and a target sum we have to find minimum number of elements required to reach target sum
// EX int arr[3] ={1,2,3},target = 5, target can be reached
// {1,1,1,1,1}
//{1,1,1,2}
//{1,1,3}
//{1,2,2}
//{2,3} => this set of integer have least element , so this will be the final answer
#include <iostream>
#include <vector>
using namespace std;
int findLeastIntegerSum(vector<int> &arr, int target)
{
    // Base case
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT16_MAX;
    }
    // SOLVE ONE CASE
    int mini = INT32_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = findLeastIntegerSum(arr, target - arr[i]);
        if (ans != INT16_MAX)
        {
            mini = (mini, ans + 1);
        }
    }
    return mini;
}

int main()
{
    int n;
    int target;
    cout << "Enter number of lements of array:-";
    cin >> n;
    cout << "Please enter array elements :-";
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter a target integer:-";
    cin >> target;
    int ans = findLeastIntegerSum(arr, target);
    cout << "Answer is: " << ans << endl;
    return 0;
}