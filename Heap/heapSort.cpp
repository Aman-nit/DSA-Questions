// only root node can be delete in the heap
// PROCESS
// replace last node with rooot node
// place root node node at right place
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int index = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;
    int largest = index;

    if (leftIndex < n && arr[largest] < arr[leftIndex])
    {
        largest = leftIndex;
    }
    if (rightIndex < n && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
    }
    if (index != largest)
    {

        swap(arr[index], arr[largest]);
        index = largest;
        heapify(arr, n, index);
    }
}
void buildHeap(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }
}
void heapSort(int arr[], int n)
{
    cout << "Calling heap SOrt" << endl;
    int index = n;

    while (index != 1)
    {
        swap(arr[1], arr[n--]);

        heapify(arr, n, 1);
    }
}

int main()
{
    int arr[] = {-1, 12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32};
    int n = 11;
    cout << "Printing the Array " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    buildHeap(arr, n);
    cout << "Printing the heap " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    heapSort(arr, n);
    cout << "Printing the Sorted array using Heap.. " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}