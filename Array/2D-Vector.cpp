#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // int n;
    // vector<vector<int>> arr;

    // vector<int> a{1, 2, 3};
    // vector<int> b{3, 4, 5};
    // vector<int> c{6, 7, 8};
    // arr.push_back(a);
    // arr.push_back(b);
    // arr.push_back(c);

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     for (int j = 0; j < arr[i].size(); j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // NOTHER WAY OF INITIALIZTION
    vector<vector<int>> arr(5, vector<int>(5, -8));
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}