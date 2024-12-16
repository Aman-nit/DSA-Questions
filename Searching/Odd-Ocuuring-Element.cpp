#include <iostream>
#include <vector>
using namespace std;

int OddOccarance(vector<int> arr)
{
    int s = 0;
    int e = arr.size();
    int mid = s + (e - s) / 2;
    int ans = 0;
    while (s <= e)
    {
        if (s == e)
        {
            return s;
        }

        if (mid % 2 == 0)
        {
            if (arr[mid] == arr[mid + 1])
            {
                s = mid + 2;
            }
            else
            {
                e = mid;
            }
        }
        else
        {
            if (arr[mid] == arr[mid - 1])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter number of lement of array:-";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = OddOccarance(arr);

    if (ans == -1)
    {
        cout << "All the elements are in pair";
    }
    else
    {
        cout << "Index is " << ans << endl;
        cout << "value is " << arr[ans] << endl;
    }
    return 0;
} 

// Q:-Find the art occurring element in an array
// All the elements occurs even number of times and except one
// all repeating occurs of element appears in pairs and pairs are not adjacent (there cannot be maximum 2 occurrence  element)
//  find the element that appears odd number of times