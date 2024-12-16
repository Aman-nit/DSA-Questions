#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> &arr, int &s, int &end, int &key)
{
    // Base casae
    if (s > end)
    {
        return -1;
    }
    int mid = (s + end) / 2;
    // case solev 1
    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[mid] < key)
    {
        s = mid + 1;
        return binarySearch(arr, s, end, key);
    }
    if (arr[mid] > key)
    {
        end = mid - 1;
        return binarySearch(arr, s, end, key);
    }
}

int main()
{
    int n;

    cout << "Enter number of element of an array:-";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements:-";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int s = 0;
    int end = arr.size();

    int key;
    cout << "Enter a key to find:-";
    cin >> key;
    int ans = binarySearch(arr, s, end, key);
    cout << key << " Found at index :-" << ans;

    return 0;
}