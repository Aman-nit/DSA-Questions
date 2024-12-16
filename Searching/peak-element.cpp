#include <iostream>
#include <vector> //For using vector
using namespace std;
int findPeakIndex(int arr[], int n, int target)
{
    int start = 0;
    int end = n - 1;

    int mid = start + (end - start) / 2;
    // loop wil end if start>end;
    while (start < end)
    {

        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        // Searching in right side of array
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return end;
}

int main()
{
    int n;
    cout << "Enter number of element of an array:-";
    cin >> n;
    int v;
    // cin >> v;
    // vector<int> vect;
    int arr[n];
    // Taiking array input
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // Taking input target lement
    int target;

        int indexOfPeakElement = findPeakIndex(arr, n, target);

    cout << findPeakIndex;

    return 0;
}