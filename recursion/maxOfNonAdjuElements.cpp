// One array is  given to us we have to find find the max sum of two non adjustian elements
// EX arr = 1,2,4,9
// 1+4=5
// 1+9 =10
// 2+9 =11 this is max sum of non adj element
#include <iostream>
#include <vector>
using namespace std;

void maxOfNonAdjuElements(vector<int> &arr, int sum, int &maxi, int i)
{
    // base case
    if (i >= arr.size() - 1)
    {
        maxi = max(sum, maxi);
        return;
    }
    // include

    maxOfNonAdjuElements(arr, sum + arr[i], maxi, i + 2);
    // exclude
    maxOfNonAdjuElements(arr, sum, maxi, i + 1);
    return;
}

int main()
{
    int n;
    int sum = 0;
    int maxi = INT8_MIN;
    int i = 0;
    cout << "Enter number of elements of arr:-";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of arr:-";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxi << endl;

    return 0;
}