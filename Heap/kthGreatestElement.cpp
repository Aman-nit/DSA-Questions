#include <iostream>
#include <queue>
using namespace std;

int kthGreatestElement(int arr[], int n, int k)
{
    // creat max heap
    priority_queue<int, vector<int>, greater<int>> pq;
    // for first k element of array
    for (int i = 0; i < k; i++)
    {
        int element = arr[i];
        pq.push(element);
    }
    // for remaining elements, push only if theye are less than top element
    for (int j = k; j < n; j++)
    {
        if (arr[j] > pq.top())
        {
            pq.pop();
            pq.push(arr[j]);
        }
    }
    int ans = pq.top();
    return ans;
}

int main()
{
    int n;
    int k;
    cout << "Enter number of elements of array:-";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    cout << "Enter the value of k:-";
    cin >> k;
    int ans = kthGreatestElement(arr, n, k);
    cout << k << "th Greatest element is :- ";
    cout << ans << " ";

    return 0;
}