#include <iostream>
#include <vector>
using namespace std;
bool isSortedOrNot(vector<int> &arr, int i)
{
    // Base case
    if (i == arr.size() - 1)
    {
        return true;
    }
    // Processing
    if (arr[i + 1] < arr[i])
    {
        return false;
    }
    // RR
    return isSortedOrNot(arr, i + 1);
}

int main()
{
    int n;
    int i = 0;
    cout << "Enter number of element of an array:-";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements:-";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool issoterd = isSortedOrNot(arr, i);
    if (issoterd)
    {
        cout << "Array is sorted.";
    }
    else
    {
        cout << "Array is not sorted.";
    }

    return 0;
}