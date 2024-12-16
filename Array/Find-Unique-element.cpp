#include <iostream>
#include <vector>
using namespace std;

int uniqueElement(vector<int> arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of array:-";
    cin >> n;
    vector<int> arr{n};
    cout << "Enter the elements:-";
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    int uniq = uniqueElement(arr);
    cout << "Unique element is " << uniq;
    return 0;
}