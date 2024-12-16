#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n;
    cout << " Enter a number of total element you want to insert :-";
    cin >> n;
    cout << "Please enter only 0 & 1:-";
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    //
    int start = 0;
    int i = 0;
    int end = arr.size() - 1;
    while (i != end)
    {
        if (arr[i] == 0)
        {
            swap(arr[start], arr[i]);
            start++;
            i++;
        }
        else if (arr[i] == 1)
        {
            swap(arr[end], arr[i]);
            end--;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}