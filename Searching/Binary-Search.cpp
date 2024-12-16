#include <iostream>
#include <vector> //For using vector
using namespace std;
int binarySearch(int arr[], int n, int target)
{
    int start = 0;
    int end = n - 1;
    // integer over flow issue
    // if s and e both are is max integer and adding both can cross limit
    // int mid = (start + end) / 2;
    int mid = start + (end - start) / 2;
    // loop wil end if start>end;
    while (start <= end)
    {
        // here we are finding element in only mid index
        int element = arr[mid];
        if (element == target)
        {
            return mid;
        }
        // Searching in left side of array
        else if (target < element)
        {
            end = mid - 1;
        }
        // Searching in right side of array
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
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
    cout << "Enter a number to find:-";
    cin >> target;
    // calliing binarysearch function
    int indexOfTarget = binarySearch(arr, n, target);

    if (indexOfTarget == -1)
    {
        cout << "Target not found";
    }
    else
    {
        cout << "Target found at the index of :-" << indexOfTarget;
    }

    return 0;
}