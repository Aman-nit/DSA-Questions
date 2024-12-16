#include <iostream>
#include <vector>
using namespace std;

int partitionLogic(int arr[], int s, int e)
{
    // chose pivot element
    int pivotIndex = s;
    int pivotElement = arr[s];

    // fiind right position for pivot element and place it there

    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        count++;
    }
    // job main loop se bahar hua , tohmere pass pivot kiright position ka index ready h
    int rightIndex = s + count;
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex = rightIndex;

    // left me chota and right me bada element

    int i = s;
    int j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivotElement)
        {
            i++;
        }
        while (arr[i] > pivotElement)
        {
            j--;
        }
        // 2 case possible
        // A- you found the element to swap

        // B- no need to swap
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // BASE casae
    if (s >= e)
    {
        return;
    }
    // partition logic
    int p = partitionLogic(arr, s, e);

    // recursive call
    // left
    quickSort(arr, s, p - 1);

    // right
    quickSort(arr, p + 1, e);
}

int main()
{
    int n;
    int s = 0;
    int e = n - 1;
    cout << "Enter number of elements:- ";
    cin >> n;
    cout << "Enter array elements:-";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, s, e);
    cout << "Printing sorted array.....";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}