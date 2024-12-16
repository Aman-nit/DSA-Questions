#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int IndexoLastOccur(vector<int> brr, int target)
{
    int s = 0;
    int e = brr.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (brr[mid] == target)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (brr[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

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
    int index = IndexoLastOccur(brr, target);
    if (index == -1)
    {
        cout << "Target not found!";
    }
    else
    {
        cout << "First ocuurance of " << target << " is " << index;
    }

    return 0;
}
