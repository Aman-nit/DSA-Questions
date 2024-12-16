#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of elements of array:-";
    cin >> n;
    vector<int> brr(n);
    cout << "Enter erlements of arra:-";
    for (int i = 0; i < brr.size(); i++)
    {
        cin >> brr[i];
    }
    int target;
    cout << "Enter a target element:-";
    cin >> target;
    vector<int> arr(n);
    auto firstOcc = lower_bound(arr.begin(), arr.end(), target);

    // cout << "Target not found!";

    cout << "First ocuurance of target is ";
    cout << firstOcc - arr.begin();
    return 0;
}