// Pinting max of an array using recursion
#include <iostream>
#include <vector>
using namespace std;

void printMaxOfArr(vector<int> arr, int i, int &max)
{

    // base case
    if (i >= arr.size())
    {
        return;
    }
    if (arr[i] > max)
    {
        max = arr[i];
    }

    // cout << max << " ";
    // RR
    printMaxOfArr(arr, i + 1, max);
}

int main()
{
    int n;
    int i = 0;
    int max = INT16_MIN;
    cout << "Enter number of elements of array:-";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of array:-";
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    cout << "Printing max of arr........\n";
    printMaxOfArr(arr, i, max);
    cout << max;
    return 0;
}