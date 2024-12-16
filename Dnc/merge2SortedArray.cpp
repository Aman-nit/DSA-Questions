#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int &s, int &e)
{
    int mid = (s + e) / 2;
    int length1 = mid - s + 1;
    int length2 = e - mid;

    // Asume to create array for len1 and len 2
    int *left = new int[length1];
    int *right = new int[length2];

    // copy values
    int k = s;
    for (int i = 0; i < length1; i++)
    {
        left[i] = arr[k];
        k++;
    }
    k = mid + 1;
    for (int i = 0; i < length2; i++)
    {
        right[i] = arr[k];
    }

    // merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;
    while (leftIndex < length1 && rightIndex < length2)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else
        {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    } // copy logic for left array
    while (leftIndex < length1)
    {
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }
    // copy logic for right array
    while (leftIndex < length1)
    {
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        leftIndex++;
    }
    // TODO:- delete left and right wala newly array
}

void mergeSort(vector<int> &arr, int &s, int &e)
{
    // Base case
    // s == e->single elemnet
    // s>e ->invalid array
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    // left part sort by recursion
    mergeSort(arr, s, mid);

    // right part sort by recursion
    int newMid = mid + 1;
    mergeSort(arr, newMid, e);

    // Now merge 2 sorted array
    merge(arr, s, e);
}

int main()
{
    int n;
    cout << "Enter number of lemenets:-";
    cin >> n;
    vector<int> arr(n);
    // Taking input array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int s = 0;
    int e = n - 1;

    mergeSort(arr, s, e);

    // printing arr;-
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}