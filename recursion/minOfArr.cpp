// Pinting max of an array using recursion
#include <iostream>
#include <vector>
using namespace std;

void printMinOfArr(vector<int> arr, int i, int &min)
{

    // base case
    if (i >= arr.size())
    {
        return;
    }
    if (arr[i] < min)
    {
        min = arr[i];
    }

    // cout << max << " ";
    // RR
    printMinOfArr(arr, i + 1, min);
}

int main()
{
    int n;
    int i = 0;
    int min = INT16_MAX;
    cout << "Enter number of elements of array:-";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of array:-";
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    cout << "Printing min of arr........\n";
    printMinOfArr(arr, i, min);
    cout << min;
    return 0;
}