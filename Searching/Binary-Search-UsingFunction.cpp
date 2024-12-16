#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of array element:-";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements:-";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Enter target element:-";
    cin >> target;
    if (binary_search(arr.begin(), arr.end(), target))
    {
        cout << "Target found:-";
    }
    else
    {
        cout << "Target not found:-";
    }

    return 0;
}