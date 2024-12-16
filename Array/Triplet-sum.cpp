#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elemt of arr:-";
    cin >> n;

    vector<int> arr(n);

    cout << "Element of arr:-" << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    int sum;
    cout << "Enter the sum number to find:-";
    cin >> sum;
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = i + j + 1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    cout << "sum " << sum << " is the pair of" << "(" << arr[i] << "," << arr[j] << "," << arr[k] << ")";
                    cout << endl;
                }
            }
        }
    }

    return 0;
}