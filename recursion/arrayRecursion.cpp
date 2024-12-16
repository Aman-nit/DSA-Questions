// Pinting array using recursion
#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> arr, int i)
{

    // base case
    if (i >= arr.size())
    {
        return;
    }
    cout << arr[i] << " ";
    // RR
    printArr(arr, i + 1);
}

int main()
{
    int n;
    int i = 0;
    cout << "Enter number of elements of array:-";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of array:-";
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    cout << "Printing arr........\n";
    printArr(arr, i);
    return 0;
}