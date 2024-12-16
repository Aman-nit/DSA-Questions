#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // THIS IS FOR TWO GIVEN ARRAY
    //  int n, m;

    // cout << "Enter number of elemt of arr:-";
    // cin >> n;
    // cout << "Enter number of elemt of brr:-";
    // cin >> m;
    // vector<int> arr(n);
    // vector<int> brr(m);
    // cout << "Element of arr:-" << endl;

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cin >> arr[i];
    // }
    // cout << "Element of brr:-" << endl;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cin >> brr[i];
    // }
    // cout << endl;

    // int sum;
    // cout << "Enter the sum number to find:-";
    // cin >> sum;
    // cout << endl;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     for (int j = 0; j < brr.size(); j++)
    //     {
    //         if (arr[i] + brr[j] == sum)
    //         {
    //             cout << "sum " << sum << "is the pair of" << "(" << arr[i] << "," << brr[j] << ")";
    //             cout << endl;
    //         }
    //     }
    // }

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
            if (arr[i] + arr[j] == sum)
            {
                cout << "sum " << sum << "is the pair of" << "(" << arr[i] << "," << arr[j] << ")";
                cout << endl;
            }
        }
    }

    return 0;
}