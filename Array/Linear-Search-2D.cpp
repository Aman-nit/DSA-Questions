#include <iostream>
#include <vector>
using namespace std;
int FindKeyLS(int arr[][3], int row, int col, int key)
{
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == key)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int arr[3][3];
    int row = 3;
    int col = 3;
    int key;
    cout << "Enter the values of 3*3 matrix:-" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Enter a key to find:-";
    cin >> key;
    int ans = FindKeyLS(arr, row, col, key);
    if (ans == 0)
    {
        cout << "Not found";
    }
    else
    {
        cout << "Element found ";
    }

    return 0;
}